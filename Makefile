CC = g++
CFLAGS = -std=c++11 -Wall

SRCS = main.cpp Exchange.cpp OrderBook.cpp OrderBookSide.cpp Order.cpp
OBJS = $(SRCS:.cpp=.o)
MAIN = FlowerExchange

all: $(MAIN)
	@echo Compiled FlowerExchange successfully.

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(MAIN)
