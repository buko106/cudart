CXX=g++
CXXFLAGS=-std=c++11 -Wall -Wconversion -Wextra

.PHONY: all clean

all: minrt

minrt: minrt.cpp
	$(CXX) -o $@ $^ $(CXXFLAGS)

clean:
	rm -f minrt
