#pragma once
#include <string>

struct ExecutionReport {
    std::string OrderID;
    std::string ClientOrderID;
    std::string Instrument;
    int Side;
    double Price;
    int Quantity;
    int Status;
    std::string Reason;
    std::string TransactionTime;
};