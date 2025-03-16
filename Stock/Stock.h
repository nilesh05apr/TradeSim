#ifndef STOCK_H
#define STOCK_H

#include <string>
#include <vector>
#include <chrono>
#include <unordered_map>
#include <mutex>
#include <memory>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "../OrderBook/OrderBook.h"

namespace Stock {

class Stock {
public:
    Stock(const std::string& symbol, const std::string& name, double listedPrice, int totalShares);

    // Accessors
    const boost::uuids::uuid& getId() const;
    const std::string& getSymbol() const;
    const std::string& getName() const;
    double getCurrentMarketPrice() const;
    int getAvailableShares() const;

    //    OrderBook::OrderBook getOrderBook() const;
    // std::shared_ptr<OrderBook::OrderBook> getOrderBook() const;

    // Order handling
    void addOrder(const Order::Order& order);
    void cancelOrder(const boost::uuids::uuid& orderId);

    // OrderBook queries
    void printOrderBook() const;
    void printTradeHistory() const;

    // Processing
    void startProcessing();
    void stopProcessing();

    OrderBook::OrderBook orderBooks_;
    // std::shared_ptr<OrderBook::OrderBook> orderBooks_;
    // std::unordered_map<boost::uuids::uuid, std::shared_ptr<OrderBook::OrderBook>, boost::hash<boost::uuids::uuid>> orderBooks_;

private:
    boost::uuids::uuid id_;
    std::string symbol_;
    std::string name_;
    double listedPrice_;
    int totalShares_;
    int availableShares_;
    double currentMarketPrice_;
    std::chrono::time_point<std::chrono::system_clock> listedDate_;
};

}

#endif // STOCK_H