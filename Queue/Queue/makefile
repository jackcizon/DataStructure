CFLAGS = -w -g

queue: Queue_Main.o queue.o
	gcc $(CFLAGS) -o queue.exe Queue_Main.o queue.o

Queue_Main.o: Queue_Main.c queue.h
	gcc $(CFLAGS) -c Queue_Main.c

queue.o: queue.c queue.h
	gcc $(CFLAGS) -c queue.c