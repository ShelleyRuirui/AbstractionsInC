all:maze

maze:maze.o genlib.o exception.o
	gcc maze.o genlib.o exception.o -o maze

maze.o:maze.c
	gcc -c maze.c

clean:
	rm *.o
