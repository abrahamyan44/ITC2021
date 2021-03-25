SUBDIRS := src/class src/main

.PHONY: all clean $(SUBDIRS)

all: $(SUBDIRS)

$(SUBDIRS): 
	@echo "Create directories."
	@mkdir -p bin obj lib
	$(MAKE) -C $@


clean:
	@rm -rf *.o bin obj lib
	@find -name "*.o" -type f -delete
