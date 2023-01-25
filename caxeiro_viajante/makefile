all: melhor_caminho.o matriz.o main.o
	gcc melhor_caminho.o matriz.o main.o -o pcv -std=c99 -Wall

melhor_caminho.o:
	gcc -c melhor_caminho.c -o melhor_caminho.o

matriz.o:
	gcc -c matriz.c -o matriz.o
	 
main.o:
	gcc -c main.c -o main.o
	 
clean:
	rm *.o pcv

run:
	./pcv