OBJPATH := ../../obj
LIBPATH := ../../lib
HEADS := $(wildcard *.hpp)
SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp,$(OBJPATH)/%.o,$(SRCS))

$(LIBPATH)/libclass.so: $(OBJS)
	@echo "OBJ FILES --->" $(OBJS)
	g++ -shared $^ -o $@

$(OBJPATH)/%.o: %.cpp %.hpp
	@echo "CLASS --->"$<
	g++ -c -fPIC $< -o $@

