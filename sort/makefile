EXE := benchmark
CC := g++

$(EXE) : main.cpp
	$(CC) $^ -o $@

SHELL:=/bin/bash
.ONESHELL:


test:
	@$(MAKE)
	@echo "Enter size of array"
	@read size
	@echo "Enter test count"
	@read test_count
	#@chmod a+x $(EXE) 
	@./$(EXE) $$size $$test_count

.PHONY: clean

clean:
	@rm -rf $(EXE)




