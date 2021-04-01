EXE := main
SRCS := $(wildcard *.cpp)

.PHONY: clean

$(EXE): $(SRCS)
	@g++ $^ -o $@

clean:
	@rm -rf $(EXE)
