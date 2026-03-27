#include "OrderBook.h"
#include "Order.h"
#include "ExecutionReport.h"
#include "Exchange.h"
#include <vector>
#include <iostream>

void OrderBook::processOrder(Order& order, Exchange& exchange) {
    OrderBookSide& oppositeSide = (order.getSide() == 1) ? sellSide : buySide;
    OrderBookSide& ownSide = (order.getSide() == 1) ? buySide : sellSide;

    while (!oppositeSide.isEmpty()) {
        Order& topOrder = oppositeSide.getTopOrder();
        bool isMatch = (order.getSide() == 1) ? (order.getPrice() >= topOrder.getPrice()) 
                                              : (order.getPrice() <= topOrder.getPrice());

        if (isMatch) {
            int fillQty = std::min(order.getQuantity(), topOrder.getQuantity());
            double matchPrice = topOrder.getPrice();

            order.reduceQuantity(fillQty);
            topOrder.reduceQuantity(fillQty);

            // Generate reports for both sides
            exchange.generateExecutionReport(order, (order.getQuantity() == 0) ? "2" : "3", matchPrice, fillQty); 
            exchange.generateExecutionReport(topOrder, (topOrder.getQuantity() == 0) ? "2" : "3", matchPrice, fillQty);

            if (topOrder.getQuantity() == 0) {
                oppositeSide.removeOrder(topOrder);
            }

            if (order.getQuantity() == 0) break;
        } else {
            break;
        }
    }

    if (order.getQuantity() > 0) {
        ownSide.addOrder(order);
        exchange.generateExecutionReport(order, "0", order.getPrice(), order.getQuantity());
    }
}

bool OrderBook::isMatchingOrder(const Order& order) {
    if (order.getSide() == 1) { // Buy
        if (sellSide.isEmpty()) return false;
        return order.getPrice() >= sellSide.getTopOrder().getPrice();
    } else { // Sell
        if (buySide.isEmpty()) return false;
        return order.getPrice() <= buySide.getTopOrder().getPrice();
    }
}
