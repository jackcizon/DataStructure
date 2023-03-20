CFLAGS = -w -g

share_stack: Share_Stack_Main.o share_stack.o
	gcc $(CFLAGS) -o share_stack.exe Share_Stack_Main.o share_stack.o

Share_Stack_Main.o: Share_Stack_Main.c share_stack.h
	gcc $(CFLAGS) -c Share_Stack_Main.c

share_stack.o: share_stack.c share_stack.h
	gcc $(CFLAGS) -c share_stack.c