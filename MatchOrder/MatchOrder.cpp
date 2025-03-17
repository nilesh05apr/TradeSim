#include "MatchOrder.h"
#include "../Order/Order.h"
#include "../Utils/Utils.h"

namespace MatchOrder {
    Utils::Logger& logger = Utils::Logger::getInstance();

    int MatchOrder::matchOrders(
        std::vector<Order::Order>& buyOrders, 
        std::vector<Order::Order>& sellOrders, 
        std::vector<Order::Order>& tradeHistory
    ) {
        logger.info("Matching orders...");

        // Sort the buy orders in descending order of price, and by timestamp for FIFO
        std::sort(buyOrders.begin(), buyOrders.end(), [](const Order::Order& a, const Order::Order& b) {
            if (a.price == b.price) {
                return a.timestamp < b.timestamp;
            }
            return a.price > b.price;
        });

        // Sort the sell orders in ascending order of price, and by timestamp for FIFO
        std::sort(sellOrders.begin(), sellOrders.end(), [](const Order::Order& a, const Order::Order& b) {
            if (a.price == b.price) {
                return a.timestamp < b.timestamp;
            }
            return a.price < b.price;
        });

        auto buyIt = buyOrders.begin();
        auto sellIt = sellOrders.begin();

        int matched = 0;
        while (buyIt != buyOrders.end() && sellIt != sellOrders.end()) {
            // Handle market orders
            logger.info("Evaluating orders for matching...");
            logger.info(
                "Buy Order: ID " 
                + boost::uuids::to_string(buyIt->id) 
                + ", Price: " + std::to_string(buyIt->price) 
                + ", Quantity: " + std::to_string(buyIt->quantity)
            );
            logger.info(
                "Sell Order: ID " 
                + boost::uuids::to_string(sellIt->id) 
                + ", Price: " + std::to_string(sellIt->price) 
                + ", Quantity: " + std::to_string(sellIt->quantity)
            );


            // Handle market orders
            if (buyIt->type == OrderType::MARKET_BUY || sellIt->type == OrderType::MARKET_SELL) {
                
                double tradePrice = (buyIt->type == OrderType::MARKET_BUY) ? sellIt->price : buyIt->price;
                int tradeQuantity = std::min(buyIt->quantity, sellIt->quantity);
                
                logger.info(
                    "Market trade executed: " 
                    + std::to_string(tradeQuantity) 
                    + " @ " + std::to_string(tradePrice)
                );

                // Log matched trade to trade history
                Order::Order matchedOrder = *buyIt;
                matchedOrder.quantity = tradeQuantity;
                matchedOrder.price = tradePrice;
                tradeHistory.emplace_back(matchedOrder);

                buyIt->quantity -= tradeQuantity;
                sellIt->quantity -= tradeQuantity;

                if (buyIt->quantity == 0) {
                    buyIt = buyOrders.erase(buyIt);
                } else {
                    ++buyIt;
                }

                if (sellIt->quantity == 0) {
                    sellIt = sellOrders.erase(sellIt);
                } else {
                    ++sellIt;
                }
                matched = 1;
            }
            // Handle limit orders
            else if (buyIt->price >= sellIt->price) {
                double tradePrice = sellIt->price;            
                int tradeQuantity = std::min(buyIt->quantity, sellIt->quantity);
                logger.info(
                    "Limit trade executed: " 
                    + std::to_string(tradeQuantity) 
                    + " @ " + std::to_string(sellIt->price)
                );

                // Log matched trade to trade history
                Order::Order matchedOrder = *buyIt;
                matchedOrder.quantity = tradeQuantity;
                matchedOrder.price = tradePrice;
                tradeHistory.emplace_back(matchedOrder);

                buyIt->quantity -= tradeQuantity;
                sellIt->quantity -= tradeQuantity;

                if (buyIt->quantity == 0) {
                    buyIt = buyOrders.erase(buyIt);
                } else {
                    ++buyIt;
                }

                if (sellIt->quantity == 0) {
                    sellIt = sellOrders.erase(sellIt);
                } else {
                    ++sellIt;
                }
                matched = 1;
            } else {
                ++buyIt;
            }
        }

        logger.info("Order matching completed.");
        return matched;
    }

}