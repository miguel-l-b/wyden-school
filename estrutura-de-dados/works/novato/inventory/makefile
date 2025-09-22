all: inventory

inventory: main.o inventory.o
	gcc main.o inventory.o -o inventory

main.o: main.c inventory.h
	gcc -c main.c

inventory.o: inventory.c inventory.h
	gcc -c inventory.c

clean:
	rm -f *.o inventory