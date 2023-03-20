CFLAGS = -w -g

double_circular: Double_Circular_Main.o double_circular_linked_list.o
	gcc $(CFLAGS) -o double_circular.exe Double_Circular_Main.o double_circular_linked_list.o

Double_Circular_Main.o: Double_Circular_Main.c double_circular_linked_list.h
	gcc $(CFLAGS) -c Double_Circular_Main.c

double_circular_linked_list.o: double_circular_linked_list.c double_circular_linked_list.h
	gcc $(CFLAGS) -c double_circular_linked_list.c