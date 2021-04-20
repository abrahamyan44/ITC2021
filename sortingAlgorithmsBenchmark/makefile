export EXE := benchmark
export CC := g++

export SRCS := $(wildcard *.cpp)
export OBJS := $(patsubst %.cpp, %.o, $(SRCS))
export DEPS := $(patsubst %.cpp, %.dep, $(SRCS))

$(EXE) : $(OBJS)
	$(CC) $^ -o $@

%.o : 
	$(CC) -c $< -o $@

%.dep : %.cpp
	$(CC) -MM $^ -o $@

-include $(DEPS)

.PHONY : clean
clean :
	rm $(EXE) $(OBJS) $(DEPS)	
