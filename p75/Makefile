CC = gcc
LIBS = quicksort.c
SRCS = $(wildcard 1_*.c)

test:
	@for f in $(SRCS); do $(CC) $$f $(LIBS) -o a.out && ./a.out; done
