all :clean create_bin   bin/out

create_bin :
		@mkdir -p bin

bin/out : bin/tree.o bin/main.o
	@g++ $^ -o $@
	@./$@

bin/%.o : src/%.cpp
	@g++ -c  $^  -o $@

clean:
	@rm -rf out *.o bin
