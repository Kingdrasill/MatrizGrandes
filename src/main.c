#include "hash.h"

int main() {
    HashTable H;
    char arquivo[MAX_FILE];
    int opcao;
    bool name = false;
    
    Initialize(&H, 101);

    while(true) {
        printf("\n0 - Dar/Mudar nome do arquivo\n");
        printf("1 - Criar matriz em um arquivo\n");
        printf("2 - Pegar matrizes de um arquivo\n");
        printf("3 - Criar arquivo de coordenadas\n");
        printf("4 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        printf("\n");

        switch(opcao) {
            case 0:
                printf("Nome do arquivo: ");
                scanf("%s", arquivo);
                name = true;
                break;
            case 1:
                if(name) {
                    createArquivoMatriz(arquivo);
                    printf("\n");
                } else {
                    printf("O nome do arquivo não foi dado ainda!\n");
                }
                break;
            case 2:
                if(name) {
                    readMatrizesFromFile(arquivo, &H);
                    printf("\n");
                } else {
                    printf("O nome do arquivo não foi dado ainda!\n");
                }
                break;
            case 3:
                createArquivoCoordenadas();
                break;
            case 4:
                return 0;
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }
    
    return 0;
}