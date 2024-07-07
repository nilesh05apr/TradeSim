#ifndef EXCHANGE_H
#define EXCHANGE_H

#include <unordered_map>
#include <string>
#include <memory>
#include <stdexcept>
#include "../Stock/Stock.h"
#include "../OrderBook/OrderBook.h"
#include "../Utils/Utils.h"

namespace Exchange {

class Exchange {
public:
    void start();
    void stop();

    // CRUD for stocks
    void listStock(const std::string& symbol, const std::string& name, double listedPrice, int totalShares);
    std::shared_ptr<Stock::Stock>& getStock(const std::string& symbol);

    // Order operations
    void placeOrder(const Order::Order& order);
    void cancelOrder(const boost::uuids::uuid& orderId);

    // Query operations
    void getOrderBook(const std::string& symbol) const;
    void getTradeHistory(const std::string& symbol) const;

private:
    std::unordered_map<std::string, std::shared_ptr<Stock::Stock>> stocks_;
};

}

#endif // EXCHANGE_H