#include <stdbool.h>
#include <stdlib.h>
#include <libprg/libprg.h>

typedef struct fila {
    int *elementos;
    int capacidade;
    int inicio;
    int fim;
} fila_t;

fila_t* criar_fila(int capacidade) {
    fila_t *f = malloc(sizeof(fila_t));
    f->elementos = malloc(sizeof(int) * capacidade);

    f->capacidade = capacidade;

    f->inicio = 0;
    f->fim = 0;

    return f;
}

void enfileirar(fila_t* fila, int valor) {
    fila->elementos[fila->fim] = valor;
    fila->fim++;
}

void desenfileirar(fila_t* fila, int fim, int inicio) {
    fila->fim--;
}

bool cheia(fila_t* fila) {
    return fila->fim >= fila->capacidade;
}



