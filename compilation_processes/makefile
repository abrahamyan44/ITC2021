
subdirs := src/gcd src/main

all: $(subdirs)

.PHONY: clean all $(subdirs)

$(subdirs):	
	@mkdir -p objc
	@$(MAKE) -s -C $@
	@echo BUILD SUCCESSFUL
	
src/main: src/gcd

clean: 
	@rm -rf *.o main objc bin
