all: io powertab calcPiLeibForm calcPiFromArea

io:exception.o genlib.o simpio.o io.o
	gcc exception.o genlib.o simpio.o io.o -o io

io.o:io.c
	gcc -c io.c

powertab:exception.o genlib.o simpio.o powertab.o
	gcc exception.o genlib.o simpio.o powertab.o -o powertab

powertab.o:powertab.c
	gcc -c powertab.c

calcPiLeibForm:calcPiLeibForm.c
	gcc calcPiLeibForm.c -o calcPiLeibForm

calcPiFromArea:calcPiFromArea.c
	gcc calcPiFromArea.c -lm -L/lib -L/usr/lib -o calcPiFromArea

clean:
	rm io *.o
