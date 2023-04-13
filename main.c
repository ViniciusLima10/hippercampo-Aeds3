#include "./headers/triangulos.h"
#include <sys/resource.h>
#include <sys/time.h>

int main(int argc, char *argv[]){
    Ponto *P;
    Ancora ancora;
    Triangulo *T;
    char *outputFileName;
    int intMaiorSequencia;
    double diff;
    struct rusage usage;
    struct timeval start, end;


    ioFlags(argc, argv, &P, &ancora, &outputFileName);

    criarTriangulos(&P, &ancora, &T);
    qsort(T, INPUTSIZE, sizeof(Triangulo), compararTriangulos);
    getrusage(RUSAGE_SELF, &usage);

    gettimeofday(&start, NULL);
    intMaiorSequencia = maiorSequencia(T); 
    gettimeofday(&end, NULL);
    diff = (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_usec - start.tv_usec) / 1000000.0;

    printf("===== Maior Sequencia ====\n");
    printf("%d\n", intMaiorSequencia);
    printf("==========================\n");

    
    printf("Tempo de CPU usado: %ld.%06ld segundos\n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
    printf("Tempo de CPU do sistema usado: %ld.%06ld segundos\n", usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
    printf("Máximo uso de memória residente: %ld kilobytes\n", usage.ru_maxrss);
    printf("Tempo de execucao do algoritmo de encontrar a maior sequencia: %f segundos\n", diff);
    free(P);
    free(T);

    outputFile(outputFileName, intMaiorSequencia);  
    return 0;
}