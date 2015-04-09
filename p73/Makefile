CC = gcc
OBJS = linked_list.o linked_list_test.o
EXE = test.out

test: $(EXE)
	@./$(EXE)

$(EXE): $(OBJS)
	$(CC) $(OBJS) -o $@

%.o: %.c
	$(CC) -c -o $@ $<

.PHONY: clean

clean:
	rm $(EXE) $(OBJS)
