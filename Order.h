#include <string>

class Order {

private:
    std::string OrderID;
    std::string ClientOrderID;
    std::string Instrument;
    int Side;
    double Price;
    int Quantity;

public:
    Order(const std::string& orderID, const std::string& clientOrderID, const std::string& instrument, int side, double price, int quantity)
        : OrderID(orderID), ClientOrderID(clientOrderID), Instrument(instrument), Side(side), Price(price), Quantity(quantity) {}

    std::string getOrderID() const ;
    std::string getClientOrderID() const ;
    std::string getInstrument() const ;
    int getSide() const ;
    double getPrice() const ;
    int getQuantity() const ;
    void reduceQuantity(int filledQuantity) ;
    std::string validate() const;
};