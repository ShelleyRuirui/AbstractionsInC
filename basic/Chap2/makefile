all:enum quadeq

enum:enum.c
	gcc enum.c -o enum

quadeq:exception.o genlib.o simpio.o quadeq.o
	gcc exception.o genlib.o simpio.o quadeq.o -lm -L/lib -L/usr/lib -o quadeq

quadeq.o:quadeq.c
	gcc -c quadeq.c

clean:
	rm enum *.o
