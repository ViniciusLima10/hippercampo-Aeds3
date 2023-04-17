#ifndef __MANIPULAARQUIVOS__
#define __MANIPULAARQUIVOS__
#include "triangulos.h"

void inputFile(char *fileName, Ponto **P, Ancora *ancora);

void outputFile(char *fileName, int maiorSequencia);

void inputOutputFlags(int argc, char * argv[],  Ponto **P, Ancora *ancora, char **outputFileName);



#endif