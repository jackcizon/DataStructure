CFLAGS = -w -g

CC = gcc 

EXECUTABLE = Set

OBJECTS = Set_Main.o array_set.o

ALL = $(OBJECTS) $(EXECUTABLE).exe


$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ 
	@echo "generate $@ success."
	del $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<
	@echo "compile $@ success"

clean:
	del -f $(ALL)
	@echo "del '$(ALL)' success."