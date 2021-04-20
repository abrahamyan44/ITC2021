EXE := benchmark
CC := g++

$(EXE) : *.cpp
	$(CC) $^ -o $@

SHELL:=/bin/bash
.ONESHELL:


test:
	@$(MAKE)
	@echo "Enter size of array"
	@read size
	@echo "Enter test count"
	@read test_count
	@./$(EXE) $$size $$test_count

.PHONY: clean test

clean:
	@rm -rf $(EXE)




