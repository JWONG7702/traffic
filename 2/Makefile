CC = g++
CXX = g++ 

INCLUDE = 

CFLAG = -g -Wall $(INCLUDE)
CXXFLAGS = -g -Wall -std=c++11 $(INCLUDE)

executables = simulation test1 
objects = simulation.o road.o lane.o

.PHONY: default
default: $(executables)

$(executables): road.o

$(objects): road.h

.PHONY: clean
clean: 
	rm -f *~ a.out core $(objects) $(executables)
.PHONY: all
all: clean default
