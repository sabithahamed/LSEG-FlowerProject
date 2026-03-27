#include "Order.h"
#include <cctype>

std::string Order::getOrderID() const {
    return OrderID;
}

std::string Order::getClientOrderID() const {
    return ClientOrderID;
}

std::string Order::getInstrument() const {
    return Instrument;
}

int Order::getSide() const {
    return Side;
}

double Order::getPrice() const {
    return Price;
}

int Order::getQuantity() const {
    return Quantity;
}

void Order::reduceQuantity(int filledQuantity) {
    Quantity -= filledQuantity;
}

std::string Order::validate() const {
    if (ClientOrderID.empty()) return "Invalid client order ID";
    if (ClientOrderID.length() > 7) return "Invalid client order ID";
    for (char c : ClientOrderID) {
        if (!std::isalnum(c)) return "Invalid client order ID";
    }
    if (Instrument != "Rose" && Instrument != "Lavender" && Instrument != "Lotus" && Instrument != "Tulip" && Instrument != "Orchid") {
        return "Invalid instrument";
    }
    if (Side != 1 && Side != 2) return "Invalid side";
    if (Price <= 0.0) return "Invalid price";
    if (Quantity < 10 || Quantity > 1000 || Quantity % 10 != 0) return "Invalid size";
    
    return "";
}
