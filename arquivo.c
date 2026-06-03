#include <stdio.h>
#include <stdlib.h>
#include "arquivo.h"

#define NOME_ARQUIVO "alunos.dat"

void salvarDados(Aluno *lista, int quantidade) {
    FILE *arquivo = fopen(NOME_ARQUIVO, "wb");

    if (arquivo == NULL) {
        printf("\nErro ao salvar arquivo!\n");
        return;
    }

    fwrite(&quantidade, sizeof(int), 1, arquivo);
    fwrite(lista, sizeof(Aluno), quantidade, arquivo);

    fclose(arquivo);
}

void carregarDados(Aluno **lista, int *quantidade) {
    FILE *arquivo = fopen(NOME_ARQUIVO, "rb");

    if (arquivo == NULL) {
        *lista = NULL;
        *quantidade = 0;
        return;
    }

    fread(quantidade, sizeof(int), 1, arquivo);

    if (*quantidade > 0) {
        *lista = malloc((*quantidade) * sizeof(Aluno));
        fread(*lista, sizeof(Aluno), *quantidade, arquivo);
    } else {
        *lista = NULL;
    }

    fclose(arquivo);
}
