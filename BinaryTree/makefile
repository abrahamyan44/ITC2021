EXE := main
SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp,obj/%.o,$(SRCS))
DEP := $(patsubst %.cpp,%.dep,$(SRCS))

.PHONY: clean

$(EXE): $(OBJS)
	g++ -g $^ -o $@

obj/%.o: %.cpp #%.hpp
	mkdir -p obj
	g++ -g -c $< -o $@

#%.dep: %.cpp %.hpp
#	g++ -M $^ -o $@

clean:
	@rm -rf $(EXE) $(OBJS) $(DEP) *.o obj

#-include $(DEP)
