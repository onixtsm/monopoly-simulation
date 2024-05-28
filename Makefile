SOURCES=$(wildcard *.cpp)
OBJ=$(SOURCES:.cpp=.o )
CFLAGS=-ggdb

%.o:%.c
	$(CXX) -c $@ $^

main:$(SOURCES)
	$(CXX) -std=c++17 -o $@ $^ $(CFLAGS)

windows: $(SOURCES)
	i686-w64-mingw32-g++ -std=c++17 -o main.exe $^ $(CFLAGS) -static

clean:
	rm *.o
all: main

