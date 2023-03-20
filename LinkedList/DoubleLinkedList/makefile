CFLAGS = -w -g

double: Double_Main.o double_linked_list.o
	gcc $(CFLAGS) -o double.exe Double_Main.o double_linked_list.o

Double_Main.o: Double_Main.c double_linked_list.h
	gcc $(CFLAGS) -c Double_Main.c

double_linked_list.o: double_linked_list.c double_linked_list.h
	gcc $(CFLAGS) -c double_linked_list.c

	