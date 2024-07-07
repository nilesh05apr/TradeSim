#include<iostream>
#include<string>
#include<mutex>
#include<memory>
#include "../Order/Order.h"

#ifndef UTILS_H
#define UTILS_H

namespace Utils {
    class Logger {
        public:
        static Logger& getInstance();
        void log(const std::string& message);

        private:
        Logger() {}
        Logger(const Logger&) = delete;
        Logger& operator=(const Logger&) = delete;
        static std::once_flag init_instance_flag;
        static std::unique_ptr<Utils::Logger> instance;
        std::mutex log_mutex;
    };

std::string toString(Order::OrderType type);
}

#endif // UTILS_H