all: lista.o main.o
	gcc lista.o main.o -o main

lista.o:
	gcc -c lista.c -o lista.o
main.o:
	gcc -c main.c -o main.o
clean:
	rm *.o
run:
	./main