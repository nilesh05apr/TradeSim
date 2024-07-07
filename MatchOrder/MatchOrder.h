#ifndef MATCHORDER_H
#define MATCHORDER_H

#include <vector>
#include <algorithm>
#include "../Order/Order.h"

namespace MatchOrder {
using namespace Order;

class MatchOrder {
public:
    static int matchOrders(std::vector<Order::Order>& buyOrders, std::vector<Order::Order>& sellOrders, std::vector<Order::Order>& tradeHistory);
};

}

#endif // MATCHORDER_H