all: inventory-app

inventory-app: main.o inventory.o
	gcc main.o inventory.o -o inventory-app

main.o: main.c inventory.h
	gcc -c main.c

inventory.o: inventory.c inventory.h
	gcc -c inventory.c

clean:
	rm -f *.o inventory-app