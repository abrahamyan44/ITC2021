EXE := main
OBJPATH := ../../obj
BINPATH := ../../bin
SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp,%.o,$(SRCS))
OBJECTS := $(wildcard ../../obj/*.o)


$(BINPATH)/$(EXE): $(OBJECTS) $(OBJPATH)/$(OBJS)
	@g++ $^ -o $@

$(OBJPATH)/$(OBJS): $(SRCS)
	@g++ -c  $^ -o $@

