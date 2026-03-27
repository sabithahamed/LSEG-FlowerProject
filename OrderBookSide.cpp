#include "OrderBookSide.h"

void OrderBookSide::addOrder(const Order& order) {
    auto it = orders.begin();
    if (side == 1) { // Buy - Descending
        while (it != orders.end() && it->getPrice() >= order.getPrice()) {
            ++it;
        }
    } else { // Sell - Ascending
        while (it != orders.end() && it->getPrice() <= order.getPrice()) {
            ++it;
        }
    }
    orders.insert(it, order);
}

void OrderBookSide::removeOrder(const Order& order) {
    for (auto it = orders.begin(); it != orders.end(); ++it) {
        if (it->getOrderID() == order.getOrderID()) {
            orders.erase(it);
            return;
        }
    }
}

Order& OrderBookSide::getTopOrder() {
    return orders.front();
}
