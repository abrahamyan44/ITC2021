SOURCE_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(patsubst %.cpp, %.o, $(SOURCE_FILES))

bin/main: $(OBJ_FILES)
	@mkdir -p bin
	g++ -g $^ -o $@
    
OBJ_FILES: $(SOURCE_FILES)
	g++ -O3 -c $^ -o $@
