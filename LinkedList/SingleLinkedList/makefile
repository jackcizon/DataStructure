FLAGS = -w -g 

single: Single_Main.o single_linked_list.o
	gcc $(FLAGS) -o single.exe Single_Main.o single_linked_list.o

Single_Main.o: Single_Main.c single_linked_list.h
	gcc $(FLAGS) -c Single_Main.c

single_linked_list.o: single_linked_list.c single_linked_list.h
	gcc $(FLAGS) -c single_linked_list.c
