all:craps testString PigLatin

craps:genlib.o random.o exception.o craps.o
	gcc genlib.o random.o craps.o exception.o -o craps

craps.o:craps.c
	gcc -c craps.c

testString:testString.c
	gcc testString.c -o testString

PigLatin:PigLatin.c
	gcc PigLatin.c -o PigLatin

clean:
	rm *.o
