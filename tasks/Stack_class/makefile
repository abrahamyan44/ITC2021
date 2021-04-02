
all:clean create_bin bin/stack.o bin/main.o bin/out gen

create_bin:
	@mkdir -p bin

bin/out:bin/main.o bin/stack.o
	@g++ $^ -o $@

bin/stack.o: src/stack.cpp
	@g++ -c $^ -o $@

bin/main.o: src/main.cpp
	@g++ -c $^ -o $@


gen:
	@./bin/out
clean:
		@rm -rf ./bin
