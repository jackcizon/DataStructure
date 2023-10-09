CFLAGS = -w -g

CC = gcc 

EXECUTABLE = adjlist.exe

OBJECTS = Adj_List_Main.o adjlist.o

ALL = $(OBJECTS) $(EXECUTABLE)


$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ 
	@echo "generate $@ success."
	rm $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<
	@echo "compile $@ success"

clean:
	del -f $(ALL)
	@echo "del '$(ALL)' success."