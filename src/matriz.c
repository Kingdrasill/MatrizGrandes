#include "matriz.h"

void createMatriz(Matriz *M, int c, int l, bool tipo) {
    M->c = c;
    M->l = l;
    M->tipo = tipo;
    if(tipo) { 
        M->mi = malloc(l * sizeof(int*));

        for(int i=0; i<l; i++) {
            M->mi[i] = malloc(c *sizeof(int));
        }
    } else {
        M->mf = malloc(l * sizeof(float*));

        for(int i=0; i<l; i++) {
            M->mf[i] = malloc(c *sizeof(float));
        }
    }
}

void printMatriz(Matriz *M, bool tipo) {
    if(tipo) {
        for(int i=0; i<M->l; i++) {
            for(int j=0; j<M->c; j++) {
                printf("%d\t", M->mi[i][j]);
            }
            printf("\n");
        }
    } else {
        for(int i=0; i<M->l; i++) {
            for(int j=0; j<M->c; j++) {
                printf("%f\t", M->mf[i][j]);
            }
            printf("\n");
        }
    }
}

Matriz createTransposta(Matriz *M, bool tipo) {
    Matriz MT;

    createMatriz(&MT, M->l, M->c, tipo);
    
    if(tipo) {
        for(int i=0; i<M->l; i++) {
            for(int j=0; j<M->c; j++) {
                MT.mi[j][i] = M->mi[i][j];
            }
        }
    } else {
        for(int i=0; i<M->l; i++) {
            for(int j=0; j<M->c; j++) {
                MT.mf[j][i] = M->mf[i][j];
            }
        }
    }
    
    return MT;
}

Matriz multiplyMatriz(Matriz *M, bool tipo) {
    Matriz Result, MT;
    int somaprodi = 0;
    float somaprodf = 0;

    MT = createTransposta(M, tipo);

    createMatriz(&Result, MT.c, M->l, tipo);

    if(tipo) {
        for(int i=0; i<Result.l; i++) {
            for(int j=0; j<Result.c; j++){
                somaprodi = 0;
                for(int n=0; n<M->c; n++) {
                    somaprodi += M->mi[i][n] * MT.mi[n][j];
                }
                Result.mi[i][j] = somaprodi;
            }
        }
    } else {
        for(int i=0; i<Result.l; i++) {
            for(int j=0; j<Result.c; j++){
                somaprodf = 0;
                for(int n=0; n<M->c; n++) {
                    somaprodf += M->mf[i][n] * MT.mf[n][j];
                }
                Result.mf[i][j] = somaprodf;
            }
        }
    }

    return Result;
}

Matriz getMatrizFromFile(char arquivo[MAX_FILE], Ponto p1, Ponto p2, int coluna, bool tipo) {
    FILE *fp;
    Matriz M;
    int numberi=0, c=0, l=0, i=0, j=0, espacamento;
    float numberf=0;

    c = p2.x - p1.x + 1;
    l = p2.y - p1.y + 1;

    createMatriz(&M, c, l, tipo);

    if(tipo)
        espacamento = 3;
    else
        espacamento = 10;

    fp = fopen(arquivo, "r");
    if (fp == NULL) {
        printf("\nErro!Nao foi possivel abrir o arquivo!");
        return M;
    } else {
        if(tipo) {
            fseek(fp, ((espacamento*(coluna)*(p1.y+i))+(p1.y+i) + espacamento*p1.x), SEEK_SET);
            while(i < l) {
                j = 0;
                while(j < c) {
                    fscanf(fp, "%d", &numberi);
                    M.mi[i][j] = numberi;
                    j++;
                }
                i++;
                fseek(fp, ((espacamento*(coluna)*(p1.y+i))+(p1.y+i) + espacamento*p1.x), SEEK_SET);
            }
        } else {
            fseek(fp, ((espacamento*(coluna)*(p1.y+i))+(p1.y+i) + espacamento*p1.x), SEEK_SET);
            while(i < l) {
                j = 0;
                while(j < c) {
                    fscanf(fp, "%f", &numberf);
                    M.mf[i][j] = numberf;
                    j++;
                }
                i++;
                fseek(fp, ((espacamento*(coluna)*(p1.y+i))+(p1.y+i) + espacamento*p1.x), SEEK_SET);
            }
        }
    }
    fclose(fp);

    return M;
}

bool createArquivoMatriz(char arquivo[MAX_FILE]) {
    srand( (unsigned)time(NULL) );
    FILE *fp;
    int inteiro, l, c;
    float flutuante;
    bool tipo;

    printf("Tipo de matriz:\n1 - Inteiros(0-99)\n2 - Ponto flutuantes(0.000000-99.99999)\nOpcao: ");
    scanf("%d", &inteiro);

    switch (inteiro) {
        case 1:
            tipo = true;
            break;
        case 2:
            tipo = false;
            break;
        default:
            printf("\nOpcao Invalida!");
            return false;
    }

    printf("\nQuantidade de linhas e colunas(Serao gerados numeros entre 0-99): ");
    scanf("%d %d", &l, &c);

    fp = fopen(arquivo, "w");
    if (fp == NULL) {
        printf("\nErro!Nao foi possivel abrir o arquivo!");
        return false;
    } else {
        for(int i=0; i<l; i++) {
            for(int j=0; j<c; j++) {
                if(tipo) {
                    inteiro = rand()%100;
                    if(inteiro < 10)
                        fprintf(fp, "0%d\t", inteiro);
                    else
                        fprintf(fp, "%d\t", inteiro);
                } else {
                    flutuante = rand()%100000000;
                    flutuante = flutuante/1000000;
                    if(flutuante < 10)
                        fprintf(fp, "0%f\t", flutuante);
                    else
                        fprintf(fp, "%f\t", flutuante);
                }
            }
            fprintf(fp, "\n");
        }

        printf("\nArquivo %s gerado!", arquivo);
    }
    fclose(fp);

    return true;
}

bool createArquivoCoordenadas() {
    char arquivo[MAX_FILE] = "coordenadas.txt";
    srand( (unsigned)time(NULL) );
    FILE *fp;
    int n1=-1, n2=-1, n3=-1, n4=-1, l, c, aux;
    bool cont = true;

    printf("As coordenadas serao geras aleatoriamente!\nDimensoes da matriz em que as cooredenadas sera usadas: ");
    scanf("%d %d", &l, &c);

    fp = fopen(arquivo, "w");
    if (fp == NULL) {
        printf("\nErro!Nao foi possivel abrir o arquivo!");
        return false;
    } else {
        while(cont) {
            n1 = rand()%l;
            n2 = rand()%c;
            while(n3<n1)
                n3 = rand()%l;
            while(n4<n2)
                n4 = rand()%c;
             
            fprintf(fp, "%d,%d,%d,%d\n", n1, n2, n3, n4);
            printf("\n%d,%d,%d,%d foi adicionada no arquivo, continuar: 1 - Sim 2 - Nao ", n1, n2, n3, n4);
            scanf("%d", &aux);
            if(aux == 2) {
                cont = false;
            }
        }

        printf("\nArquivo %s gerado!\n", arquivo);
    }
    fclose(fp);

    return true;
}