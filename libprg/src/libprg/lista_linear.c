#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct lista_linear {
    int *elementos;
    int tamanho;
    int capacidade;
} lista_linear_t;

lista_linear_t *criar_lista_linear(int capacidade) {
    lista_linear_t *ll = malloc(sizeof(lista_linear_t));
    ll->elementos = malloc(sizeof(int) * capacidade);
    ll->capacidade = capacidade;
    ll->tamanho = 0;
    return ll;
}

bool lista_linear_cheia(lista_linear_t *ll) {
    return ll->tamanho == ll->capacidade;
}

bool lista_linear_vazia(lista_linear_t *ll) {
    return ll->tamanho == 0;
}

void inserir_lista_linear(lista_linear_t *ll, int valor) {
    if (lista_linear_cheia(ll)) {
        exit(EXIT_FAILURE);
    }
    ll->elementos[ll->tamanho] = valor;
    ll->tamanho++;
}