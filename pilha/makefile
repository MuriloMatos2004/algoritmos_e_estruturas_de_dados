all: pilha.o usa_pilha.o
	gcc pilha.o usa_pilha.o -o usa_pilha -std=c99 -Wall

pilha.o:
	gcc -c pilha.c -o pilha.o

usa_pilha:
	gcc -c usa_pilha.c -o usa_pilha.c

clean:
	rm *.o usa_pilha
run:
	./usa_pilha