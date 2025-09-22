all: tetris-stack-app

tetris-stack-app: main.o queue.o
	gcc main.o queue.o -o tetris-stack-app

main.o: main.c queue.h
	gcc -c main.c

queue.o: queue.c queue.h
	gcc -c queue.c

clean:
	rm -f *.o tetris-stack-app
