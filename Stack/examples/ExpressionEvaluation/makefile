CFLAGS = -w -g

CC = gcc

EXECUTABLE = Expression

OBJECTS = Expression_Main.o stack.o expression.o

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

	