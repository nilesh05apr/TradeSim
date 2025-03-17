#include "Stock.h"
#include <boost/uuid/uuid_generators.hpp>
#include "../Utils/Utils.h"

namespace Stock {

    Utils::Logger& logger = Utils::Logger::getInstance();


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
            orderBooks_.addOrder(order);
            logger.info("Order added: " + boost::uuids::to_string(order.id) + 
            " Type: " + Utils::toString(order.type) +
            " Price: " + std::to_string(order.price) + 
            " Quantity: " + std::to_string(order.quantity));
        }


        void Stock::cancelOrder(const boost::uuids::uuid& orderId) {
            logger.warning("Cancelling order: " + boost::uuids::to_string(orderId));
            orderBooks_.cancelOrder(orderId);
        }

        void Stock::printOrderBook() const {
            logger.info("Printing order book for " + symbol_);
            orderBooks_.print();
        }

        void Stock::printTradeHistory() const {
            logger.info("Printing trade history for " + symbol_);
            orderBooks_.printHistory();
        }

        void Stock::startProcessing() {
            logger.debug("Stock processing started.");
            orderBooks_.startProcessing();
        }

        void Stock::stopProcessing() {
            logger.warning("Stock processing stopped.");
            orderBooks_.stopProcessing();
        }

}