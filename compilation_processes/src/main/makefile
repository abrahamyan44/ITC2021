
SOURCES := $(wildcard ../../src/*/*.cpp)
OBJS := $(patsubst %.c, %.o, $(SOURCES))

main: $(OBJS)
	@gcc $^ -I../../src/gcd /usr/lib/gcc/x86_64-linux-gnu/5/libstdc++.a -o $@

main.o : main.cpp
	@gcc -c $^ -I../../src/gcd -o $@
	@mv $@ ../../objc/

