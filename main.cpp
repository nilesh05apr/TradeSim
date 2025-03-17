#include "Exchange/Exchange.h"
#include "Order/Order.h"
#include "Utils/Utils.h"
#include "OrderBook/OrderBook.h"
#include <thread>
#include <memory>
#include <random>
#include <ctime>
#include <limits>
#include <cmath>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/random/variate_generator.hpp>

using std::normal_distribution;
using std::mt19937_64;


int current_time_nanoseconds(){
  struct timespec tm;
  clock_gettime(CLOCK_REALTIME, &tm);
  return tm.tv_nsec;
}

int random_number(int start, int end){
  boost::random::mt19937_64 mc(current_time_nanoseconds());
  boost::random::uniform_int_distribution<> udist(start, end);
  return udist(mc);
}

float sigma(float x) {
  return exp(-1 * x) / (1 + exp(-1 * x));
}

int getRandomOrderType_() {
  float epsilon = random_number(0, 5);
  return int(epsilon);
}

Order::OrderType getRandomOrderType() {
  int num = getRandomOrderType_();

  switch (num) {
    case 0:
      std::cout<< "LIMIT BUY" << std::endl;
      return Order::OrderType::LIMIT_BUY;
    case 1:
      std::cout<< "LIMIT SELL" << std::endl;  
      return Order::OrderType::LIMIT_SELL;
    case 2:
      std::cout<< "MARKET BUY" << std::endl;
      return Order::OrderType::MARKET_BUY;
    case 3:
      std::cout<< "MARKET SELL" <<std::endl;
      return Order::OrderType::MARKET_SELL;
    default:
      std::cout<< "DEFAULT LIMIT ORDER" << std::endl;
      return Order::OrderType::LIMIT_BUY;
      break;
  }
}


int main() {
  
    Utils::Logger& logger = Utils::Logger::getInstance();

    Exchange::Exchange exchange;

    // List stock
    try {
        exchange.listStock("AAPL", "Apple Inc.", 150.0, 1000000);
    } catch (const std::exception& e) {
        logger.error("Stock listing error: " + std::string(e.what()));
        return 1;
    }

    // Start exchange processing
    exchange.start();

    // Create orders
    try {
        // Limit orders

        Order::Order buyOrder("AAPL", Order::OrderType::LIMIT_BUY, 150.0, 10);
        Order::Order sellOrder("AAPL", Order::OrderType::LIMIT_SELL, 150.0, 5);

        // Market orders
        Order::Order marketBuyOrder("AAPL", Order::OrderType::MARKET_BUY, 0.0, 15);
        Order::Order marketSellOrder("AAPL", Order::OrderType::MARKET_SELL, 0.0, 10);

        // Place orders
        exchange.placeOrder(buyOrder);
        exchange.placeOrder(sellOrder);
        exchange.placeOrder(marketBuyOrder);
        exchange.placeOrder(marketSellOrder);

        // Cancel order
        buyOrder.type = Order::OrderType::CANCEL;
        exchange.placeOrder(buyOrder);
        
    } catch (const std::exception& e) {
        logger.error("Order creation error: " + std::string(e.what()));
        return 1;
    }

    // Query order book and trade history
    try {
        exchange.getOrderBook("AAPL");
        exchange.getTradeHistory("AAPL");
    } catch (const std::exception& e) {
        logger.error("Error fetching order book or trade history: " + std::string(e.what()));
        return 1;
    }

    // Stop exchange processing (stops all stock process threads)
    exchange.stop();
    
    Order::OrderType type_ = getRandomOrderType();

    std::cout<< std::to_string(static_cast<int>(type_)) << std::endl;

    return 0;
}
