all: detective_quest

detective_quest: main.o mansion.o
	gcc main.o mansion.o -o detective_quest

main.o: main.c mansion.h
	gcc -c main.c

mansion.o: mansion.c mansion.h
	gcc -c mansion.c

clean:
	rm -f *.o detective_quest
