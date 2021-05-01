

all : benchmark

sorting.o : sorting.hpp
	gcc -Wall -fPIC -c $^ -o $@

libsort.so : sorting.o
	g++ -shared -Wl,-soname,$^ -o $@

benchmark : libsort.so
	g++ -I. -L. libsort.so *.cpp -o $@


.PHONY : clean

clean :
	rm -f benchmark *.o *.so


