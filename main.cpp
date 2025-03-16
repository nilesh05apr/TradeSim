#include "Exchange/Exchange.h"
#include "Order/Order.h"
#include "Utils/Utils.h"
#include "OrderBook/OrderBook.h"
#include <thread>
#include <memory>

int main() {
    Exchange::Exchange exchange;

    // List stock
    try {
        exchange.listStock("AAPL", "Apple Inc.", 150.0, 1000000);
    } catch (const std::exception& e) {
        Utils::Logger::getInstance().log("Stock listing error: " + std::string(e.what()));
        return 1;
    }

    // Start exchange processing
    exchange.start();

    // Create orders
    try {
        // Limit orders

        Order::Order buyOrder("AAPL", Order::OrderType::LIMIT_BUY, 150.0, 10);
        Order::Order sellOrder("AAPL", Order::OrderType::LIMIT_SELL, 150.0, 5);

        // Market orders
        Order::Order marketBuyOrder("AAPL", Order::OrderType::MARKET_BUY, 0.0, 15);
        Order::Order marketSellOrder("AAPL", Order::OrderType::MARKET_SELL, 0.0, 10);

        // Place orders
        exchange.placeOrder(buyOrder);
        exchange.placeOrder(sellOrder);
        exchange.placeOrder(marketBuyOrder);
        exchange.placeOrder(marketSellOrder);

        // Cancel order
        buyOrder.type = Order::OrderType::CANCEL;
        exchange.placeOrder(buyOrder);
        
    } catch (const std::exception& e) {
        Utils::Logger::getInstance().log("Order creation error: " + std::string(e.what()));
        return 1;
    }

    // Query order book and trade history
    try {
        exchange.getOrderBook("AAPL");
        exchange.getTradeHistory("AAPL");
    } catch (const std::exception& e) {
        Utils::Logger::getInstance().log("Error fetching order book or trade history: " + std::string(e.what()));
        return 1;
    }

    // Stop exchange processing (stops all stock process threads)
    exchange.stop();

    return 0;
}