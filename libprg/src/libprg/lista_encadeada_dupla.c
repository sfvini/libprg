#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct no_duplo {
    int valor;
    struct no_duplo* proximo;
    struct no_duplo* anterior;
} no_duplo_t;

no_duplo_t* criar_lista_encadeada_dupla(int valor);

void inserir_lista_encadeada_dupla(no_duplo_t** inicio, int valor);

no_duplo_t* buscar_lista_encadeada_dupla(no_duplo_t* inicio, int valor);
int buscar_por_indice_lista_encadeada_dupla(no_duplo_t* inicio, int indice);
void listar_lista_encadeada_dupla(no_duplo_t* inicio);

void substituir_em_indice_lista_encadeada_dupla(no_duplo_t* inicio, int indice, int valor);
void inverter_lista_encadeada_dupla(no_duplo_t** inicio);

int tamanho_lista_encadeada_dupla(no_duplo_t* inicio);
bool lista_encadeada_dupla_vazia(no_duplo_t* inicio);

void excluir_item_lista_encadeada_dupla(no_duplo_t** inicio, int valor);
void excluir_em_indice_lista_encadeada_dupla(no_duplo_t** inicio, int indice);

void destruir_lista_encadeada_dupla(no_duplo_t** inicio);

// ======== CRIAÇÃO ========
no_duplo_t* criar_lista_encadeada_dupla(int valor) {
    no_duplo_t *no = malloc(sizeof(no_duplo_t));
    no->valor = valor;
    no->proximo = NULL;
    no->anterior = NULL;
    return no;
}

// ======== INSERÇÃO ========
void inserir_lista_encadeada_dupla(no_duplo_t** inicio, int valor) {
    no_duplo_t* novo_no = criar_lista_encadeada_dupla(valor);
    if (!*inicio) {
        *inicio = novo_no;
        return;
    }
    novo_no->proximo = *inicio;
    (*inicio)->anterior = novo_no;
    *inicio = novo_no;
}

// ======== BUSCA E LISTAGEM ========
no_duplo_t* buscar_lista_encadeada_dupla(no_duplo_t* inicio, int valor) {
    no_duplo_t* atual = inicio;
    while (atual) {
        if (atual->valor == valor) return atual;
        atual = atual->proximo;
    }
    return NULL;
}

int buscar_por_indice_lista_encadeada_dupla(no_duplo_t* inicio, int indice) {
    int i = 0;
    no_duplo_t* atual = inicio;
    while (atual) {
        if (i == indice) return atual->valor;
        atual = atual->proximo;
        i++;
    }
    return -1;
}

void listar_lista_encadeada_dupla(no_duplo_t* inicio) {
    no_duplo_t* atual = inicio;
    while (atual) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

// ======== SUBSTITUIÇÃO E INVERSÃO ========
void substituir_em_indice_lista_encadeada_dupla(no_duplo_t* inicio, int indice, int valor) {
    int i = 0;
    no_duplo_t* atual = inicio;
    while (atual) {
        if (i == indice) {
            atual->valor = valor;
            return;
        }
        atual = atual->proximo;
        i++;
    }
}

void inverter_lista_encadeada_dupla(no_duplo_t** inicio) {
    no_duplo_t* atual = *inicio;
    no_duplo_t* temp = NULL;
    while (atual) {
        temp = atual->anterior;
        atual->anterior = atual->proximo;
        atual->proximo = temp;
        if (!atual->anterior) {
            *inicio = atual;
        }
        atual = atual->anterior;
    }
}

// ======== UTILIDADES ========
int tamanho_lista_encadeada_dupla(no_duplo_t* inicio) {
    int i = 0;
    no_duplo_t* atual = inicio;
    while (atual) {
        i++;
        atual = atual->proximo;
    }
    return i;
}

bool lista_encadeada_dupla_vazia(no_duplo_t* inicio) {
    return inicio == NULL;
}

// ======== EXCLUSÃO ========
void excluir_item_lista_encadeada_dupla(no_duplo_t** inicio, int valor) {
    no_duplo_t* atual = *inicio;
    while (atual) {
        if (atual->valor == valor) {
            if (atual->anterior) {
                atual->anterior->proximo = atual->proximo;
            } else {
                *inicio = atual->proximo;
            }
            if (atual->proximo) {
                atual->proximo->anterior = atual->anterior;
            }
            free(atual);
            return;
        }
        atual = atual->proximo;
    }
}

void excluir_em_indice_lista_encadeada_dupla(no_duplo_t** inicio, int indice) {
    no_duplo_t* atual = *inicio;
    int i = 0;
    while (atual) {
        if (i == indice) {
            if (atual->anterior) {
                atual->anterior->proximo = atual->proximo;
            } else {
                *inicio = atual->proximo;
            }
            if (atual->proximo) {
                atual->proximo->anterior = atual->anterior;
            }
            free(atual);
            return;
        }
        atual = atual->proximo;
        i++;
    }
}

// ======== DESTRUIÇÃO ========
void destruir_lista_encadeada_dupla(no_duplo_t** inicio) {
    no_duplo_t* atual = *inicio;
    while (atual) {
        no_duplo_t* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    *inicio = NULL;
}
