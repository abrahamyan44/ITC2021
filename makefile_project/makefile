.ONESHELL:
SHELL := /bin/bash

SOURCE_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(patsubst %.cpp, %.o, $(SOURCE_FILES))
file1 = "test/goutput.txt"
file2 = "test_run/output.txt" 

bin/main: $(OBJ_FILES)
	@mkdir -p bin
	@mkdir -p test_run
	g++ -g $^ -o $@

release: $(OBJ_FILES)
	@mkdir -p bin
	@mkdir -p test_run
	g++ -O3 -g $^ -o bin/$@

$(OBJ_FILES): $(SOURCE_FILES)
	g++ -c $^ -o $@

.PHONY: test release	

test: 
	@if diff -q $(file1) $(file2); then
		@echo "PASSED"
	@else
		@echo "FAILED";
	@fi

clean: 
	rm -R bin test_run
