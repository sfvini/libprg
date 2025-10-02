#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no* proximo;
} no_t;

//--------------------------------------
no_t* criar_lista_encadeada(int valor) {
    no_t* no = malloc(sizeof(no_t));
    no->valor = valor;
    no->proximo = NULL;

    return no;
}

void adicionar_lista_encadeada(no_t** inicio, int valor) {
    no_t* novo_no = criar_lista_encadeada(valor);
    novo_no->proximo = *inicio;
    *inicio = novo_no;
}
//--------------------------------------

//--------------------------------------
no_t* criar_lista_encadeada_circular(int valor) {
    no_t* no = malloc(sizeof(no_t));
    no->valor = valor;
    no->proximo = no;

    return no;
}

void adicionar_lista_encadeada_circular(no_t** inicio, int valor) {
    no_t* novo_no = criar_lista_encadeada_circular(valor);
    novo_no->proximo = *inicio;

    no_t* ultimo = *inicio;

    while (ultimo->proximo != *inicio) {
        ultimo = ultimo->proximo;
    }

    ultimo->proximo = novo_no;
    *inicio = novo_no;
}
//--------------------------------------

//--------------------------------------
no_t* buscar_lista_encadeada(no_t** inicio, int valor) {
    no_t* atual = *inicio;

    while (atual) {
        if (atual->valor == valor) return atual;
        atual = atual->proximo;
    }

    return NULL;
}

void remover_lista_encadeada(no_t** inicio, int valor) {
    no_t* atual = *inicio;
    no_t* anterior = NULL;

    while (atual) {
        if (atual->valor == valor) {
            if (anterior) {
                anterior->proximo = atual->proximo;
            }
            else {
                *inicio = atual->proximo;
            }
            free(atual);
            break;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

void destruir_lista_encadeada(no_t** inicio) {
    no_t* atual = *inicio;

    while (atual) {
        no_t* proximo = atual->proximo;
        free(atual);
        if (proximo == *inicio) break;
        atual = proximo;
    }
}
