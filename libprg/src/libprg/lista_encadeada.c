#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no {
    int valor;
    struct no* proximo;
} no_t;

no_t* criar_lista_encadeada(int valor);
no_t* criar_lista_encadeada_circular(int valor);

void inserir_lista_encadeada(no_t** inicio, int valor);
void inserir_lista_encadeada_circular(no_t** inicio, int valor);

void listar_lista_encadeada(no_t* inicio);
void listar_lista_encadeada_circular(no_t* inicio);

no_t* buscar_lista_encadeada(no_t* inicio, int valor);
int buscar_por_indice_lista_encadeada(no_t* inicio, int indice);

bool lista_encadeada_vazia(no_t* inicio);
int tamanho_lista_encadeada(no_t* inicio);

void substituir_em_indice_lista_encadeada(no_t* inicio, int indice, int valor);
void inverter_lista_encadeada(no_t** inicio);

void excluir_item_lista_encadeada(no_t** inicio, int valor);
void excluir_em_indice_lista_encadeada(no_t** inicio, int indice);

void limpar_lista_encadeada(no_t** inicio);
void destruir_lista_encadeada(no_t** inicio);


// ======== CRIAÇÃO ========
no_t* criar_lista_encadeada(int valor) {
    no_t* no = malloc(sizeof(no_t));
    no->valor = valor;
    no->proximo = NULL;
    return no;
}

no_t* criar_lista_encadeada_circular(int valor) {
    no_t* no = malloc(sizeof(no_t));
    no->valor = valor;
    no->proximo = no;
    return no;
}

// ======== INSERÇÃO ========
void inserir_lista_encadeada(no_t** inicio, int valor) {
    no_t* novo_no = criar_lista_encadeada(valor);
    novo_no->proximo = *inicio;
    *inicio = novo_no;
}

void inserir_lista_encadeada_circular(no_t** inicio, int valor) {
    no_t* novo_no = criar_lista_encadeada_circular(valor);
    if (!*inicio) {
        *inicio = novo_no;
        return;
    }
    no_t* ultimo = *inicio;
    while (ultimo->proximo != *inicio) {
        ultimo = ultimo->proximo;
    }
    novo_no->proximo = *inicio;
    ultimo->proximo = novo_no;
    *inicio = novo_no;
}

// ======== LISTAGEM ========
void listar_lista_encadeada(no_t* inicio) {
    no_t* atual = inicio;
    while (atual) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

void listar_lista_encadeada_circular(no_t* inicio) {
    if (!inicio) return;
    no_t* atual = inicio;
    do {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    } while (atual != inicio);
    printf("\n");
}

// ======== BUSCA ========
no_t* buscar_lista_encadeada(no_t* inicio, int valor) {
    no_t* atual = inicio;
    while (atual) {
        if (atual->valor == valor) return atual;
        atual = atual->proximo;
    }
    return NULL;
}

int buscar_por_indice_lista_encadeada(no_t* inicio, int indice) {
    int i = 0;
    no_t* atual = inicio;
    while (atual) {
        if (i == indice) return atual->valor;
        atual = atual->proximo;
        i++;
    }
    return -1;
}

// ======== UTILIDADES ========
bool lista_encadeada_vazia(no_t* inicio) {
    return inicio == NULL;
}

int tamanho_lista_encadeada(no_t* inicio) {
    int i = 0;
    no_t* atual = inicio;
    while (atual) {
        i++;
        atual = atual->proximo;
    }
    return i;
}

// ======== SUBSTITUIÇÃO E INVERSÃO ========
void substituir_em_indice_lista_encadeada(no_t* inicio, int indice, int valor) {
    int i = 0;
    no_t* atual = inicio;
    while (atual) {
        if (i == indice) {
            atual->valor = valor;
            return;
        }
        atual = atual->proximo;
        i++;
    }
}

void inverter_lista_encadeada(no_t** inicio) {
    no_t* anterior = NULL;
    no_t* atual = *inicio;
    no_t* proximo = NULL;
    while (atual) {
        proximo = atual->proximo;
        atual->proximo = anterior;
        anterior = atual;
        atual = proximo;
    }
    *inicio = anterior;
}

// ======== EXCLUSÃO ========
void excluir_item_lista_encadeada(no_t** inicio, int valor) {
    no_t* atual = *inicio;
    no_t* anterior = NULL;
    while (atual) {
        if (atual->valor == valor) {
            if (anterior) anterior->proximo = atual->proximo;
            else *inicio = atual->proximo;
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

void excluir_em_indice_lista_encadeada(no_t** inicio, int indice) {
    no_t* atual = *inicio;
    no_t* anterior = NULL;
    int i = 0;
    while (atual) {
        if (i == indice) {
            if (anterior) anterior->proximo = atual->proximo;
            else *inicio = atual->proximo;
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
        i++;
    }
}

// ======== LIMPEZA E DESTRUIÇÃO ========
void limpar_lista_encadeada(no_t** inicio) {
    no_t* atual = *inicio;
    while (atual) {
        no_t* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    *inicio = NULL;
}

void destruir_lista_encadeada(no_t** inicio) {
    if (!*inicio) return;
    no_t* atual = *inicio;
    if (*inicio != (*inicio)->proximo) {
        do {
            no_t* proximo = atual->proximo;
            free(atual);
            atual = proximo;
        } while (atual != *inicio);
    } else {
        free(atual);
    }
    *inicio = NULL;
}
