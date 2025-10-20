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

bool fila_cheia(fila_t *f) {
    return f->tamanho == f->capacidade;
}

bool fila_vazia(fila_t *f) {
    return f->tamanho == 0;
}

int tamanho_fila(fila_t *f) {
    return f->tamanho;
}

int inicio_fila(fila_t *f) {
    if (fila_vazia(f)) {
        return -1;
    }
    return f->elementos[f->inicio];
}

int topo_fila(fila_t *f) {
    if (fila_vazia(f)) {
        return -1;
    }
    return f->elementos[(f->fim - 1 + f->capacidade) % f->capacidade];
}

void enfileirar(fila_t *f, int valor) {
    if (fila_cheia(f)) {
        exit(EXIT_FAILURE);
    }
    f->elementos[f->fim] = valor;
    f->tamanho++;
    f->fim = (f->fim + 1) % f->capacidade;
}

void desenfileirar(fila_t *f) {
    if (fila_vazia(f)) {
        exit(EXIT_FAILURE);
    }
    f->inicio = (f->inicio + 1) % f->capacidade;
    f->tamanho--;
}

void listar_fila(fila_t *f) {
    if (fila_vazia(f)) {
        exit(EXIT_FAILURE);
    }
    int i = f->inicio;
    for (int count = 0; count < f->tamanho; count++) {
        printf("%d ", f->elementos[i]);
        i = (i + 1) % f->capacidade;
    }
    printf("\n");
}

void destruir_fila(fila_t *f) {
    free(f->elementos);
    free(f);
}

void limpar_fila(fila_t *f) {
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
}

int buscar_fila(fila_t *f, int valor) {
    int i = f->inicio;
    for (int count = 0; count < f->tamanho; count++) {
        if (f->elementos[i] == valor) {
            return count;
        }
        i = (i + 1) % f->capacidade;
    }
    return -1;
}

void inverter_fila(fila_t *f) {
    for (int i = 0; i < f->tamanho / 2; i++) {
        int idx1 = (f->inicio + i) % f->capacidade;
        int idx2 = (f->inicio + f->tamanho - 1 - i) % f->capacidade;
        int temp = f->elementos[idx1];
        f->elementos[idx1] = f->elementos[idx2];
        f->elementos[idx2] = temp;
    }
}
