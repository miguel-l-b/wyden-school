all: tetris-stack

tetris-stack: main.o tetris.o
	gcc main.o tetris.o -o tetris-stack

main.o: main.c tetris.h
	gcc -c main.c

tetris.o: tetris.c tetris.h
	gcc -c tetris.c

clean:
	rm -f *.o tetris-stack
