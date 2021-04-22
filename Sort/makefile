

EXECUTABLE :=sorting_benchmark
SOURCE_FILES := $(wildcard *.cpp)
OBJ_FILES := $(patsubst %.cpp, %.o, $(SOURCE_FILES))
CC :=g++ 

$(EXECUTABLE): $(OBJ_FILES)
	@$(CC) $^ -o $@
	@echo "Linking stage. \n Executable file is creating! "


%.o : %.cpp
	@$(CC) -c $^ -o $@	
	@echo "Creating object files"


.PHONY: clean

clean:
	@rm $(OBJ_FILES) $(EXECUTABLE) 2> /dev/null
	@echo "Genereted files removed."


.PHONY: debug

debug:
	$(MAKE) CHOICE="-g ggdb"
	gdb ./$(EXECUTABLE)	
