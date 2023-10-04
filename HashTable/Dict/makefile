CFLAGS = -Wall -g

CC = gcc 

EXECUTABLE = dict_main.exe

OBJECTS = dict_main.o dict.o

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