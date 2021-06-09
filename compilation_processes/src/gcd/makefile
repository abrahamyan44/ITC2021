../../lib/libtest.so : ../../objc/gcd.o
	gcc -g --shared $^ -o $@

../../objc/gcd.o : gcd.cpp
	gcc -fPIC -c $^ -o $@
