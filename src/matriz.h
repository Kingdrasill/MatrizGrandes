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
    int **m;
};

void createMatriz(Matriz *M, int c, int l);
Matriz createTransposta(Matriz *M);
Matriz multiplyMatriz(Matriz *M, Matriz *MT);
Matriz getMatrizFromFile(char arquivo[MAX_FILE], Ponto p1, Ponto p2, int coluna);
bool createArquivoMatriz(char arquivo[MAX_FILE]);
bool createArquivoCoordenadas(char arquivo[MAX_FILE]);

#endif