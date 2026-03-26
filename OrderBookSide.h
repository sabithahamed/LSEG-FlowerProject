#include <list>
#include "Order.h"

class OrderBookSide {
private:
    std::list<Order> orders;

public:
    void addOrder(const Order& order);
    void removeOrder(const Order& order);
    Order getTopOrder() const;
};