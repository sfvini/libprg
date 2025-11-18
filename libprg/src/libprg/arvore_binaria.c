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

void destruir_arvore(no_arvore_t *raiz) {
    if (raiz != NULL) {
        destruir_arvore(raiz->esquerda);
        destruir_arvore(raiz->direita);
        free(raiz);
    }
}

no_arvore_t *inserir_valor(no_arvore_t *raiz, int valor){
    if (raiz == NULL) {
        return criar_no(valor);
    }
    if (valor < raiz->valor) {
        raiz->esquerda = inserir_valor(raiz->esquerda, valor);
    }
    else if (valor > raiz->valor) {
        raiz->direita = inserir_valor(raiz->direita, valor);
    }
    return raiz;
}

bool busca(no_arvore_t *raiz, int valor){
    if (raiz == NULL) return false;
    if (valor == raiz->valor) return true;
    if (valor < raiz->valor) return busca(raiz->esquerda, valor);
    return busca(raiz->direita, valor);
}

