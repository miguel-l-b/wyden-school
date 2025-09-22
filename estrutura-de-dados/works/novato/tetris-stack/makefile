all: tetris_stack

tetris_stack: main.o queue.o
	gcc main.o queue.o -o tetris_stack

main.o: main.c queue.h
	gcc -c main.c

queue.o: queue.c queue.h
	gcc -c queue.c

clean:
	rm -f *.o tetris_stack
