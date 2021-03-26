EXE = vector
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
CC = g++
CFLAGS = -std=c++11

all: $(EXE)

$(EXE): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $@

.cpp.o:
		$(CC) $(CFLAGS) -c $^ -o $@

depend: $(SRCS)
		makedepend $^

clean:
		rm $(OBJS) $(EXE)
