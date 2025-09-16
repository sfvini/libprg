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
    if (!lista_linear_cheia(ll)) {
        ll->elementos[ll->tamanho] = valor;
        ll->tamanho++;
    }
}

int buscar_lista_linear(lista_linear_t *ll, int valor) {
    if (!lista_linear_vazia(ll)) {
        for (int i = 0; i < ll->tamanho; i++) {
            if (ll->elementos[i] == valor) {
                return i;
            }
        }
    }
    return -1;
}

void listar_lista_linear(lista_linear_t *ll) {
    if (!lista_linear_vazia(ll)) {
        for (int i = 0; i < ll->tamanho; i++) {
            printf("%d ", ll->elementos[i]);
        }
        printf("\n");
    }
}

int tamanho_lista_linear(lista_linear_t *ll) {
    return ll->tamanho;
}

void excluir_elemento_lista_linear(lista_linear_t *ll, int valor) {
    if (!lista_linear_vazia(ll)) {
        for (int i = 0; i < ll->tamanho; i++) {
            if (ll->elementos[i] == valor) {
                ll->elementos[i] = ll->elementos[ll->tamanho-1];
                ll->tamanho--;
                return;
            }
        }
    }
}

void apagar_lista_linear(lista_linear_t *ll) {
    free(ll->elementos);
    free(ll);
}