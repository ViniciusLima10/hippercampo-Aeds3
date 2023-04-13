#ifndef __TRIANGULOS__
#define __TRIANGULOS__
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int INPUTSIZE;

typedef struct{
    int x;
    int y;
}Ponto;

typedef struct{
    Ponto a;
    Ponto b;
    Ponto c;
    int length;

} Triangulo;

typedef struct {
    Ponto ancoraA;
    Ponto ancoraB;
}Ancora;


int trianguloEstaDentroDoTriangulo(Triangulo t, Triangulo p);

void criarTriangulos(Ponto **P, Ancora *ancora, Triangulo **T);

int compararTriangulos(const void* a, const void* b);

float areaDoTriangulo(Triangulo *T);

int comparaArea(Triangulo *t1, Triangulo *t2);


#endif