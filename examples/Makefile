EXAMPLES	:=	settings

.PHONY: all

all: clean
	$(foreach dir,$(EXAMPLES),$(MAKE) -C $(dir))

clean:
	$(foreach dir,$(EXAMPLES),$(MAKE) -C $(dir) clean)
