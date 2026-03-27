#include "Exchange.h"
#include "OrderBook.h"
#include "Order.h"
#include "ExecutionReport.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <algorithm>

void Exchange::ReadOrders() {
    std::ifstream file("orders.csv");
    if (!file.is_open()) {
        std::cerr << "Error: Could not open orders.csv" << std::endl;
        return;
    }

    std::string line;
    // Skip header
    std::getline(file, line);

    while (std::getline(file, line)) {
        if (line.empty()) continue;
        
        std::stringstream ss(line);
        std::string clientOrderID, instrument, sideStr, qtyStr, priceStr;

        std::getline(ss, clientOrderID, ',');
        std::getline(ss, instrument, ',');
        std::getline(ss, sideStr, ',');
        std::getline(ss, qtyStr, ',');
        std::getline(ss, priceStr, ',');

        try {
            int side = std::stoi(sideStr);
            int qty = std::stoi(qtyStr);
            double price = std::stod(priceStr);

            std::string orderID = "ord" + std::to_string(getNextOrderID());
            Order order(orderID, clientOrderID, instrument, side, price, qty);

            std::string validationError = order.validate();
            if (!validationError.empty()) {
                generateExecutionReport(order, "1", price, qty, validationError);
                continue;
            }

            if (orderBooks.find(instrument) == orderBooks.end()) {
                orderBooks[instrument] = OrderBook();
            }
            
            orderBooks[instrument].processOrder(order, *this);

        } catch (...) {
            std::cerr << "Error parsing line: " << line << std::endl;
        }
    }
    
    file.close();
}

void Exchange::generateExecutionReport(const Order& order, const std::string& status, double price, int quantity, const std::string& reason) {
    ExecutionReport report;
    report.OrderID = order.getOrderID();
    report.ClientOrderID = order.getClientOrderID();
    report.Instrument = order.getInstrument();
    report.Side = order.getSide();
    report.Price = price;
    report.Quantity = quantity;
    report.Status = std::stoi(status);
    report.Reason = reason;

    // Get current time in specified format
    auto now = std::chrono::system_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm* now_tm = std::localtime(&now_c);

    std::stringstream ss;
    ss << std::put_time(now_tm, "%Y%m%d-%H%M%S") << "." << std::setfill('0') << std::setw(3) << ms.count();
    report.TransactionTime = ss.str();

    executionReports.push(report);
}

void Exchange::printExecutionReports() {
    std::ofstream outFile("execution_rep.csv");
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open execution_rep.csv for writing" << std::endl;
        return;
    }

    outFile << "Order ID,Client Order ID,Instrument,Side,Exec Status,Quantity,Price,Reason,Transaction Time" << std::endl;
    
    while (!executionReports.empty()) {
        ExecutionReport report = executionReports.front();
        executionReports.pop();

        outFile << report.OrderID << ","
                << report.ClientOrderID << ","
                << report.Instrument << ","
                << report.Side << ","
                << report.Status << ","
                << report.Quantity << ","
                << std::fixed << std::setprecision(2) << report.Price << ","
                << report.Reason << ","
                << report.TransactionTime << std::endl;
    }
    
    outFile.close();
}

int Exchange::getNextOrderID() {
    return ++orderCounter;
}
