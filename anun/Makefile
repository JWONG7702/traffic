CC = g++
CXX = g++ 

INCLUDE = 

CFLAG = -g Wall $(INCLUDE)
CXXFLAGS = -g -Wall $(INCLUDE) -std=c++11

executables = data 
objects =

.PHONY: default
default: $(executables)

$(objects):

.PHONY: clean
clean: 
	rm -f *~ a.out core $(objects) $(executables)
.PHONY: all
all: clean default
