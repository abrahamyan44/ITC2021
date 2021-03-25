OBJPATH := ../../obj
BINPATH := ../../bin
SRC := $(wildcard *.cpp)
OBJ := $(patsubst %.cpp,%.o,$(SRC))
OBJECTS := $(wildcard ../../obj/*.o)


$(BINPATH)/main: $(OBJECTS)
	@echo "OBJECTS-----> "$^
	g++ $^ -o $@

$(OBJPATH)/%.o: %.cpp
	@echo "MAIN OBJ----> "$<
	g++ -c $< -o $@
