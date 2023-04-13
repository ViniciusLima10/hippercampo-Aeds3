#include "./headers/encontraSequencia.h"

int maiorSequencia(Triangulo *T){
    int max = 0, count;
    Triangulo aux;
    for(int i = 0; i < INPUTSIZE; i++){
        aux = T[i];
        count = 1;
        for(int j = i + 1; j < INPUTSIZE; j++){
            if(trianguloEstaDentroDoTriangulo(aux, T[j])){
                aux = T[j];
                count++;
            }     
        }
        if(count > max){
            max = count;
        }
    }
    return max;
}