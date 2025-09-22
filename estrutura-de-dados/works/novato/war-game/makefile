all: territory

territory: main.o territory.o
	gcc main.o territory.o -o territory

main.o: main.c territory.h
	gcc -c main.c

territory.o: territory.c territory.h
	gcc -c territory.c

clean:
	rm -f *.o territory