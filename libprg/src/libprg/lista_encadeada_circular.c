#include <stdlib.h>

typedef struct no_duplo {
    int valor;
    struct no_duplo* proximo;
    struct no_duplo* anterior;
} no_duplo_t;

no_duplo_t* criar_lista_encadeada_dupla(int valor) {
    no_duplo_t *no = malloc(sizeof(no_duplo_t));
    no->valor = valor;
    no->proximo = NULL;
    no->anterior = NULL;
}

void adicionar_lista_encadeada_dupla(no_duplo_t** inicio, int valor) {
    no_duplo_t* novo_no = criar_lista_encadeada_dupla(valor);
    novo_no->proximo = *inicio;
    (*inicio)->anterior = novo_no;
    *inicio = novo_no;
}

no_duplo_t* buscar_lista_encadeada_dupla(no_duplo_t** inicio, int valor) {
    no_duplo_t* atual = *inicio;
    while (atual) {
        if (atual->valor == valor) return atual;
        atual = atual->proximo;
    }
    return NULL;
}

void excluir_item_lista_encadeada_dupla(no_duplo_t** inicio, int valor) {
    no_duplo_t* atual = *inicio;

    while (atual) {
        if (atual->valor == valor) {
            if (atual->anterior) {
                atual->anterior->proximo = atual->proximo;
                atual->proximo->anterior = atual->anterior;
            }
            else {
                *inicio = atual->proximo;
                (*inicio)->anterior = NULL;
            }
            free(atual);
            break;
        }
atual = atual->proximo;
    }
}
