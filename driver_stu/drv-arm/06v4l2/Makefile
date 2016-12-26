src := $(shell ls *.c)
elf := $(patsubst %.c, %, $(src))

LDFLAGS := -ljpeg

%: %.c
	gcc -o $@ $< $(LDFLAGS)

clean:
	rm -f $(elf)

