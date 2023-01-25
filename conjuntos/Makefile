all: item.o set.o main.o
	gcc -g item.o set.o main.o -o main -std=c99 -Wall

item.o:
	gcc -g -c item.c -o item.o

set.o:
	gcc -g -c set.c -o set.o
	 
main.o:
	gcc -g -c main.c -o main.o
	 
clean:
	rm *.o main

run:
	./main