#include "Exchange.h"
#include "../Utils/Utils.h"

namespace Exchange {

void Exchange::start() {
    for (auto& [symbol, stock] : stocks_) {
        Utils::Logger::getInstance().log("Starting stock: " + symbol);
        stock->startProcessing();
    }
    Utils::Logger::getInstance().log("Exchange started.");
}

void Exchange::stop() {
    for (auto& [symbol, stock] : stocks_) {
        stock->stopProcessing();
    }
    Utils::Logger::getInstance().log("Exchange stopped.");
}

void Exchange::listStock(const std::string& symbol, const std::string& name, double listedPrice, int totalShares) {
    if (stocks_.find(symbol) != stocks_.end()) {
        throw std::invalid_argument("Stock already listed.");
    }
    stocks_[symbol] = std::make_shared<Stock::Stock>(symbol, name, listedPrice, totalShares);
}

std::shared_ptr<Stock::Stock>& Exchange::getStock(const std::string& symbol) {
    if (stocks_.find(symbol) == stocks_.end()) {
        throw std::invalid_argument("Stock not found.");
    }
    return stocks_[symbol];
}

void Exchange::placeOrder(const Order::Order& order) {
    try {
        auto& stock = getStock(order.symbol);
        stock->addOrder(order);
        
        Utils::Logger::getInstance().log("Order placed: " + boost::uuids::to_string(order.id) + 
                                         " Type: " + Utils::toString(order.type) +
                                         " Price: " + std::to_string(order.price) + 
                                         " Quantity: " + std::to_string(order.quantity));
    } catch (const std::exception& e) {
        Utils::Logger::getInstance().log("Failed to place order: " + std::string(e.what()));
    }
}

void Exchange::cancelOrder(const boost::uuids::uuid& orderId) {
    for (auto& [symbol, stock] : stocks_) {
        stock->cancelOrder(orderId);
    }
}

void Exchange::getOrderBook(const std::string& symbol) const {
    try {
        auto& stock = stocks_.at(symbol);
        stock->printOrderBook();
    } catch (const std::exception& e) {
        Utils::Logger::getInstance().log("Failed to get order book: " + std::string(e.what()));
    }
}

void Exchange::getTradeHistory(const std::string& symbol) const {
    try {
        auto& stock = stocks_.at(symbol);
        stock->printTradeHistory();
    } catch (const std::exception& e) {
        Utils::Logger::getInstance().log("Failed to get trade history: " + std::string(e.what()));
    }
}

}