#include "Stock.h"
#include <boost/uuid/uuid_generators.hpp>
#include "../Utils/Utils.h"

namespace Stock {

Stock::Stock(const std::string& symbol, const std::string& name, double listedPrice, int totalShares)
    : id_(boost::uuids::random_generator()()), 
    symbol_(symbol), 
    name_(name), 
    listedPrice_(listedPrice), 
    totalShares_(totalShares), 
    availableShares_(totalShares), 
    currentMarketPrice_(listedPrice), 
    listedDate_(std::chrono::system_clock::now()) {}

const boost::uuids::uuid& Stock::getId() const { return id_; }
const std::string& Stock::getSymbol() const { return symbol_; }
const std::string& Stock::getName() const { return name_; }
double Stock::getCurrentMarketPrice() const { return currentMarketPrice_; }
int Stock::getAvailableShares() const { return availableShares_; }

void Stock::addOrder(const Order::Order& order) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (orderBooks_.find(order.id) == orderBooks_.end()) {
        orderBooks_[order.id] = std::make_unique<OrderBook::OrderBook>();
    }
    orderBooks_[order.id]->addOrder(order);
    Utils::Logger::getInstance().log("Order added: " + boost::uuids::to_string(order.id) + 
                                     " Type: " + Utils::toString(order.type) +
                                     " Price: " + std::to_string(order.price) + 
                                     " Quantity: " + std::to_string(order.quantity));
}

void Stock::cancelOrder(const boost::uuids::uuid& orderId) {
    std::lock_guard<std::mutex> lock(mutex_);
    orderBooks_.erase(orderId);
}

void Stock::printOrderBook() const {
    std::lock_guard<std::mutex> lock(mutex_);
    for (const auto& [id, book] : orderBooks_) {
        book->print();
    }
}

void Stock::printTradeHistory() const {
    std::lock_guard<std::mutex> lock(mutex_);
    for (const auto& [id, book] : orderBooks_) {
        book->printHistory();
    }
}

void Stock::startProcessing() {
    Utils::Logger::getInstance().log("Stock processing started.");
    for (auto& [id, book] : orderBooks_) {
        book->startProcessing();
        Utils::Logger::getInstance().log("OrderBook processing started for order: " + boost::uuids::to_string(id));
    }
}

void Stock::stopProcessing() {
    for (auto& [id, book] : orderBooks_) {
        book->stopProcessing();
    }
}

}