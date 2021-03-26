EXE = stack
CC = g++
CFLAGS = -std=c++11
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

all: $(EXE)

$(EXE): $(OBJS)
		$(CC) $(OBJS) $(CFLAGS) -o $@

.cpp.o:
		$(CC) $(CFLAGS) -c $^ -o $@

depend: $(SRCS)
		makedepend $^

clean:
		rm $(OBJS) $(EXE)
