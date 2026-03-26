#include "OrderBookSide.h"

class OrderBook {
private:
    OrderBookSide buySide;
    OrderBookSide sellSide;

public:
    void processOrder(const Order& order);
    bool isMatchingOrder(const Order& order);

};