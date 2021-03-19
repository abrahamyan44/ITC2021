
subdirs := src/gcd src/main

all: $(subdirs)

.PHONY: clean all $(subdirs)

$(subdirs):
	@mkdir -p objc
	$(MAKE) -C $@
	
src/main: src/gcd

clean: 
	rm -rf *.o bin/main objc 
