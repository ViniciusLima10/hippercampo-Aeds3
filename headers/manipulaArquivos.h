#ifndef __MANIPULAARQUIVOS__
#define __MANIPULAARQUIVOS__
#include "triangulos.h"

void openFILE(char *fileName, Ponto **P, Ancora *ancora);

void outputFile(char *fileName, int maiorSequencia);

void ioFlags(int argc, char * argv[],  Ponto **P, Ancora *ancora, char **outputFileName);



#endif