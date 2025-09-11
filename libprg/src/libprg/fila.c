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

bool cheia(fila_t *f) {
    return f->tamanho == f->capacidade;
}

bool vazia(fila_t *f) {
    return f->tamanho == 0;
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

int fim_fila(fila_t *f) {
    if (f->fim < 0) {
        exit(EXIT_FAILURE);
    }
    return f->elementos[f->fim];
}

void enfileirar(fila_t *f, int valor) {
    if (cheia(f)) {
        exit(EXIT_FAILURE);
    }
    f->elementos[f->fim] = valor;
    f->tamanho++;
    f->fim = (f->fim + 1) % f->capcidade;
}

void desenfileirar(fila_t *f) {
    if (vazia(f)) {
        exit(EXIT_FAILURE);
    }
    f->inicio = (f->inicio + 1) % f->capacidade;
    f->tamanho--;
}

void listar_fila(fila_t *f) {
    if (vazia(f)) {
        exit(EXIT_FAILURE);
    }
    int i = f->inicio;
    for (int count = 0; count < f->tamanho; count++) {
        printf("%d ", f->elementos[i]);
        i = (i + 1) % f->capacidade;
    }
    printf("\n");
}

void apagar_fila(fila_t *f) {
    free(f->elementos);
    free(f);
}

