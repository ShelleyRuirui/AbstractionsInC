all:Hanio permutation testGraph mondrian DrawFractals drawtree

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

DrawFractals:DrawFractals.o genlib.o random.o graphics.o exception.o
	gcc DrawFractals.o genlib.o random.o graphics.o exception.o -o DrawFractals -lm

drawtree:drawtree.o genlib.o random.o graphics.o exception.o
	gcc drawtree.o genlib.o random.o graphics.o exception.o -o drawtree -lm

mondrian.o:mondrian.c 
	gcc -c mondrian.c

DrawFractals.o:DrawFractals.c
	gcc -c DrawFractals.c

drawtree.o:drawtree.c
	gcc -c drawtree.c

clean:
	rm *.o
