#include "./headers/manipulaArquivos.h"


void openFILE(char *fileName, Ponto **P, Ancora *ancora){
    int x, y;
    FILE *file;
    file = fopen(fileName, "r");
    if(file == NULL){
        printf("Couldn't open file!\n");
        return;
    }
    fscanf(file, "%d %d %d", &INPUTSIZE, &ancora->ancoraA.x, &ancora->ancoraB.x);
    ancora->ancoraA.y = 0;
    ancora->ancoraB.y = 0;
 
    *P = malloc(INPUTSIZE * sizeof(Ponto));
    for(int i = 0; i < INPUTSIZE; i++){
        fscanf(file, "%d %d", &x, &y);
        (*P)[i].x = x;
        (*P)[i].y = y;
    }
    fclose(file);
};

void outputFile(char *fileName, int maiorSequencia) {
    FILE *arquivo; // ponteiro para arquivo
    arquivo = fopen(fileName, "w"); // abre o arquivo em modo de escrita
    
    if (arquivo == NULL) { // verifica se o arquivo foi aberto corretamente
        printf("Erro ao abrir o arquivo!");
        return;
    }
    
    fprintf(arquivo, "%d", maiorSequencia); // escreve o valor de maiorSequencia no arquivo
    fclose(arquivo); // fecha o arquivo
}

void ioFlags(int argc, char * argv[],  Ponto **P, Ancora *ancora, char **outputFileName){
    int c;
    char *filename;
    while ((c = getopt(argc, argv, ":i:o:")) != -1) {
    switch(c) {
    case 'i':
        filename = optarg;
        openFILE(filename, P, ancora);
        break;
    case 'o':
        *outputFileName = optarg;
        break;
    case ':':
        printf("-%c without filename\n", optopt);
        break;
    }
}

}