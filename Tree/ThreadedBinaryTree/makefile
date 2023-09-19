CFLAGS = -Wall -g

CC = gcc

EXECUTABLE = main.exe

OBJECTS = ThrBTree.o ThrBTree_Main.o

ALL = $(OBJECTS) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@
	@echo "generate $@ success."
	rm $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<
	@echo "compile $@ success."

clean:
	rm -f $(ALL)
	@echo "rm '$(ALL)' success."
