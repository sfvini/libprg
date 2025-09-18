#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct lista {
    int *elementos;
    int tamanho;
    int capacidade;
    bool ordenada;
} lista_t;

lista_t *criar_lista(int capacidade, bool ordenada) {
    lista_t *l = malloc(sizeof(lista_t));
    l->elementos = malloc(sizeof(int) * capacidade);
    l->capacidade = capacidade;
    l->tamanho = 0;
    l->ordenada = ordenada;
    return l;
}

bool lista_cheia(lista_t *l) {
    return l->tamanho == l->capacidade;
}

bool lista_vazia(lista_t *l) {
    return l->tamanho == 0;
}

void inserir_ordenada(lista_t *l, int valor) {
    int i = l->tamanho - 1;
    while (i >= 0 && l->elementos[i] < valor) {
        l->elementos[i + 1] = l->elementos[i];
        i--;
    }
    l->elementos[i + 1] = valor;
    l->tamanho++;
}

void inserir_nao_ordenada(lista_t *l, int valor) {
    l->elementos[l->tamanho] = valor;
    l->tamanho++;
}

void inserir_lista(lista_t *l, int valor) {
    if (lista_cheia(l)) return;
    if (l->ordenada)
        inserir_ordenada(l, valor);
    else
        inserir_nao_ordenada(l, valor);
}

int busca_binaria(lista_t *l, int valor) {
    int inicio = 0;
    int fim = l->tamanho - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (l->elementos[meio] == valor) return meio;
        (l->elementos[meio] < valor) ? (fim = meio - 1) : (inicio = meio + 1);
    }
    return -1;
}

int busca_linear(lista_t *l, int valor) {
    for (int i = 0; i < l->tamanho; ++i) {
        if (l->elementos[i] == valor) return i;
    }
    return -1;
}

int buscar_lista(lista_t *l, int valor) {
    if (lista_vazia(l)) return -1;
    if (l->ordenada) return busca_binaria(l, valor);
    return busca_linear(l, valor);
}

void listar_lista(lista_t *l) {
    if (!lista_vazia(l)) {
        for (int i = 0; i < l->tamanho; i++) {
            printf("%d ", l->elementos[i]);
        }
        printf("\n");
    }
}

int tamanho_lista(lista_t *l) {
    return l->tamanho;
}

void remocao_nao_ordenada(lista_t *l, int valor) {
    int pos = buscar_lista(l, valor);
    if (pos == -1) return;

    l->elementos[pos] = l->elementos[l->tamanho - 1];
    l->tamanho--;
}

void remocao_ordenada(lista_t *l, int valor) {
    int pos = buscar_lista(l, valor);
    if (pos == -1) return;

    for (int i = pos; i < l->tamanho - 1; i++) {
        l->elementos[i] = l->elementos[i + 1];
    }
    l->tamanho--;
}

void excluir_item_lista(lista_t *l, int valor) {
    if (lista_vazia(l)) return;
    if (l->ordenada)
        remocao_ordenada(l, valor);
    else
        remocao_nao_ordenada(l, valor);
}

void apagar_lista(lista_t *l) {
    free(l->elementos);
    free(l);
}
