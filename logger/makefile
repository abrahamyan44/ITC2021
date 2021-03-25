SRCS = main.cpp log.cpp
OBJS = $(SRCS:.cpp=.o)
MAIN = logger 
export CFLAGS=-std=c++11 
CC = g++
INCLUDES := ./
.PHONY: depend clean

all: $(MAIN)
 
$(MAIN): $(OBJS)
		$(CC) $(OBJS) $(CFLAGS) -o $(MAIN) 
 
.cpp.o:
		$(CC) $(CFLAGS) -c $< -o $@
 
clean:
		rm *.o $(MAIN)

depend: $(SRCS)
		makedepend $(INCLUDES) $^


 
