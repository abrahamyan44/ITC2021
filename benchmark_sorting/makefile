out: BenchmarkImplementation.cpp
	@g++ $^ -o $@

.ONESHELL:
run:
	@make -s;
	@read -p "Please, input size of the array, which should be sorted: " size;
	@echo "Now choose which type of elements should be in an array."
	@echo "(By default your elements will be integers. 
	1.If you want to work with characters input 'char'. 
	2.If you want to work with floating-point numbers, please, input 'double'. 
	3.And finally, for 'long long numbers', please, input 'long'.):"
	@read type;
	@./out $$size $$type;

clean:
	@rm -rf out
