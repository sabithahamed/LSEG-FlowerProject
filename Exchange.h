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
    void ReadOrders();
    void generateExecutionReport(const Order& order, const std::string& reason);
    void processExecutionReport(const ExecutionReport& report);
    void printExecutionReports();
    int getNextOrderID();
};