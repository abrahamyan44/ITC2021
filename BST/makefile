.PHONY: clean

bin/main: main.o BST.o
	@echo "Your program compiled sucsesfully!"
	@mkdir -p bin
	@g++ -g $^ -o $@

main.o: main.cpp
	@g++ -c $^ -o $@

BST.o: BST.cpp
	@g++ -c $^ -o $@

clean:
	@echo "All generated files are deleted"	
	@rm -R *.o bin/
