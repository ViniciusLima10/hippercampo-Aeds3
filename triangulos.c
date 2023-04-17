#include "./headers/triangulos.h"



int trianguloEstaDentroDoTriangulo(Triangulo t, Triangulo p) {//verifica se o triangulo p esta dentro do triangulo t
    if (t.a.x == p.a.x && t.a.y == p.a.y && t.b.x == p.b.x && t.b.y == p.b.y && t.c.x == p.c.x && t.c.y == p.c.y) {
        return 0;
    }
    
    float l1, l2, l3;
    int negativo = 0, positivo = 0;

    l1 = (p.c.x - t.a.x) * (t.b.y - t.a.y) - (t.b.x - t.a.x) * (p.c.y - t.a.y);
    l2 = (p.c.x - t.b.x) * (t.c.y - t.b.y) - (t.c.x - t.b.x) * (p.c.y - t.b.y);
    l3 = (p.c.x - t.c.x) * (t.a.y - t.c.y) - (t.a.x - t.c.x) * (p.c.y - t.c.y);

    if ((l1 < 0) || (l2 < 0) || (l3 < 0)) {
        negativo = 1;
    }

    if ((l1 > 0) || (l2 > 0) || (l3 > 0)) {
        positivo = 1;
    }

    if (negativo && positivo) {
        return 0;
    } else {
        return 1;
    }
}



void criarTriangulos(Ponto **P, Ancora *ancora, Triangulo **T) {
    *T = malloc(INPUTSIZE * sizeof(Triangulo));
    (*T)[0].a = ancora->ancoraA;
    (*T)[0].b = ancora->ancoraB;
    (*T)[0].c = (*P)[0];
    for (int i = 1; i < INPUTSIZE; i++) {
        (*T)[i].a = (*T)[0].a;
        (*T)[i].b = (*T)[0].b;
        (*T)[i].c = (*P)[i];
        (*T)->length++;
    }

}


int compararTriangulos(const Triangulo* t1, const Triangulo* t2) {
    
    if (t1->c.y > t2->c.y){
        return -1;
    } else if (t1->c.y < t2->c.y){
        return 1;
    }
    
    return 0;
}

