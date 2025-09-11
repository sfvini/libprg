#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "./libprg/libprg.h"

typedef struct fila {
    int *elementos;
    int capacidade;
    int inicio;
    int fim;
    int tamanho;
} fila_t;

fila_t *criar_fila(int capacidade) {
    fila_t *f = malloc(sizeof(fila_t));
    f->elementos = malloc(sizeof(int) * capacidade);
    f->capacidade = capacidade;
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
    return f;
}

bool cheia(fila_t *fila) {
    return fila->tamanho == fila->capacidade;
}

bool vazia(fila_t *fila) {
    return fila->tamanho == 0;
}

int tamanho_fila(fila_t *f) {
    return f->tamanho;
}

int inicio_fila(fila_t *f) {
    if (f->inicio < 0) {
        exit(EXIT_FAILURE);
    }
    return f->elementos[f->inicio];
}

void enfileirar(fila_t *fila, int valor) {
    if (cheia(fila)) {
        exit(EXIT_FAILURE);
    }
    fila->elementos[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->tamanho++;
}

void desenfileirar(fila_t *fila) {
    if (vazia(fila)) {
        exit(EXIT_FAILURE);
    }
    fila->inicio = (fila->inicio + 1) % fila->capacidade;
    fila->tamanho--;
}

void listar_fila(fila_t *fila) {
    if (vazia(fila)) {
        exit(EXIT_FAILURE);
    }
    int i = fila->inicio;
    for (int count = 0; count < fila->tamanho; count++) {
        printf("%d ", fila->elementos[i]);
        i = (i + 1) % fila->capacidade;
    }
    printf("\n");
}

void apagar_fila(fila_t *f) {
    free(f->elementos);
    free(f);
}

