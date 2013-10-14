all:enum quadeq gymjudge testRecord dynamicAlloc

enum:enum.c
	gcc enum.c -o enum

quadeq:exception.o genlib.o simpio.o quadeq.o
	gcc exception.o genlib.o simpio.o quadeq.o -lm -L/lib -L/usr/lib -o quadeq

quadeq.o:quadeq.c
	gcc -c quadeq.c

gymjudge:exception.o genlib.o simpio.o gymjudge.o
	gcc exception.o genlib.o simpio.o gymjudge.o -o gymjudge

gymjudge.o:gymjudge.c
	gcc -c gymjudge.c

testRecord:testRecord.c
	gcc testRecord.c -o testRecord

dynamicAlloc:dynamicAlloc.c
	gcc dynamicAlloc.c -o dynamicAlloc

clean:
	rm enum *.o
