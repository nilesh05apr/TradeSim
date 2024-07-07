# TradeSim

TradeSim is a C++ simulation of a stock exchange. It supports order types, including market and limit orders, and employs a multithreaded approach for efficient order processing.

## Features
- **Order Types**: Supports MARKET_BUY, MARKET_SELL, LIMIT_BUY, LIMIT_SELL, and CANCEL.
- **Comprehensive Logging**: Detailed logs for each step of order processing.
- **Order Matching**: FIFO and price-time priority matching algorithms.

## Prerequisites
- **CMake**: Ensure CMake is installed on your system.
- **Boost Library**: Install Boost libraries for UUID generation.
- **C++17 Compiler**: Ensure you have a C++17 compatible compiler (e.g., GCC, Clang).

## Installation

### Ubuntu
```sh
sudo apt-get update
sudo apt-get install cmake libboost-all-dev build-essential
```

### MacOS
```sh
brew install cmake boost
```

### WINDOWS
- Install CMake and Boost, ensure they are added to your system PATH.

## Build and Run
### Clone the Repository
```sh
git clone https://github.com/nilesh05apr/TradeSim.git
cd TradeSim
```

### Create Build Directory and Run CMake
```sh
mkdir build
cd build
cmake ..
make
```

### Run the Simulation
```sh
./TradeSim
```

## Project Structure
```shell
TradeSim/
|-- Utils/
|   |-- Utils.h
|   |-- Utils.cpp
|-- Exchange/
|   |-- Exchange.h
|   |-- Exchange.cpp
|-- Order/
|   |-- Order.h
|-- MatchOrder/
|   |-- MatchOrder.h
|   |-- MatchOrder.cpp
|-- OrderBook/
|   |-- OrderBook.h
|   |-- OrderBook.cpp
|-- Stock/
|   |-- Stock.h
|   |-- Stock.cpp
|-- main.cpp
|-- CMakeLists.txt
```

## How to Use

### Listing a Stock
Edit main.cpp to list a stock with the following code:
```c++
exchange.listStock("AAPL", "Apple Inc.", 150.0, 1000000);
```

### Placing Orders
Add code in main.cpp to place orders:
```c++
Order::Order buyOrder1("AAPL", Order::OrderType::LIMIT_BUY, 150.0, 10);
Order::Order sellOrder1("AAPL", Order::OrderType::LIMIT_SELL, 150.0, 5);
Order::Order marketBuyOrder("AAPL", Order::OrderType::MARKET_BUY, 0.0, 15);
exchange.placeOrder(buyOrder1);
exchange.placeOrder(sellOrder1);
exchange.placeOrder(marketBuyOrder);
```

### Query Order Book and Trade History
```c++
exchange.getOrderBook("AAPL");
exchange.getTradeHistory("AAPL");
```

### Stopping the Exchange
Ensure to stop the exchange to gracefully terminate threads:
```c++
exchange.stop();
```
## License
```sh
This project is licensed under the MIT License. See the LICENSE file for details.
```


