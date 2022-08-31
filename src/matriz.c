#include "matriz.h"

void createMatriz(Matriz *M, int c, int l) {
    M->c = c;
    M->l = l;
    M->m = malloc(l * sizeof(int*));

    for(int i=0; i<l; i++) {
        M->m[i] = malloc(c *sizeof(int));
    }
}

Matriz createTransposta(Matriz *M) {
    Matriz MT;

    createMatriz(&MT, M->l, M->c);
    
    for(int i=0; i<M->l; i++) {
        for(int j=0; j<M->c; j++) {
            MT.m[j][i] = M->m[i][j];
        }
    }
    
    return MT;
}

Matriz multiplyMatriz(Matriz *M, Matriz *MT) {
    Matriz Result;
    int somaprod = 0;

    createMatriz(&Result, MT->c, M->l);

    for(int i=0; i<Result.l; i++) {
        for(int j=0; j<Result.c; j++){
            somaprod = 0;
            for(int n=0; n<M->c; n++) {
                somaprod += M->m[i][n] * MT->m[n][j];
            }
            Result.m[i][j] = somaprod;
        }
    }

    return Result;
}

Matriz getMatrizFromFile(char arquivo[MAX_FILE], Ponto p1, Ponto p2, int coluna) {
    FILE *fp;
    Matriz M;
    int number=0, c=0, l=0, i=0, j=0;

    c = p2.x - p1.x + 1;
    l = p2.y - p1.y + 1;

    createMatriz(&M, c, l);

    fp = fopen(arquivo, "r");
    if (fp == NULL) {
        printf("\nErro!Nao foi possivel abrir o arquivo!");
        return M;
    } else {
        fseek(fp, ((3*(coluna)*(p1.y+i))+(p1.y+i) + 3*p1.x), SEEK_SET);
        while(i < l) {
            j = 0;
            while(j < c) {
                fscanf(fp, "%d", &number);
                M.m[i][j] = number;
                j++;
            }
            i++;
            fseek(fp, ((3*(coluna)*(p1.y+i))+(p1.y+i) + 3*p1.x), SEEK_SET);
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

    printf("Tipo de arquivo:\n1 - Inteiros(0-99)\n2 - Ponto flutuantes(0.000000-99.99999)\nOpcao: ");
    scanf("%d", &inteiro);

    switch (inteiro) {
        case 1:
            tipo = true;
            break;
        case 2:
            tipo = false;
            break;
        default:
            printf("\nOpcao Invalida!\n");
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

bool createArquivoCoordenadas(char arquivo[MAX_FILE]) {
    srand( (unsigned)time(NULL) );
    FILE *fp;
    int n1=-1, n2=-1, n3=-1, n4=-1, l, c, aux;
    bool cont = true;

    printf("As coordenadas serao geras aleatoriamente!\nTamanho da matriz no arquivo: ");
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

        printf("\nArquivo %s gerado!", arquivo);
    }
    fclose(fp);

    return true;
}