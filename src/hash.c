#include "hash.h"


void Initialize(HashTable *h, int M){
	h->table = (DataTable*) malloc (M * sizeof(DataTable));

	for(int i=0; i<M; i++){
		h->table[i].key = -1;
		h->table[i].p1.y = -1;
		h->table[i].p1.x = -1;
		h->table[i].p2.y = -1;
		h->table[i].p2.x = -1;
        h->table[i].tipo = -1;
	}

	h->M = M;
}

bool getValue(HashTable *h, int key, Ponto p1, Ponto p2, Matriz *M, short int tipo){
	int idx = hash(key, h->M);
	int aux = idx;
	
	while (h->table[idx].key != key || h->table[idx].tipo != tipo || h->table[idx].p1.y != p1.y || h->table[idx].p1.x != p1.x
            || h->table[idx].p2.y != p2.y || h->table[idx].p2.x != p2.x){
		idx = (idx + 1) % h->M;
		if (idx == aux){
			return false;
		}
	}

    *M = h->table[idx].M;
	return true;
}

void Insert(HashTable *h, int key, Matriz M, Ponto p1, Ponto p2, short int tipo){
	int idx = hash(key, h->M);
	int aux = idx;
	
	while (h->table[idx].key != -1){
		idx = (idx + 1) % h->M;
		if (idx == aux){
			printf("\nOPENED HASH IS FULL!\n");
			return;
		}
	}
	
	h->table[idx].key = key;
    h->table[idx].p1 = p1;
    h->table[idx].p2 = p2;
    h->table[idx].tipo = tipo;
	h->table[idx].M = M;
}

void readMatrizesFromFile(char arquivo[MAX_FILE], HashTable *H) {
    FILE *fp;
    Matriz M;
    Ponto p1, p2;
    int linha, coluna, opcao, key;
    short int i;
    bool tipo;

    printf("Tipo de matriz:\n1 - Inteiros\n2 - Ponto flutuantes\nOpcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            i = 1;
            tipo = true;
            break;
        case 2:
            i = 2;
            tipo = false;
            break;
        default:
            printf("\nOpcao invalida!");
            return;
            break;
    }

    printf("\nDimensoes da matriz: ");
    scanf("%d %d", &linha, &coluna);

    fp = fopen("coordenadas.txt", "r");
    if (fp == NULL) {
        printf("\nErro!Nao foi possivel abrir o arquivo!");
        return;
    } else {
        while (fscanf(fp, "%d,%d,%d,%d", &p1.y, &p1.x, &p2.y, &p2.x) != -1) {
            printf("\nCoordenas[l,c]: [%d,%d]-[%d,%d]\n", p1.y, p1.x, p2.y, p2.x);
            key = (p2.x-p1.x)%(p2.y-p1.y);
            if(getValue(H, key, p1, p2, &M, i)) {
                printf("\nResultado da multiplicacao da matriz pega do arquivo com sua transposta:\n\n");
                printMatriz(&M, tipo);
            } else {
                M = getMatrizFromFile(arquivo, p1, p2, coluna, tipo);
                printf("\nResultado da multiplicacao da matriz pega do arquivo com sua transposta:\n\n");
                M = multiplyMatriz(&M, tipo);
                printMatriz(&M, tipo);
                Insert(H, key, M, p1, p2, i);
            }
            printf("\nPegar outra matriz do arquivo de coordenadas: 1 - Sim 2 - Nao ");
            scanf("%d", &opcao);
            if(opcao == 2)
                break;
        }
        
    }
    fclose(fp);
}