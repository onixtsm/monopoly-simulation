SOURCES=$(wildcard *.cpp)
OBJ=$(SOURCES:.cpp=.o )
CFLAGS=-ggdb

%.o:%.c
	$(CXX) -c $@ $^

main:$(SOURCES)
	$(CXX) -std=c++17 -o $@ $^ $(CFLAGS)

clean:
	rm *.o
all: main

