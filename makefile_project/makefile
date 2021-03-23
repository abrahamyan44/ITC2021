.ONESHELL:
SHELL := /bin/bash

SOURCE_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(patsubst %.cpp, %.o, $(SOURCE_FILES))
file1 = "test/goutput.txt"
file2 = "test_run/output.txt"

all: $(OBJ_FILES) release bin/main

bin/main:
	@mkdir -p bin
	@mkdir -p test_run
	@g++ -g obj/*.o -o $@

release:
	@mkdir -p bin
	@mkdir -p test_run
	@g++ -O3 -g obj/*.o -o bin/$@

$(OBJ_FILES): $(SOURCE_FILES)
	@mkdir -p obj	
	@g++ -c $^ -o $@ 
	@mv $@ obj/

.PHONY: $(OBJ_FILES) release bin/main test	

test: 
	@make -s  all
	@./bin/main
	@echo "Comand is checking the differnce..."
	@if diff -q $(file1) $(file2); then
		@echo "PASSED"
	@else
		@echo "FAILED";
	@fi

clean:
	@echo "All generated files are deleted"
	@rm -rf bin test_run obj
