#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no_arvore {
    int valor;
    struct no_arvore *esquerda;
    struct no_arvore *direita;
} no_arvore_t;

no_arvore_t *criar_no(int valor){
    no_arvore_t *novo_no = (no_arvore_t*)malloc(sizeof(no_arvore_t));
    if (novo_no == NULL) {
        perror("Erro ao alocar memória para novo nó");
        exit(EXIT_FAILURE);
    }
    novo_no->valor = valor;
    novo_no->esquerda = novo_no->direita = NULL;
    return novo_no;
}

