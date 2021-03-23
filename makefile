

.PHONY: debug release test clean

debug: bin/GCD.debug
bin/GCD.debug: src/*.cpp
	@mkdir -p bin
	@g++ -g $< -o $@

release:bin/GCD

bin/GCD:src/GCD.cpp
	@mkdir -p bin
	@g++ $< -o $@
test:release
	@mkdir -p tst.run
	@./bin/GCD test tst/input.txt
	@echo >> tst.run/output.txt
	@grep -Eo '[0-9\.]+' tst/goutput.txt > tst.run/result.txt
	@echo "" >> tst.run/result.txt
	@bash src/cmp.sh

       			
clean:
	@rm -rf bin tst.run
