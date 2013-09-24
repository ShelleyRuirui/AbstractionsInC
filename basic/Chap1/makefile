all: io powertab

io:exception.o genlib.o simpio.o io.o
	gcc exception.o genlib.o simpio.o io.o -o io

io.o:io.c
	gcc -c io.c

powertab:exception.o genlib.o simpio.o powertab.o
	gcc exception.o genlib.o simpio.o powertab.o -o powertab

powertab.o:powertab.c
	gcc -c powertab.c

clean:
	rm io *.o
