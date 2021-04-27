
bin/out:src/BenchMark.cpp
	@mkdir -p bin
	@g++ $^ -o $@
	@mkdir -p bin

.ONESHELL:

run:
	@mkdir -p bin
	@make -s;
	@read -p "Please, input size of the array, which should be sorted: "  size;
	@read -p "Please, input count of sortings(count should be more or equal to 1 and less or equal to 3: "  count;
	@./bin/out $$size $$count;

help:
	@echo "Typing 'make' command , '.exe' file will be created." 
	@echo "Typing 'make run' command, '.exe' file will be created and the result will be printed. "
	@echo "Typing 'make clean' command, already created '.exe' executable file will be deleted. "
clean:
	@rm -r bin

