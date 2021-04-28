out:
	@make -s objs;
	@mkdir -p bin;
	@g++ objs/* -o bin/out;

objs:
	@mkdir -p objs;
	@g++ -c src/BenchmarkImplementation.cpp -o objs/main.o

.ONESHELL:
run:
	@make -s out;
	@read -p "Input size of the array, which should be sorted: " size;
	@echo "Choose type of elements."
	@echo "1.For characters input char."
	@echo "2.For float: double."
	@echo "3.For long long: long."
	@echo "4.In case of other inputs: int:"
	@read type;
	@bin/out $$size $$type;

.PHONY: bin/out

clean:
	@rm -rf bin objs