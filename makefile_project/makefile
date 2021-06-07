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

release: $(OBJ_FILES)
	@mkdir -p bin
	@mkdir -p test_run
	@g++ -O3 -g obj/*.o -o $@
	@mv $@ bin/

$(OBJ_FILES): $(SOURCE_FILES)
	@mkdir -p obj	
	@g++ -c $^ -o $@ 
	@mv $@ obj/

.PHONY: $(OBJ_FILES) release bin/main test	
count = `diff $(file1) $(file2)| grep "^>" | wc -l`

test: 
	@make -s  all
	@./bin/main
	@echo "Command is checking the difference..."
	@if diff -q $(file1) $(file2); then
		@echo "PASSED"
	@else
		@echo "FAILED";
		@echo The count of different lines is $(count)
	@fi
clean:
	@echo "All generated files are deleted"
	@rm -rf bin test_run obj
