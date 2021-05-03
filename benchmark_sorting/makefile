out:
	@make -s objs;
	@mkdir -p bin;
	@g++  -o bin/main objs/* -L. lib/*;

objs:
	@mkdir -p objs;
	@g++ -c src/*.cpp
	@mv *.o objs/

.ONESHELL:
run:
	@make -s out;
	@read -p "Input size of the array, which should be sorted: " size;
	@read -p "Input count of tests (limited by 3): " test_count;
	@bin/main $$size $$test_count;

clean:
	@rm -rf bin objs
