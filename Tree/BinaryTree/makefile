CFLAGS = -w -g

CC = gcc 

EXECUTABLE = BinaryTree

OBJECTS = Binary_Tree_Main.o binary_tree.o

ALL = $(OBJECTS) $(EXECUTABLE).exe


$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ 
	@echo "generate $@ success."
	rm $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<
	@echo "compile $@ success"

clean:
	rm -f $(ALL)
	@echo "del '$(ALL)' success."