CC = g++
CXX = g++ -std=c++11
INCLUDE = 
CFLAG = -g Wall $(INCLUDE)
executables = simulation 
objects = road.o simulation.o
.PHONY: default
default: $(executables)

$(executables): road.o

$(objects): road.h

.PHONY: clean
clean: 
	rm -f *~ a.out core $(objects) $(executable)
.PHONY: all
all: clean default
