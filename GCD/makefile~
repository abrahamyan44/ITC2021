EXE := out
CC := g++
BUILD_DIR ?=bin
SOURCE_DIR ?=src
MKDIR ?=@mkdir -p

SOURCE :=$(wildcard $(SOURCE_DIR)/*.cpp)
OBJ :=$(patsubst $(SOURCE_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCE))

.PHONY : clean create_bin release test diff

SHELL:=/bin/bash
.ONESHELL:

$(BUILD_DIR)/$(EXE) : $(OBJ)
	$(CC) $^ -o $@

$(BUILD_DIR)/%.o : $(SOURCE_DIR)/%.cpp 
	$(MKDIR) $(BUILD_DIR)
	$(CC) -c $^ -o $@

create_bin :
	$(MKDIR) $(BUILD_DIR)

debug :
	"-g" && $(MAKE)
	gdb $(BUILD_DIR)/$(EXE)

release :
	$(MAKE) -o3

	
test :
	@$(MAKE)	
	$(MKDIR) test_run
	@cp -r tst test_run
	@cp -r bin test_run
	@if diff -q ./tst/output.txt ./tst/goutput.txt
	@then
	echo "PASSED"
	@else
	echo "FAILED"
	@fi

diff :
	@diff ./tst/output.txt ./tst/goutput.txt &> error
	@cat error

clean :
	@rm -rdf $(BUILD_DIR) error test_run 
