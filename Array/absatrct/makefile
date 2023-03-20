CFLAGS = -w -g

abstract: Abstract_Main.o abstract.o
	gcc $(CFLAGS) -o abstract.exe Abstract_Main.o abstract.o

Abstract_Main.o: Abstract_Main.c abstract.h
	gcc $(CFLAGS) -c Abstract_Main.c 

abstract.o: abstract.c abstract.h
	gcc $(CFLAGS) -c abstract.c 