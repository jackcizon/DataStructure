CFLAGS = -w -g

single_circular: Single_Circular_Main.o single_circular_linked_list.o
	gcc $(CFLAGS) -o single_circular.exe Single_Circular_Main.o single_circular_linked_list.o

Single_Circular_Main.o: Single_Circular_Main.c single_circular_linked_list.h
	gcc $(CFLAGS) -c Single_Circular_Main.c

single_circular_linked_list.o: single_circular_linked_list.c single_circular_linked_list.h
	gcc $(CFLAGS) -c single_circular_linked_list.c