cmake_minimum_required(VERSION 3.10)
project(TradeSim)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

include_directories(Utils)
include_directories(Order)
include_directories(OrderBook)
include_directories(Exchange)
include_directories(Stock)
include_directories(MatchOrder)

add_executable(TradeSim main.cpp 
                           Utils/Utils.cpp 
                           OrderBook/OrderBook.cpp 
                           Exchange/Exchange.cpp 
                           Stock/Stock.cpp 
                           MatchOrder/MatchOrder.cpp)

target_link_libraries(TradeSim ${Boost_LIBRARIES})