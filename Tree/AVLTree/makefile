CFLAGS = -Wall -g
# LDFLAGS = -lcunit  # Link with the CUnit library

CC = gcc

EXECUTABLE = main.exe

OBJECTS = avl_tree.o avl_tree_main.o

ALL = $(OBJECTS) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)  # Link with CUnit library
	@echo "generate $@ success."
	rm $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<
	@echo "compile $@ success"

clean:
	rm -f $(ALL)
	@echo "rm '$(ALL)' success."
