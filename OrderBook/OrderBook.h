#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include <queue>
#include <unordered_map>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_hash.hpp>
#include "../Order/Order.h"
#include "../Utils/Utils.h"

namespace OrderBook {

class OrderBook {
public:
    OrderBook();
    
    // Delete copy constructor and assignment operator
    OrderBook(const OrderBook&) = delete;
    OrderBook& operator=(const OrderBook&) = delete;

    void addOrder(const Order::Order& order);
    void startProcessing();
    void stopProcessing();
    void cancelOrder(const boost::uuids::uuid& orderId);

    // Query methods
    void print() const;
    void printHistory() const;
    void processOrders();

private:
    std::priority_queue<Order::Order, std::vector<Order::Order>, Order::OrderComparator> orders_;
    std::unordered_map<boost::uuids::uuid, Order::Order, boost::hash<boost::uuids::uuid>> orderMap_;
    std::vector<Order::Order> tradeHistory_;
//    std::atomic<bool> stopProcessing_ = false;
    bool stopProcessing_ = false;

};

}

#endif // ORDERBOOK_H