all:maze nim tictac

maze:maze.o genlib.o exception.o
	gcc maze.o genlib.o exception.o -o maze

maze.o:maze.c
	gcc -c maze.c

nim:nim.o genlib.o exception.o strlib.o simpio.o
	gcc nim.o genlib.o exception.o strlib.o simpio.o -o nim

nim.o:nim.c
	gcc -c nim.c

tictac:tictac.o genlib.o exception.o strlib.o simpio.o
	gcc tictac.o genlib.o exception.o strlib.o simpio.o -o tictac
	
tictac.o:tictac.c
	gcc -c tictac.c
	
clean:
	rm *.o
