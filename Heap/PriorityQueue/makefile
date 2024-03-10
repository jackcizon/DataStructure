CFLAGS = -w -g

CC = gcc 

EXECUTABLE = min_heap.exe

OBJECTS = Heap_Main.o min_heap.o

ALL = $(OBJECTS) $(EXECUTABLE)


$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ 
	@echo "generate $@ success."
	rm $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<
	@echo "compile $@ success"

clean:
	rm -f $(ALL)
	@echo "rm '$(ALL)' success."