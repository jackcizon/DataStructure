FLAGS = -w -g 

Sum: Add_Main.o single_linked_list.o
	gcc $(FLAGS) -o Sum.exe Add_Main.o single_linked_list.o

Add_Main.o: Add_Main.c single_linked_list.h
	gcc $(FLAGS) -c Add_Main.c

single_linked_list.o: single_linked_list.c single_linked_list.h
	gcc $(FLAGS) -c single_linked_list.c