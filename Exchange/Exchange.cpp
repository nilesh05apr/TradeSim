#include "Exchange.h"
#include "../Utils/Utils.h"

namespace Exchange {

    Utils::Logger& logger = Utils::Logger::getInstance();

    void Exchange::start() {
        logger.info("Exchange started.");
        if (stocks_.empty()) {
            logger.error("No stocks listed.");
            throw std::invalid_argument("No stocks listed.");
        }
        isRunning = true;
        for (auto& [symbol, stock] : stocks_) {
            logger.info("Starting process for stock: " + symbol);
            stock->startProcessing();
        }
    }

    void Exchange::stop() {
        isRunning = false;
        for (auto& [symbol, stock] : stocks_) {
            stock->stopProcessing();
        }
        logger.warning("Exchange stopped.");
    }

    void Exchange::listStock(const std::string& symbol, const std::string& name, double listedPrice, int totalShares) {
        if (stocks_.find(symbol) != stocks_.end()) {
            logger.error("Stock already listed.");
            throw std::invalid_argument("Stock already listed.");
        }
        stocks_[symbol] = std::make_shared<Stock::Stock>(symbol, name, listedPrice, totalShares);
        logger.success("Stock listed: " + symbol);
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
            stock->orderBooks_.startProcessing();
            logger.debug("Order placed: " + boost::uuids::to_string(order.id) + 
                                            " Type: " + Utils::toString(order.type) +
                                            " Price: " + std::to_string(order.price) + 
                                            " Quantity: " + std::to_string(order.quantity));
        } catch (const std::exception& e) {
            logger.error("Failed to place order: " + std::string(e.what()));
        }
    }

    void Exchange::cancelOrder(const boost::uuids::uuid& orderId) {
        logger.warning("Cancelling order: " + boost::uuids::to_string(orderId));
        for (auto& [symbol, stock] : stocks_) {
            stock->cancelOrder(orderId);
        }
    }

    void Exchange::getOrderBook(const std::string& symbol) const {
        try {
            auto& stock = stocks_.at(symbol);
            stock->printOrderBook();
        } catch (const std::exception& e) {
            logger.error("Failed to get order book: " + std::string(e.what()));
        }
    }

    void Exchange::getTradeHistory(const std::string& symbol) const {
        try {
            auto& stock = stocks_.at(symbol);
            stock->printTradeHistory();
        } catch (const std::exception& e) {
            logger.error("Failed to get trade history: " + std::string(e.what()));
        }
    }

    std::vector<std::string> Exchange::getStockSymbols() const {
        logger.debug("Getting stock symbols.");
        std::vector<std::string> symbols;
        for (const auto& [symbol, stock] : stocks_) {
            symbols.push_back(symbol);
        }
        return symbols;

    }

} // namespace Exchange