#include "Exchange/Exchange.h"
#include "Order/Order.h"
#include "Utils/Utils.h"
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
        Order::Order buyOrder1("AAPL", Order::OrderType::LIMIT_BUY, 150.0, 10);
        Order::Order sellOrder1("AAPL", Order::OrderType::LIMIT_SELL, 150.0, 5);
        Order::Order marketBuyOrder("AAPL", Order::OrderType::MARKET_BUY, 0.0, 15);

        exchange.placeOrder(buyOrder1);
        exchange.placeOrder(sellOrder1);
        exchange.placeOrder(marketBuyOrder);
        
        // Cancel order
        exchange.cancelOrder(buyOrder1.id);
        
    } catch (const std::exception& e) {
        Utils::Logger::getInstance().log("Order creation error: " + std::string(e.what()));
        return 1;
    }

    std::this_thread::sleep_for(std::chrono::seconds(5));

    // Query order book and trade history
    exchange.getOrderBook("AAPL");
    exchange.getTradeHistory("AAPL");

    // Stop exchange processing
    exchange.stop();

    return 0;
}