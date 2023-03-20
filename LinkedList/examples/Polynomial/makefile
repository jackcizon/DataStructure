CFLAGS = -W -g

Polynomial: Polynomial.o Polynomial_Main.o
	gcc $(CFLAGS) -o Polynomial Polynomial.o Polynomial_Main.o

Polynomial_Main.o: Polynomial_Main.c Polynomial.h
	gcc $(CFLAGS) -c Polynomial_Main.c

Polynomial.o: Polynomial.c Polynomial.h
	gcc $(CFLAGS) -c Polynomial.c