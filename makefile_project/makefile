.ONESHELL:
SHELL := /bin/bash

SOURCE_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(patsubst %.cpp, %.o, $(SOURCE_FILES))
file1 = "test/goutput.txt"
file2 = "test_run/output.txt" 

bin/main: $(OBJ_FILES)
	@mkdir -p bin
	g++ -g $^ -o $@

#release: $(OBJ_FILES)
#	@mkdir -p bin
#	g++ -O3 -g $^ -o bin/$@

#test_run:
#	@mkdir -p $@

OBJ_FILES: $(SOURCE_FILES)
	g++ -c $^ -o $@

.PHONY: test test_run release	
test_run:
	@mkdir -p $@

test: 
	@if diff -q $(file1) $(file2); then
		@echo "PASSED"
	@else
		@echo "FAILED";
	@fi

clean: 
	rm -R bin test_run
