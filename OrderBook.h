#pragma once
#include "OrderBookSide.h"

class Exchange;

class OrderBook {
private:
    OrderBookSide buySide;
    OrderBookSide sellSide;

public:
    OrderBook() : buySide(1), sellSide(2) {}
    void processOrder(Order& order, Exchange& exchange);
    bool isMatchingOrder(const Order& order);

};