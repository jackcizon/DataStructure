CFLAGS = -w -g

CC = gcc

EXECUTABLE = Palindrome

OBJECTS = Palindrome_Main.o stack.o palindrome.o

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

	