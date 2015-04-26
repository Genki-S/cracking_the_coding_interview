CC = gcc
SRCS = $(wildcard *.c)

test:
	@for f in $(SRCS); do $(CC) $$f -o a.out && ./a.out; done
