
TEST_FILES := $(wildcard tst/*)
COPY := cp
MKDIR := mkdir
BASH := bash
RM := rm 

all: release
	
create_bin:
	@echo "bin directory was successfully created"
	@$(MKDIR) -p bin

.Phony: create_bin

debug:
	@g++ -g src/gcd.cpp -o bin/gcd.out

test:
	@make -s release
	@$(MKDIR) -p test_run
	@$(COPY) $(TEST_FILES) test_run
	@$(BASH) test_run/read_and_write_in_file.sh
	@$(RM) bin/gcd.out

release: create_bin
	@g++ src/gcd.cpp -o bin/gcd.out

clean: 
	@rm -rf bin
	@rm -rf test_run
	@echo "bin and test_run directories were deleted"

