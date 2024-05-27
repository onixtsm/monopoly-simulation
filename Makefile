SOURCES=$(wildcard *.cpp)
OBJ=$(SOURCES:.cpp=.o )

%.o:%.c
	g++ -c $@ $^

main:$(SOURCES)
	g++ -std=c++17 -o $@ $^ -ggdb

clean:
	rm *.o
all: main

