CC = g++
CXX = g++ -std=c++11
INCLUDE = 
CFLAG = -g Wall $(INCLUDE)
executables = simulation 
objects = road.o simulation.o
.PHONY: default
default: $(executables)

$(objects): road.h

.PHONY: clean
clean: 
	rm -f *~ a.out core simulation $(objects) $(executable)
.PHONY: all
all: clean default
