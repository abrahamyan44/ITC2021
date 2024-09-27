out:
	@make -s clean
	@make -s objs;
	@mkdir -p bin;
	@g++  -o bin/main objs/* -L. lib/*.so -l sqlite3;

objs:
	@mkdir -p objs;
	@g++ -c src/*.cpp
	@mv *.o objs/
	@g++ -shared -fPIC lib/Artaxiad.cpp -o lib/Artaxiad.so
	@g++ -shared -fPIC lib/Arshakid.cpp -o lib/Arshakid.so
	@g++ -shared -fPIC lib/Bagratid.cpp -o lib/Bagratid.so
	@g++ -shared -fPIC lib/Rubenid.cpp -o lib/Rubenid.so

.ONESHELL:
run:
	@make -s out;
	@read -p "Input size of the array, which should be sorted: " size;
	@read -p "Input count of tests (limited by 3): " test_count;
	@bin/main $$size $$test_count;

clean:
	@rm -rf bin objs lib/*.so database/*
