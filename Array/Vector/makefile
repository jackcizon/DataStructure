CFLAGS = -w -g

objects = Vector_Main.o vector.o

vector: $(objects)
	gcc $(CFLAGS) -o vector.exe $(objects)

Vector_Main.o: Vector_Main.c
	gcc $(CFLAGS) -c Vector_Main.c

vector.o: vector.c
	gcc $(CFLAGS) -c vector.c

clean:
	del vector.exe $(objects)
	#in linux, use 'rm'	
