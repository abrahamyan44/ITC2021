

all : benchmark

sorting.o : sorting.hpp
	gcc -Wall -fPIC -c $^ -o $@

libsorting.so : sorting.o
	gcc -shared -Wl,-soname,$^ -o $@

benchmark : libsorting.so 
	g++ -I. -L. libsorting.so main.cpp -o $@

.PHONY : clean

clean :
	rm -f benchmark *.o *.so


