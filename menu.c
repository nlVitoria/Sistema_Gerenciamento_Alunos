#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "arquivo.h"
#include "aluno.h"

void menuPrincipal(Aluno **lista, int *quantidade){
    int opcao, id, indice;

    carregarDados(lista, quantidade);

    do {
        printf("\n===== SISTEMA DE ALUNOS =====\n");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Listar alunos\n");
        printf("3 - Buscar aluno por ID\n");
        printf("4 - Atualizar aluno\n");
        printf("5 - Remover aluno\n");
        printf("6 - Ordenar por nome\n");
        printf("0 - Sair\n");
        printf("Escolha: ");

        if (scanf("%d", &opcao) != 1){
            while (getchar() != '\n');
            opcao = -1;
            continue;
        }

        switch(opcao){
            case 1:
                cadastrarAluno(lista, quantidade);
                break;

            case 2:
                listarAlunos(*lista, *quantidade);
                break;

            case 3:
                printf("Digite o ID: ");
                scanf("%d", &id);

                indice = buscarAlunoPorId(*lista, *quantidade, id);

                if (indice == -1){
                    printf("Aluno nao encontrado.\n");
                } else {
                    printf("\nNome: %s\n", (*lista)[indice].nome);
                    printf("Curso: %s\n", (*lista)[indice].curso);
                    printf("Media: %.2f\n", (*lista)[indice].media);
                }
                break;

            case 4:
                atualizarAluno(*lista, *quantidade);
                break;

            case 5:
                removerAluno(lista, quantidade);
                break;

            case 6:
                ordenarPorNome(*lista, *quantidade);
                break;

            case 0:
                salvarDados(*lista, *quantidade);
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 0);

    free(*lista);
}
