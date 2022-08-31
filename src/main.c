#include "matriz.h"

int main() {
    char arquivo[MAX_FILE] = "coordenadas.txt";
    createArquivoCoordenadas(arquivo);
    /*bool name = false;
    int opcao;

    while(true) {
        printf("\n0 - Dar/Mudar nome do arquivo\n");
        printf("1 - Criar matriz em um arquivo\n");
        printf("2 - Pegar matrizes de um arquivo\n");
        printf("3 - Sair\n");
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
                    createArquivo(arquivo);
                    printf("\n");
                } else {
                    printf("O nome do arquivo não foi dado ainda!\n");
                }
                break;
            case 2:
                if(name) {
                    printf("\n");
                } else {
                    printf("O nome do arquivo não foi dado ainda!\n");
                }
                break;
            case 3:
                return 0;
                break;
            default:
                printf("Opcao invalida!\n\n");
                break;
        }
    }*/
    
    return 0;
}