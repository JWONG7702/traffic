CC = g++
CXX = g++ 

INCLUDE = 

CFLAG = -g Wall $(INCLUDE)
CXXFLAGS = -g -Wall $(INCLUDE) -std=c++11

executables = simulation 
objects = simulation.o road.o

.PHONY: default
default: $(executables)

$(executables): road.o

$(objects): road.h

.PHONY: clean
clean: 
	rm -f *~ a.out core $(objects) $(executable)
.PHONY: all
all: clean default
