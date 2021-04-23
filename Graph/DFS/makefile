EXE = soution
BINPATH = bin
OBJPATH = obj
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, $(OBJPATH)/%.o, $(SRCS))

.PHONNY: clean

$(BINPATH)/$(EXE):$(OBJS)
	@mkdir -p $(BINPATH)
	g++ $^ -o $@

$(OBJPATH)/%.o: %.cpp
	@mkdir -p obj
	g++ -c $< -o $@

clean:
	@rm -rf *.o $(BINPATH) $(OBJPATH)
