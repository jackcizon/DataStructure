CFLAGS = -w -g

array: Array_Main.o array.o
	gcc $(CFLAGS) -o array Array_Main.o array.o

Array_Main.o: Array_Main.c array.h
	gcc $(CFLAGS) -c Array_Main.c

array.o: array.c array.h
	gcc $(CFLAGS) -c array.c