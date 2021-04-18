EXE := main
SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp, obj/%.o, $(SRCS))

.PHONY: clean

$(EXE): $(OBJS)
	g++ $^ -o $@

obj/%.o: %.cpp
	mkdir -p obj
	g++ -c $^ -o $@

clean:
	rm -rf obj $(EXE)

