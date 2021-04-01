.ONESHELL:
SHELL := /bin/bash

SRC := $(wildcard src/*.cpp)
BINPATH := bin
FILEPATH := tst
TESTPATH := tst.run
RELEASE_EXE := bin/GCD
.DEFAULT_GOAL := bin/D_GCD
file1 := $(TESTPATH)/goutput.txt
file2 := $(TESTPATH)/output.txt


.PHONY: release test clean 

$(.DEFAULT_GOAL): $(SRC) src/GCD.hpp
	@echo "Debug compilation."
	@mkdir -p bin
	@g++ -g $^ -o $@


release: $(RELEASE_EXE)
	
$(RELEASE_EXE): $(SRC) src/GCD.hpp
	@echo "Release compilation."
	@mkdir -p bin
	@g++ $^ -o $@


test: bin/*
	@echo "GCD testing."
	@mkdir -p $(TESTPATH)
	@./bin/*
	@cp $(FILEPATH)/*output.txt $(TESTPATH)
	@if diff -c  $(file1) $(file2)
	@then
		@echo "PASSED";
	@else
		@echo "FAILED";	
	@fi


clean:
	@echo "Solution cleaning."
	@rm -rf tst/o*	$(BINPATH) $(TESTPATH)
