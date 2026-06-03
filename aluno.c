#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

void cadastrarAluno(Aluno **lista, int *quantidade){
    int idTemp;

    printf("\n===== CADASTRAR ALUNO =====\n");
    printf("ID: ");
    scanf("%d", &idTemp);

    if (buscarAlunoPorId(*lista, *quantidade, idTemp) != -1){
        printf("\nErro: ID ja cadastrado!\n");
        return;
    }

    Aluno *temp = realloc(*lista, (*quantidade + 1) * sizeof(Aluno));

    if (temp == NULL){
        printf("\nErro de alocacao de memoria!\n");
        return;
    }

    *lista = temp;
    Aluno *novo = &(*lista)[*quantidade];
    novo->id = idTemp;

    printf("Nome: ");
    scanf(" %[^\n]", novo->nome);

    do{
        printf("Idade: ");
        scanf("%d", &novo->idade);
    }while (novo->idade < 0);

    printf("Curso: ");
    scanf(" %[^\n]", novo->curso);

    do{
        printf("Periodo: ");
        scanf("%d", &novo->periodo);
    }while (novo->periodo <= 0);

    do{
        printf("Media: ");
        scanf("%f", &novo->media);
    }while (novo->media < 0 || novo->media > 10);

    (*quantidade)++;
    printf("\nAluno cadastrado com sucesso!\n");
}

void listarAlunos(Aluno *lista, int quantidade){
    if (quantidade == 0){
        printf("\nNenhum aluno cadastrado.\n");
        return;
    }

    for (int i = 0; i < quantidade; i++){
        printf("\n===== ALUNO %d =====\n", i + 1);
        printf("ID: %d\n", lista[i].id);
        printf("Nome: %s\n", lista[i].nome);
        printf("Idade: %d\n", lista[i].idade);
        printf("Curso: %s\n", lista[i].curso);
        printf("Periodo: %d\n", lista[i].periodo);
        printf("Media: %.2f\n", lista[i].media);
    }
}

int buscarAlunoPorId(Aluno *lista, int quantidade, int id){
    for (int i = 0; i < quantidade; i++){
        if (lista[i].id == id) return i;
    }
    return -1;
}

void atualizarAluno(Aluno *lista, int quantidade){
    int id;
    printf("\nDigite o ID do aluno: ");
    scanf("%d", &id);

    int indice = buscarAlunoPorId(lista, quantidade, id);

    if (indice == -1){
        printf("\nAluno nao encontrado.\n");
        return;
    }

    printf("Novo nome: ");
    scanf(" %[^\n]", lista[indice].nome);

    do{
        printf("Nova idade: ");
        scanf("%d", &lista[indice].idade);
    }while (lista[indice].idade < 0);

    printf("Novo curso: ");
    scanf(" %[^\n]", lista[indice].curso);

    do{
        printf("Novo periodo: ");
        scanf("%d", &lista[indice].periodo);
    }while (lista[indice].periodo <= 0);

    do{
        printf("Nova media: ");
        scanf("%f", &lista[indice].media);
    }while (lista[indice].media < 0 || lista[indice].media > 10);

    printf("\nAluno atualizado com sucesso!\n");
}

void removerAluno(Aluno **lista, int *quantidade){
    int id;
    char confirmar;

    printf("\nDigite o ID do aluno: ");
    scanf("%d", &id);

    int indice = buscarAlunoPorId(*lista, *quantidade, id);

    if (indice == -1){
        printf("\nAluno nao encontrado.\n");
        return;
    }

    printf("Deseja remover %s? (s/n): ", (*lista)[indice].nome);
    scanf(" %c", &confirmar);

    if (confirmar != 's' && confirmar != 'S'){
        printf("\nRemocao cancelada.\n");
        return;
    }

    for (int i = indice; i < *quantidade - 1; i++){
        (*lista)[i] = (*lista)[i + 1];
    }

    (*quantidade)--;

    if (*quantidade > 0){
        Aluno *temp = realloc(*lista, (*quantidade) * sizeof(Aluno));
        if (temp != NULL) *lista = temp;
    }else{
        free(*lista);
        *lista = NULL;
    }

    printf("\nAluno removido com sucesso!\n");
}

void ordenarPorNome(Aluno *lista, int quantidade){
    Aluno temp;

    for (int i = 0; i < quantidade - 1; i++){
        for (int j = i + 1; j < quantidade; j++){
            if (strcmp(lista[i].nome, lista[j].nome) > 0){
                temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
    }

    printf("\nAlunos ordenados com sucesso!\n");
}
