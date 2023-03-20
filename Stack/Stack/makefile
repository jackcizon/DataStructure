CFLAGS = -w -g

stack: Stack_Main.o stack.o
	gcc $(CFLAGS) -o stack.exe Stack_Main.o stack.o

Stack_Main.o: Stack_Main.c stack.h
	gcc $(CFLAGS) -c Stack_Main.c

stack.o: stack.c stack.h
	gcc $(CFLAGS) -c stack.c