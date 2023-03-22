CFLAGS = -w -g

CC = gcc 

EXECUTABLE = DoubleCircular

OBJECTS = Double_Circular_Main.o double_circular_linked_list.o

ALL = $(OBJECTS) $(EXECUTABLE).exe


$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ 
	@echo "generate $@ success."

%.o: %.c
	$(CC) $(CFLAGS) -c $<
	@echo "compile $@ success"

clean:
	del -f $(ALL)
	@echo "del '$(ALL)' success."
