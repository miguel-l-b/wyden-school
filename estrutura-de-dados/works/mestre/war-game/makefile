all: war-game

war-game: main.o territory.o mission.o
	gcc main.o territory.o mission.o -o war-game

main.o: main.c territory.h mission.h
	gcc -c main.c

territory.o: territory.c territory.h
	gcc -c territory.c

mission.o: mission.c mission.h territory.h
	gcc -c mission.c

clean:
	rm -f *.o war-game
