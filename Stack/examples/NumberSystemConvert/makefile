CFLAGS = -w -g

CC = gcc

EXECUTABLE = Convert

OBJECTS = Number_System_Convert_Main.o stack.o convert.o

ALL = $(OBJECTS) $(EXECUTABLE).exe


$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@
	@echo "generate $@ success"
	del $(OBJECTS)

%.o: %.c 
	$(CC) $(CFLAGS) -c $<
	@echo "compile $@ success"



clean:
	del -f $(ALL)
	@echo "del '$(ALL)' success"

	