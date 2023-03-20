single: Single_Main.o single_linked_list.o
	gcc -w -o single.exe Single_Main.o single_linked_list.o

Single_Main.o: Single_Main.c single_linked_list.h
	gcc -w -c Single_Main.c

single_linked_list.o: single_linked_list.c single_linked_list.h
	gcc -w -c single_linked_list.c