CFLAGS = -w -g

double_circular: Double_Circular_Main.o double_circular_queue.o
	gcc $(CFLAGS) -o double_circular.exe Double_Circular_Main.o double_circular_queue.o

Double_Circular_Main.o: Double_Circular_Main.c double_circular_queue.h
	gcc $(CFLAGS) -c Double_Circular_Main.c

double_circular_queue.o: double_circular_queue.c double_circular_queue.h
	gcc $(CFLAGS) -c double_circular_queue.c