#include "Exchange.h"
#include <iostream>
#include <string>

int main() {

    std::string filename;
    std::cout << "Enter the filename of the orders CSV (default: orders.csv): ";
    std::getline(std::cin, filename);
    if (filename.empty()) {
        filename = "orders.csv";
    }
    Exchange exchange;
    
    std::cout << "Starting Flower Exchange..." << std::endl;
    
    exchange.ReadOrders(filename);
    
    std::cout << "Processing complete. Generating execution reports..." << std::endl;
    
    exchange.printExecutionReports();
    
    std::cout << "Done. Results saved to execution_rep.csv" << std::endl;
    
    return 0;
}
