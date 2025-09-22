all: detective-quest-app

detective-quest-app: main.o mansion.o
	gcc main.o mansion.o -o detective-quest-app

main.o: main.c mansion.h
	gcc -c main.c

mansion.o: mansion.c mansion.h
	gcc -c mansion.c

clean:
	rm -f *.o detective-quest-app
