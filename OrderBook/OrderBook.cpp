#include "OrderBook.h"
#include "../MatchOrder/MatchOrder.h"
#include "../Utils/Utils.h"
#include "../Order/Order.h"
// #include <mutex>


namespace OrderBook {

OrderBook::OrderBook() : stopProcessing_(false) {}

void OrderBook::addOrder(const Order::Order& order) {
    Utils::Logger::getInstance().log("Adding order to OrderBook");
    std::string logMessage = "Order id\t" 
                            + boost::uuids::to_string(order.id) 
                            + " symbol\t" + order.symbol 
                            + " type\t" + std::to_string(static_cast<int>(order.type)) 
                            + " price\t" + std::to_string(order.price) 
                            + " quantity\t" + std::to_string(order.quantity);
    Utils::Logger::getInstance().log(logMessage);
    orders_.push(order);
    orderMap_[order.id] = order;

}

void OrderBook::startProcessing() {
    Utils::Logger::getInstance().log("OrderBook processing thread starting...");
    processOrders();
}

void OrderBook::stopProcessing() {
    stopProcessing_ = true;
    Utils::Logger::getInstance().log("OrderBook processing thread stopped.");
}

void OrderBook::cancelOrder(const boost::uuids::uuid& orderId) {
    if (orderMap_.find(orderId) != orderMap_.end()) {
        orderMap_.erase(orderId);
    }
}

void OrderBook::print() const {
    for (const auto& orderPair : orderMap_) {
        const auto& order = orderPair.second;
        Utils::Logger::getInstance().log(
            "Order ID: " + boost::uuids::to_string(order.id) + 
            " Symbol: " + order.symbol + 
            " Quantity: " + std::to_string(order.quantity) + 
            " Price: " + std::to_string(order.price));
    }
}

void OrderBook::printHistory() const {
    for (const auto& trade : tradeHistory_) {
         Utils::Logger::getInstance().log(
            "Trade executed: Order ID " + boost::uuids::to_string(trade.id) + 
            ", Quantity: " + std::to_string(trade.quantity) + 
            ", Price: " + std::to_string(trade.price));
    }
}

void OrderBook::processOrders() {
    Utils::Logger::getInstance().log("OrderBook::processOrders started.");
    std::vector<Order::Order> buyOrders;
    std::vector<Order::Order> sellOrders;
    Utils::Logger::getInstance().log("Processing orders, order queue size: " + std::to_string(orders_.size()));

    while (!stopProcessing_ || !orders_.empty()) {
        if (orders_.empty()) {
            Utils::Logger::getInstance().log("No orders to process.");
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            return;
        }
        Order::Order order = orders_.top();
        orders_.pop();
        if (order.type == Order::OrderType::CANCEL) {
            orderMap_.erase(order.id);
            continue;
        }

        if (order.type == Order::OrderType::MARKET_BUY || order.type == Order::OrderType::LIMIT_BUY) {
            buyOrders.push_back(order);
        } else {
            sellOrders.push_back(order);
        }

        Utils::Logger::getInstance().log(
            "Order ready to process: ID " 
            + boost::uuids::to_string(order.id) 
            + " Type: " + std::to_string(static_cast<int>(order.type))
        );
    }

    // Match orders
    int matched = 0;
    try {
        Utils::Logger::getInstance().log("Matching orders...");
        matched = MatchOrder::MatchOrder::matchOrders(buyOrders, sellOrders, tradeHistory_);
    } catch (const std::exception &e) {
        Utils::Logger::getInstance().log("Order matching error: " + std::string(e.what()));
    }

    if (matched) {
        Utils::Logger::getInstance().log("Orders successfully matched.");
    } else {
        Utils::Logger::getInstance().log("No orders matched.");
    }

    // Cleanup fully matched orders
    buyOrders.erase(std::remove_if(buyOrders.begin(), buyOrders.end(), [](const Order::Order& o) { return o.quantity == 0; }), buyOrders.end());
    sellOrders.erase(std::remove_if(sellOrders.begin(), sellOrders.end(), [](const Order::Order& o) { return o.quantity == 0; }), sellOrders.end());

    Utils::Logger::getInstance().log("OrderBook::processOrders ending");
    }
}

