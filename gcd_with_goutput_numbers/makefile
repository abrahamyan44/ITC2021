
EXECUTABLE :=gcd
SOURCE_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(patsubst src/%.cpp, obj/%.o, $(SOURCE_FILES))
CC :=g++ 
CHOICE ?= -O3

$(EXECUTABLE): $(OBJ_FILES)
	@$(CC) $^ -o $@
	@echo "Linking stage. \n Executable file is creating! "


obj/%.o : src/%.cpp
	mkdir -p obj
	@$(CC) -c $^ -o $@	
	@echo "Creating object files"


.PHONY: clean

clean:
	@rm $(OBJ_FILES) $(EXECUTABLE) 2> /dev/null
	@echo "Objeced files removed."


.PHONY: release

release:
	$(MAKE) CHOICE="-O3"


.PHONY: debug

debug:
	$(MAKE) CHOICE="-g ggdb"
	gdb ./$(EXECUTABLE)	
