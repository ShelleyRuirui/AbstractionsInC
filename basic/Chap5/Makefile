all:Hanio permutation testGraph mondrian

Hanio:Hanio.c
	gcc Hanio.c -o Hanio

permutation:permutation.c
	gcc permutation.c -o permutation

testGraph:testGraph.o graphics.o exception.o genlib.o
	gcc testGraph.o graphics.o exception.o genlib.o -o testGraph -lm

testGraph.o:testGraph.c
	gcc -c testGraph.c

mondrian:mondrian.o genlib.o random.o graphics.o exception.o
	gcc mondrian.o genlib.o random.o graphics.o exception.o -o mondrian -lm

mondrian.o:mondrian.c 
	gcc -c mondrian.c

clean:
	rm *.o
