#pragma once
#include "OrderBook.h"
#include "ExecutionReport.h"
#include <queue>
#include <map>
#include <string>

class Exchange {
private:
    std::map<std::string, OrderBook> orderBooks;
    std::queue<ExecutionReport> executionReports;
    int orderCounter;
public:
    Exchange() : orderCounter(0) {}
    void ReadOrders(std::string filename );
    void generateExecutionReport(const Order& order, const std::string& status, double price, int quantity, const std::string& Timestamp, const std::string& reason = "");
    void processExecutionReport(const ExecutionReport& report);
    void printExecutionReports();
    int getNextOrderID();
    std::string getCurrentTimestamp();
};