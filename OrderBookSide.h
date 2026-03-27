#pragma once
#include <list>
#include "Order.h"

class OrderBookSide {
private:
    std::list<Order> orders;
    int side;

public:
    OrderBookSide(int side) : side(side) {}
    void addOrder(const Order& order);
    void removeOrder(const Order& order);
    Order& getTopOrder();
    bool isEmpty() const { return orders.empty(); }
};