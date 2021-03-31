
export EXE := main
export CC := g++
export SOURCES := $(wildcard *.cpp)
export DEPS := $(patsubst %.cpp, %.dep, $(SOURCES))

$(EXE) : $(SOURCES)
	$(CC) $^ -o $@ 

%.dep : %.cpp
	$(CC) -MM $^ -o $@

.PHONY : clean
clean :
	rm $(DEPS) $(EXE)	

-include $(DEPS)
