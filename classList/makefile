
export CC := g++
export EXE := main

export SRC := $(wildcard src/*.cpp)
export OBJ := $(patsubst src/%.cpp, obj/%.o, $(SRC))
export DEP := $(patsubst src/%.cpp, obj/%.dep, $(SRC))

bin/$(EXE) : $(OBJ)
	mkdir -p bin
	$(CC) $^ -o $@

obj/%.o : src/%.cpp
	mkdir -p obj
	$(CC) -c $< -o $@

obj/%.dep : src/%.cpp
	mkdir -p obj
	$(CC) -MM $< -o $@

.PHONY : clean
clean:
	rm -r bin obj 

-include $(DEP)
