
all:clean create_bin bin/vector.o bin/main.o bin/out gen

create_bin:
	@mkdir -p bin

bin/out:bin/main.o bin/vector.o
	@g++ $^ -o $@

bin/main.o: src/main.cpp
	@g++ -c $^ -o $@

bin/vector.o: src/vector.cpp
	@g++ -c $^ -o $@

gen:
	@./bin/out
clean:
		@rm -rf ./bin
