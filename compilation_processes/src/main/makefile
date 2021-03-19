SOURCES := $(wildcard ../../src/main/*.cpp)
OBJS := $(patsubst %.c, %.o, $(SOURCES))

LFLAGS +=  -L ../../lib/ -ltest
IFLAGS +=  -I../gcd
#export LD_LIBRARY_PATH=./li/

.PHONY: ../../main main.o

#../../objc/main.o : main.cpp
#	g++ -c $^ -o $@

../../bin/main: $(OBJS)
	g++ -g  $^ $(LFLAGS) $(IFLAGS) -o $@


