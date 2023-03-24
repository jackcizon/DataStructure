CFLAGS = -w -g

CC = gcc

EXECUTABLE = LineEditor

OBJECTS = Line_Editor_Main.o stack.o line_editor.o

ALL = $(OBJECTS) $(EXECUTABLE).exe


%.o: %.c 
	$(CC) $(CFLAGS) -c $<
	@echo "compile $@ success"


$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@
	@echo "generate $@ success"
	del $(OBJECTS)



clean:
	del -f $(ALL)
	@echo "del '$(ALL)' success"

	