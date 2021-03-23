
TEST_FILES := $(wildcard tst/*)
COPY := cp
MKDIR := mkdir
BASH := bash

all: create_bin bin/gcd.out 
	
bin/gcd.out: src/gcd.cpp
	g++ $^ -o $@

create_bin:
	$(MKDIR) -p bin

.Phony: create_bin bin/gcd.out

debug:
	g++ -g src/gcd.cpp -o bin/gcd.out

.ONESHELL:
test:
	$(MKDIR) -p test_run
	$(COPY) $(TEST_FILES) test_run
	$(BASH) test_run/read_and_write_in_file.sh

release:
	$(MKDIR) -p bin
	g++ src/gcd.cpp -o bin/gcd.out

clean: 
	rm -rf bin
	rm -rf test_run
	rm -f *.out

