#ifndef ALUNO_H
#define ALUNO_H

typedef struct {
    int id;
    char nome[100];
    int idade;
    char curso[50];
    int periodo;
    float media;
} Aluno;

void cadastrarAluno(Aluno **lista, int *quantidade);
void listarAlunos(Aluno *lista, int quantidade);
int buscarAlunoPorId(Aluno *lista, int quantidade, int id);
void atualizarAluno(Aluno *lista, int quantidade);
void removerAluno(Aluno **lista, int *quantidade);
void ordenarPorNome(Aluno *lista, int quantidade);

#endif
