#include "Exchange.h"
#include <iostream>

int main() {
    Exchange exchange;
    
    std::cout << "Starting Flower Exchange..." << std::endl;
    
    exchange.ReadOrders();
    
    std::cout << "Processing complete. Generating execution reports..." << std::endl;
    
    exchange.printExecutionReports();
    
    std::cout << "Done. Results saved to execution_rep.csv" << std::endl;
    
    return 0;
}
