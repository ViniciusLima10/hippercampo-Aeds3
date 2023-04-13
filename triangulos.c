#include "./headers/triangulos.h"



int trianguloEstaDentroDoTriangulo(Triangulo t, Triangulo p) {//verifica se o triangulo p esta dentro do triangulo t
    if (t.a.x == p.a.x && t.a.y == p.a.y && t.b.x == p.b.x && t.b.y == p.b.y && t.c.x == p.c.x && t.c.y == p.c.y) {
        return 0;
    }
    
    float d1, d2, d3;
    int negativo = 0, positivo = 0;

    d1 = (p.c.x - t.a.x) * (t.b.y - t.a.y) - (t.b.x - t.a.x) * (p.c.y - t.a.y);
    d2 = (p.c.x - t.b.x) * (t.c.y - t.b.y) - (t.c.x - t.b.x) * (p.c.y - t.b.y);
    d3 = (p.c.x - t.c.x) * (t.a.y - t.c.y) - (t.a.x - t.c.x) * (p.c.y - t.c.y);

    if ((d1 < 0) || (d2 < 0) || (d3 < 0)) {
        negativo = 1;
    }

    if ((d1 > 0) || (d2 > 0) || (d3 > 0)) {
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

// Função de comparação para ordenar os triângulos em ordem crescente com base em T.c.y
int compararTriangulos(const void* a, const void* b) {
    Triangulo* t1 = (Triangulo*) a;
    Triangulo* t2 = (Triangulo*) b;
    if (t1->c.y > t2->c.y) return -1;
    if (t1->c.y < t2->c.y) return 1;
    return 0;
}

float areaDoTriangulo(Triangulo *T) {
    return fabs((T->a.x * (T->b.y - T->c.y) + T->b.x * (T->c.y - T->a.y) + T->c.x * (T->a.y - T->b.y)) / 2.0);
}

// Função para comparar a área de dois triângulos
int comparaArea(Triangulo *t1, Triangulo *t2) {
    float area1 = areaDoTriangulo(t1);
    float area2 = areaDoTriangulo(t2);
    if (area1 > area2) {
        return -1;
    } else if (area1 < area2) {
        return 1;
    } else {
        return 0;
    }
}
