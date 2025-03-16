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
// std::shared_ptr<OrderBook::OrderBook> Stock::getOrderBook() const { return orderBooks_; }
// OrderBook::OrderBook Stock::getOrderBook() const { return orderBooks_; }

void Stock::addOrder(const Order::Order& order) {
    // if (orderBooks_.find(order.id) == orderBooks_.end()) {
    //     orderBooks_[order.id] = std::make_unique<OrderBook::OrderBook>();
    // }
    // orderBooks_[order.id]->addOrder(order);
    orderBooks_.addOrder(order);
    Utils::Logger::getInstance().log("Order added: " + boost::uuids::to_string(order.id) + 
                                     " Type: " + Utils::toString(order.type) +
                                     " Price: " + std::to_string(order.price) + 
                                     " Quantity: " + std::to_string(order.quantity));
}

void Stock::cancelOrder(const boost::uuids::uuid& orderId) {
    orderBooks_.cancelOrder(orderId);
    // orderBooks_.erase(orderId);
}

void Stock::printOrderBook() const {
    // for (const auto& [id, book] : orderBooks_) {
    //     book->print();
    // }
    orderBooks_.print();
}

void Stock::printTradeHistory() const {
    // for (const auto& [id, book] : orderBooks_) {
    //     book->printHistory();
    // }
    orderBooks_.printHistory();
}

void Stock::startProcessing() {
    Utils::Logger::getInstance().log("Stock processing started.");
    // for (auto& [id, book] : orderBooks_) {
    //     book->startProcessing();
    //     Utils::Logger::getInstance().log("OrderBook processing started for order: " + boost::uuids::to_string(id));
    // }

    orderBooks_.startProcessing();
}

void Stock::stopProcessing() {
    // for (auto& [id, book] : orderBooks_) {
    //     book->stopProcessing();
    // }
    orderBooks_.stopProcessing();
}

}