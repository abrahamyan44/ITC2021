OBJPATH := ../../obj
LIBPATH := ../../lib
SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp,$(OBJPATH)/%.o,$(SRCS))

$(LIBPATH)/libclass.so: $(OBJS)
	@g++ -shared $^ -o $@

$(OBJPATH)/%.o: %.cpp %.hpp
	@g++ -c -fPIC $< -o $@

