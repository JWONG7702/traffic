CC = g++
CXX = g++ 

INCLUDE = 

CFLAG = -g Wall $(INCLUDE)
CXXFLAGS = -g -Wall $(INCLUDE) -std=c++11

executables = simulation 
objects = simulation.o road.o

.PHONY: default
default: $(executables)

$(objects): road.h

.PHONY: clean
clean: 
	rm -f *~ a.out core simulation $(objects) $(executable)
.PHONY: all
all: clean default
