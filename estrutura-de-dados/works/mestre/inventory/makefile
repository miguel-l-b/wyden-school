all: inventory-app

inventory-app: main.o sort.o
	gcc main.o sort.o -o inventory-app

main.o: main.c sort.h component.h
	gcc -c main.c

sort.o: sort.c sort.h component.h
	gcc -c sort.c

clean:
	rm -f *.o inventory-app
