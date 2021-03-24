.ONESHELL:
SHELL := /bin/bash

export EXE := factorial
export GCC := g++
export DEBUG_FLAG ?=

SRC := $(wildcard src/*.cpp)
OBJ := $(patsubst src/%.cpp, obj/%.o, $(SRC))
DEP := $(patsubst src/%.cpp, obj/%.dep, $(SRC)) 

bin/$(EXE) : $(OBJ)
	@mkdir -p bin
	@$(GCC) $^ -o $@

obj/%.o : src/%.cpp 
	@mkdir -p obj
	@$(GCC) $(DEBUG_FLAG) -c $< -o $@

obj/%.dep : src/%.cpp
	@mkdir -p obj
	@$(GCC) -MM $< -o $@

.PHONY : release
release :
	@export DEBUG_FLAG="-O3" && $(MAKE)	-s
	@echo "************ RELEASE VERSIOIN **********"

.PHONY : debug
debug : 
	@export DEBUG_FLAG="-g" && $(MAKE) -s	
	@echo '************  DEBUG VERSION ************'

.PHONY : test


test :
	@echo '************  TEST VERSION ************'
	@mkdir -p tst_run
	@touch tst_run/output.txt
	@cp tst/* tst_run
	$(MAKE) -s && ./bin/$(EXE) -o tst_run/output.txt 
	@	if diff -q tst_run/output.txt tst_run/goutput.txt ;
	@	then
	@		echo "PASSED"
	@	else
	@		echo "FAILED"
	@	echo "The count of different lines is $(count)"
	@	fi
export count=`diff tst_run/output.txt tst_run/goutput.txt | grep "^>" | wc -l`


.PHONY : clean
clean :
	@echo '************ DELETED ALL GENERATED FILES ************'
	@rm -r bin obj tst_run #$(OBJ) $(DEP)
	
-include $(DEP)  


