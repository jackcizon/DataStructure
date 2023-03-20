CFLAGS = -w -g

single_circular: Single_Circular_Main.o single_circular_queue.o
	gcc $(CFLAGS) -o single_circular.exe Single_Circular_Main.o single_circular_queue.o

Single_Circular_Main.o: Single_Circular_Main.c single_circular_queue.h
	gcc $(CFLAGS) -c Single_Circular_Main.c

single_circular_queue.o: single_circular_queue.c single_circular_queue.h
	gcc $(CFLAGS) -c single_circular_queue.c