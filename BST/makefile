.PHONY: clean

bin/main: main.o BinarySearchTree.o
	@echo "Your program compiled sucsesfully!"
	@mkdir -p bin
	@g++ -g $^ -o $@

main.o: main.cpp
	@g++ -c $^ -o $@

BinarySearchTree.o: BinarySearchTree.cpp
	@g++ -c $^ -o $@

clean:
	@echo "All generated files are deleted"	
	@rm -R *.o bin/
