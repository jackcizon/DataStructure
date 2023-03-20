CFLAGS = -w -g

vector: Vector_Main.o vector.o
	gcc $(CFLAGS) -o vector Vector_Main.o vector.o

Vector_Main.o: Vector_Main.c vector.h
	gcc $(CFLAGS) -c Vector_Main.c

vector.o: vector.c vector.h
	gcc $(CFLAGS) -c vector.c

	