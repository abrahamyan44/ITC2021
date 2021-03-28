all: release 
.PHONY: create_bin bin/out test
SHELL :=/bin/bash
.ONESHELL :

create_bin:
		@echo "bin directory was created"
		@mkdir -p bin

release:
		@make -s create_bin
		@g++ ./src/gcd.cpp -o bin/out	

debug: 
		@g++  ./src/gcd.cpp -g -o bin/g_out
		@gdb ./bin/g_out


test:
		@make -s  release
		@mkdir -p test_run
		@cp tst/* test_run
		@if  diff -q  ./test_run/output.txt ./test_run/goutput.txt; then
		@echo "PASSED"
		@else 
		@echo "FAILED"
		@fi

clean:
		@echo "g_out, test_run, bin files and directories are deleted"	
		@rm -rf  g_out test_run bin
