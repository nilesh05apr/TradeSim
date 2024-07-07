#include "Utils.h"
#include <iostream>
#include <memory>
#include <mutex>
#include <sstream>
#include <chrono>
#include <iomanip>

std::unique_ptr<Utils::Logger> Utils::Logger::instance;
std::once_flag Utils::Logger::init_instance_flag;

Utils::Logger& Utils::Logger::getInstance() {
    std::call_once(init_instance_flag, []() {
        instance.reset(new Logger);
    });
    return *instance;
}

void Utils::Logger::log(const std::string& message) {
    std::lock_guard<std::mutex> lock(log_mutex);
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    std::cout << "[" << std::put_time(std::localtime(&now_c), "%F %T") << "]: " << message << std::endl;    

}

std::string Utils::toString(Order::OrderType type) {
    switch (type) {
        case Order::OrderType::LIMIT_BUY:
            return "LIMIT_BUY";
        case Order::OrderType::LIMIT_SELL:
            return "LIMIT_SELL";
        case Order::OrderType::MARKET_BUY:
            return "MARKET_BUY";
        case Order::OrderType::MARKET_SELL:
            return "MARKET_SELL";
        default:
            return "UNKNOWN";
    }
}