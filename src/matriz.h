#ifndef MATRIZ_H
#define MATRIZ_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_FILE 50

typedef struct Ponto Ponto;
typedef struct Matriz Matriz;

struct Ponto {
    int x;
    int y;
};

struct Matriz {
    int c;
    int l;
    int **mi;
    float **mf;
    bool tipo;
};

void createMatriz(Matriz *M, int c, int l, bool tipo);
void printMatriz(Matriz *M, bool tipo);
Matriz createTransposta(Matriz *M, bool tipo);
Matriz multiplyMatriz(Matriz *M, bool tipo);
Matriz getMatrizFromFile(char arquivo[MAX_FILE], Ponto p1, Ponto p2, int coluna, bool tipo);
bool createArquivoMatriz(char arquivo[MAX_FILE]);
bool createArquivoCoordenadas();

#endif