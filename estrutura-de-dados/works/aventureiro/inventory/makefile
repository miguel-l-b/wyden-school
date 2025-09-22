all: inventory

inventory: main.o vector.o list.o
	gcc main.o vector.o list.o -o inventory

main.o: main.c vector.h list.h
	gcc -c main.c

vector.o: vector.c vector.h
	gcc -c vector.c

list.o: list.c list.h
	gcc -c list.c

clean:
	rm -f *.o inventory
