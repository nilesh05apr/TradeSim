#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <chrono>
#include <exception>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace Order {

enum class OrderType {
    MARKET_BUY, MARKET_SELL,
    LIMIT_BUY, LIMIT_SELL,
    CANCEL
};

class Order {
    public:
    boost::uuids::uuid id;
    std::string symbol;
    OrderType type;
    double price; // Only relevant for LIMIT orders
    int quantity;
    std::chrono::time_point<std::chrono::high_resolution_clock> timestamp;

    // Default constructor
    Order() : id(boost::uuids::nil_uuid()), type(OrderType::CANCEL), price(0.0), quantity(0) {}

    // Default copy constructor
    Order(const Order& other) = default;

    // Default destructor
    ~Order() = default;

    // Move constructor
    Order(Order&& order) noexcept = default;

    // Copy assignment operator
    Order& operator=(const Order& other) = default;

    // Move assignment operator
    Order& operator=(Order&& other) noexcept = default;

    Order(const std::string& symbol, OrderType type, double price, int qty)
        : id(boost::uuids::random_generator()()), 
          symbol(symbol), 
          type(type), 
          price(price), 
          quantity(qty), 
          timestamp(std::chrono::high_resolution_clock::now())
    {
        if ((type == OrderType::LIMIT_BUY || type == OrderType::LIMIT_SELL) && price <= 0) {
            throw std::invalid_argument("Limit order price must be greater than zero.");
        }

        if (type != OrderType::CANCEL && qty <= 0) {
            throw std::invalid_argument("Order quantity must be greater than zero.");
        }
    }

    bool operator<(const Order& other) const {
        return timestamp < other.timestamp; // FIFO by time
    }
};

// Comparator for Order to use in priority_queue
struct OrderComparator {
    bool operator()(const Order& a, const Order& b) const {
        // Greater price has higher priority for BUY orders, lesser price for SELL orders
        if (a.type == OrderType::MARKET_BUY || a.type == OrderType::LIMIT_BUY) {
            if (a.price == b.price) {
                return a.timestamp > b.timestamp; // Earlier timestamp has priority
            }
            return a.price < b.price;
        } else {
            if (a.price == b.price) {
                return a.timestamp > b.timestamp; // Earlier timestamp has priority
            }
            return a.price > b.price;
        }
    }
};

}

#endif // ORDER_H