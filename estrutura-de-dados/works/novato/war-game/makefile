all: war-game-app

war-game-app: main.o territory.o
	gcc main.o territory.o -o war-game-app

main.o: main.c territory.h
	gcc -c main.c

territory.o: territory.c territory.h
	gcc -c territory.c

clean:
	rm -f *.o war-game-app