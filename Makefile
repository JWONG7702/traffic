CXX = g++
INCLUDE = 
CFLAG = -g Wall $(INCLUDE)
executables = 
objects =
.PHONY: default
default: $(executable)

$(executables): road.o

$(objects): road.h

.PHONY: clean
clean: 
	rm -f *~ a.out core $(objects) $(executable)
.PHONY: all
all: clean default
