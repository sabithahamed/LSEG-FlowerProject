# Flower Exchange Project

A C++ matching engine that processes flower orders from a CSV file and generates execution reports.

## Files to Push

### Source Code
- `main.cpp`: Entry point of the application.
- `Exchange.cpp` / `Exchange.h`: Orchestrates order processing and CSV I/O.
- `OrderBook.cpp` / `OrderBook.h`: Manages the matching engine for each instrument.
- `OrderBookSide.cpp` / `OrderBookSide.h`: Manages sorted buy/sell sides (Price/Time priority).
- `Order.cpp` / `Order.h`: Order data structure and validation rules.
- `ExecutionReport.h`: Simplified structure for reporting executions.

### Build & Test
- `Makefile`: Build script for the project.
- `orders.csv`: Sample input file with test orders.
- `Session06_Project-Flower-Exchange.txt`: Project specification reference.

## How to Run

1.  **Compile**: Run `make` in the terminal.
    ```bash
    make
    ```
2.  **Execute**: Run the generated binary.
    ```bash
    ./FlowerExchange
    ```
3.  **Results**: Check `execution_rep.csv` for the generated reports.

## Features
- Full compliance with LSEG Flower Exchange requirements.
- FIFO and Price-Time priority matching.
- Automatic input validation (Instruments, Quantities, Prices).
- Precision timestamps in execution reports.
