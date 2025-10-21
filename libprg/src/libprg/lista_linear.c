#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct lista_linear {
    int *elementos;
    int tamanho;
    int capacidade;
    bool ordenada;
} lista_linear_t;

lista_linear_t *criar_lista_linear(int capacidade, bool ordenada) {
    lista_linear_t *ll = malloc(sizeof(lista_linear_t));
    ll->elementos = malloc(sizeof(int) * capacidade);
    ll->capacidade = capacidade;
    ll->tamanho = 0;
    ll->ordenada = ordenada;
    return ll;
}

lista_linear_t *eliminar_duplicatas(int capacidade, lista_linear_t *ll) {
    lista_linear_t *nova_lista = malloc(sizeof(lista_linear_t));
    for (int i = 0; i < capacidade; i++) {
        if (buscar_lista_linear(nova_lista, obter_elemento_lista_linear(ll, i)) == -1) {
            inserir_lista_linear(nova_lista, obter_elemento_lista_linear(ll, i));
        }
    }
    return nova_lista;
}


bool lista_linear_cheia(lista_linear_t *ll) {
    return ll->tamanho >= ll->capacidade;
}

bool lista_linear_vazia(lista_linear_t *ll) {
    return ll->tamanho == 0;
}

//--------------------------------------
void inserir_ordenada(lista_linear_t *ll, int valor) {
    if (lista_linear_cheia(ll)) return;

    int i = ll->tamanho - 1;
    while (i >= 0 && ll->elementos[i] > valor) {
        ll->elementos[i + 1] = ll->elementos[i];
        i--;
    }
    ll->elementos[i + 1] = valor;
    ll->tamanho++;
}

void inserir_nao_ordenada(lista_linear_t *ll, int valor) {
    if (lista_linear_cheia(ll)) return;

    ll->elementos[ll->tamanho] = valor;
    ll->tamanho++;
}

void inserir_lista_linear(lista_linear_t *ll, int valor) {
    if (!ll) return;

    if (lista_linear_cheia(ll)) {
        ll->elementos = realloc(ll->elementos, sizeof(int)*ll->capacidade*2);
        ll->capacidade *=2;
    }

    if (ll->ordenada)
        inserir_ordenada(ll, valor);
    else
        inserir_nao_ordenada(ll, valor);
}
//--------------------------------------

//--------------------------------------
int busca_binaria(lista_linear_t *ll, int valor) {
    int inicio = 0;
    int fim = ll->tamanho - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (ll->elementos[meio] == valor)
            return meio;
        else if (ll->elementos[meio] < valor)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }
    return -1;
}

int busca_linear(lista_linear_t *ll, int valor) {
    for (int i = 0; i < ll->tamanho; i++) {
        if (ll->elementos[i] == valor) return i;
    }
    return -1;
}

int buscar_lista_linear(lista_linear_t *ll, int valor) {
    if (!ll || lista_linear_vazia(ll)) return -1;

    if (ll->ordenada)
        return busca_binaria(ll, valor);
    return busca_linear(ll, valor);
}
//--------------------------------------

//--------------------------------------
void excluir_item_ordenada(lista_linear_t *ll, int valor) {
    int pos = buscar_lista_linear(ll, valor);
    if (pos == -1) return;

    for (int i = pos; i < ll->tamanho - 1; i++) {
        ll->elementos[i] = ll->elementos[i + 1];
    }
    ll->tamanho--;
}

void excluir_item_nao_ordenada(lista_linear_t *ll, int valor) {
    int pos = buscar_lista_linear(ll, valor);
    if (pos == -1) return;

    ll->elementos[pos] = ll->elementos[ll->tamanho - 1];
    ll->tamanho--;
}

void excluir_item_lista_linear(lista_linear_t *ll, int valor) {
    if (!ll || lista_linear_vazia(ll)) return;

    if (ll->ordenada)
        excluir_item_ordenada(ll, valor);
    else
        excluir_item_nao_ordenada(ll, valor);
}
//--------------------------------------

int obter_elemento_lista_linear(lista_linear_t *ll, int indice) {
    if (!ll || indice < 0 || indice >= ll->tamanho) {
        return -1;
    }
    return ll->elementos[indice];
}

int tamanho_lista_linear(lista_linear_t *ll) {
    if (!ll) return 0;
    return ll->tamanho;
}

void listar_lista_linear(lista_linear_t *ll) {
    if (!ll || lista_linear_vazia(ll)) return;

    for (int i = 0; i < ll->tamanho; i++) {
        printf("%d ", ll->elementos[i]);
    }
    printf("\n");
}

void destruir_lista_linear(lista_linear_t *ll) {
    if (!ll) return;
    free(ll->elementos);
    free(ll);
}

void inverter_lista_linear(lista_linear_t *ll) {
    if (!ll || lista_linear_vazia(ll)) return;
    for (int i = 0, j = ll->tamanho - 1; i < j; i++, j--) {
        int temp = ll->elementos[i];
        ll->elementos[i] = ll->elementos[j];
        ll->elementos[j] = temp;
    }
}

void limpar_lista_linear(lista_linear_t *ll) {
    if (!ll) return;
    ll->tamanho = 0;
}

int buscar_na_posicao_lista_linear(lista_linear_t *ll, int indice) {
    return ll->elementos[indice];
}

void inserir_na_posicao_lista_linear(lista_linear_t *ll, int indice, int valor) {
        inserir_lista_linear(ll, ll->elementos[indice]);
        ll->elementos[indice] = valor;
    }
