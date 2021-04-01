
OBJPATH := ../../obj
BINPATH := ../../bin
SRC := $(wildcard *.cpp)
OBJ := $(patsubst %.cpp,$(OBJPATH)/%.o,$(SRC))
OBJECTS := $(wildcard ../../obj/*.o)


$(BINPATH)/main: $(OBJECTS) $(OBJ)
	g++ $^ -o $@

$(OBJ): $(SRC) 
	g++ -c $^ -o $@

