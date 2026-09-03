/*  esse exercicio foi dado na primeira aula pratrica
como teste para ver como estavamos em linguagem C,data: 14/07/26 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *nomes = NULL;
    int tamanho = 0;
    int opcao;
    char nome[50];

    do {
        printf("\n1 - Adicionar nome\n");
        printf("2 - Remover nome\n");
        printf("3 - Listar\n");
        printf("4 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        // ADICIONAR
        if (opcao == 1) {

            printf("Digite o nome: ");
            scanf("%s", nome);

            int tamNome = strlen(nome);

            if (tamanho == 0) {
                nomes = realloc(nomes, tamNome + 1);
                strcpy(nomes, nome);
                tamanho = tamNome;
            } 
            else {
                nomes = realloc(nomes, tamanho + tamNome + 2);

                strcat(nomes, " ");
                strcat(nomes, nome);

                tamanho = tamanho + tamNome + 1;
            }
        }

        // REMOVER
        else if (opcao == 2) {

            printf("Digite o nome para remover: ");
            scanf("%s", nome);

            char *pos = strstr(nomes, nome);

            if (pos != NULL) {

                int tamNome = strlen(nome);

                memmove(pos, pos + tamNome, strlen(pos + tamNome) + 1);

                tamanho = tamanho - tamNome;

                nomes = realloc(nomes, tamanho + 1);

                printf("Nome removido!\n");
            }
            else {
                printf("Nome nao encontrado!\n");
            }
        }

        // LISTAR
        else if (opcao == 3) {

            if (tamanho == 0) {
                printf("Nenhum nome cadastrado.\n");
            }
            else {
                printf("Nomes: %s\n", nomes);
            }
        }

    } while (opcao != 4);

    free(nomes);

    return 0;
}


/* este codigo a metade foi feito por IA, arrecem eu estava revento os conteudo de C,
 fiquei 6 meses sem ver nada sobre, pois nao sobrou vaga na turma de 26/1*/