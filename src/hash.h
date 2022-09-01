#ifndef HASHTABLE_H 
#define HASHTABLE_H

#include "matriz.h"

#define hash(v, M) (v % M)

typedef struct DataTable DataTable;
typedef struct HashTable HashTable;


struct DataTable{
	int key;
	Ponto p1, p2;
    Matriz M;
    short int tipo;
};


struct HashTable{
	DataTable *table;
	int M;
};


void Initialize(HashTable *h, int M);
bool getValue(HashTable *h, int key, Ponto p1, Ponto p2, Matriz *M, short int tipo);
void Insert(HashTable *h, int key, Matriz M, Ponto p1, Ponto p2, short int tipo);
void readMatrizesFromFile(char arquivo[MAX_FILE], HashTable *H);

#endif