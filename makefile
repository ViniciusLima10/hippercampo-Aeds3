### MAKEFILE ###

build: all
	./a.out

clean:
	rm *.o
	rm ./a.out

all: main

main: triangulos.o manipulaArquivos.o encontraSequencia.o
	gcc -c main.c
	gcc main.o triangulos.o manipulaArquivos.o encontraSequencia.o

triangulos.o: triangulos.c
	gcc -c triangulos.c

manipulaArquivos.o: manipulaArquivos.c
	gcc -c manipulaArquivos.c

encontraSequencia.o: encontraSequencia.c
	gcc -c encontraSequencia.c

