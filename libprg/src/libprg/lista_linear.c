#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct lista_linear {
    int *elementos;
    int tamanho;
    int capacidade;
    bool ordenada;
} lista_linear_t;

lista_linear_t *criar_lista_linear(int capacidade, bool ordenada);

bool lista_linear_cheia(const lista_linear_t *ll);
bool lista_linear_vazia(const lista_linear_t *ll);

int busca_binaria(const lista_linear_t *ll, int valor);
int busca_linear(const lista_linear_t *ll, int valor);
int buscar_lista_linear(const lista_linear_t *ll, int valor);
void listar_lista_linear(const lista_linear_t *ll);

void inserir_ordenada(lista_linear_t *ll, int valor);
void inserir_nao_ordenada(lista_linear_t *ll, int valor);
void inserir_lista_linear(lista_linear_t *ll, int valor);
void inserir_em_indice_lista_linear(lista_linear_t *ll, int indice, int valor);

void excluir_item_ordenada(lista_linear_t *ll, int valor);
void excluir_item_nao_ordenada(lista_linear_t *ll, int valor);
void excluir_item_lista_linear(lista_linear_t *ll, int valor);
void excluir_em_indice_lista_linear(lista_linear_t *ll, int indice);
void excluir_duplicatas_lista_linear(lista_linear_t *ll);

void substituir_em_indice_lista_linear(lista_linear_t *ll, int indice, int valor);
void inverter_lista_linear(lista_linear_t *ll);

void limpar_lista_linear(lista_linear_t *ll);
void destruir_lista_linear(lista_linear_t *ll);

// ======== CRIAÇÃO ========
lista_linear_t *criar_lista_linear(int capacidade, bool ordenada) {
    lista_linear_t *ll = malloc(sizeof(lista_linear_t));
    if (!ll) return NULL;
    ll->elementos = calloc(capacidade, sizeof(int));
    ll->capacidade = capacidade;
    ll->tamanho = 0;
    ll->ordenada = ordenada;
    return ll;
}

// ======== FUNÇÕES BOOLEANAS ========
bool lista_linear_cheia(const lista_linear_t *ll) {
    return ll && ll->tamanho >= ll->capacidade;
}

bool lista_linear_vazia(const lista_linear_t *ll) {
    return !ll || ll->tamanho == 0;
}

// ========  BUSCA E LISTAGEM ========
int busca_binaria(const lista_linear_t *ll, int valor) {
    if (!ll || lista_linear_vazia(ll)) return -1;
    int inicio = 0;
    int fim = ll->tamanho - 1;
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        if (ll->elementos[meio] == valor) return meio;
        else if (ll->elementos[meio] < valor) inicio = meio + 1;
        else fim = meio - 1;
    }
    return -1;
}

int busca_linear(const lista_linear_t *ll, int valor) {
    if (!ll || lista_linear_vazia(ll)) return -1;
    for (int i = 0; i < ll->tamanho; i++) {
        if (ll->elementos[i] == valor) return i;
    }
    return -1;
}

int buscar_lista_linear(const lista_linear_t *ll, int valor) {
    if (!ll || lista_linear_vazia(ll)) return -1;
    if (ll->ordenada)
        return busca_binaria(ll, valor);
    return busca_linear(ll, valor);
}

void listar_lista_linear(const lista_linear_t *ll) {
    if (!ll || lista_linear_vazia(ll)) return;
    for (int i = 0; i < ll->tamanho; i++)
        printf("%d ", ll->elementos[i]);
    printf("\n");
}

// ======== INSERÇÃO ========
void inserir_ordenada(lista_linear_t *ll, int valor) {
    if (!ll || lista_linear_cheia(ll)) return;
    int i = ll->tamanho - 1;
    while (i >= 0 && ll->elementos[i] > valor) {
        ll->elementos[i + 1] = ll->elementos[i];
        i--;
    }
    ll->elementos[i + 1] = valor;
    ll->tamanho++;
}

void inserir_nao_ordenada(lista_linear_t *ll, int valor) {
    if (!ll || lista_linear_cheia(ll)) return;
    ll->elementos[ll->tamanho++] = valor;
}

void inserir_lista_linear(lista_linear_t *ll, int valor) {
    if (!ll) return;
    if (lista_linear_cheia(ll)) {
        ll->capacidade += ll->capacidade / 2;
        ll->elementos = realloc(ll->elementos, sizeof(int) * ll->capacidade);
    }
    if (ll->ordenada) {
        inserir_ordenada(ll, valor);
    }
    else {
        inserir_nao_ordenada(ll, valor);
    }
}

void inserir_em_indice_lista_linear(lista_linear_t *ll, int indice, int valor) {
    if (!ll || indice < 0 || indice > ll->tamanho) return;
    if (lista_linear_cheia(ll)) {
        ll->capacidade += ll->capacidade / 2;
        ll->elementos = realloc(ll->elementos, sizeof(int) * ll->capacidade);
    }
    for (int i = ll->tamanho; i > indice; i--) {
        ll->elementos[i] = ll->elementos[i - 1];
    }
    ll->elementos[indice] = valor;
    ll->tamanho++;
}

    // ======== EXCLUSÃO ========
void excluir_item_ordenada(lista_linear_t *ll, int valor) {
    if (!ll || lista_linear_vazia(ll)) return;
    int pos = buscar_lista_linear(ll, valor);
    if (pos == -1) return;
    for (int i = pos; i < ll->tamanho - 1; i++)
        ll->elementos[i] = ll->elementos[i + 1];
    ll->tamanho--;
}

void excluir_item_nao_ordenada(lista_linear_t *ll, int valor) {
    if (!ll || lista_linear_vazia(ll)) return;
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

void excluir_em_indice_lista_linear(lista_linear_t *ll, int indice) {
    if (!ll || indice < 0 || indice >= ll->tamanho) return;
    for (int i = indice; i < ll->tamanho - 1; i++)
        ll->elementos[i] = ll->elementos[i + 1];
    ll->tamanho--;
}

void excluir_duplicatas_lista_linear(lista_linear_t *ll) {
    if (!ll || lista_linear_vazia(ll)) return;

    int novo_tamanho = 0;

    for (int i = 0; i < ll->tamanho; i++) {
        int valor = ll->elementos[i];
        bool duplicado = false;

        for (int j = 0; j < novo_tamanho; j++) {
            if (ll->elementos[j] == valor) {
                duplicado = true;
                break;
            }
        }
        if (!duplicado) {
            ll->elementos[novo_tamanho++] = valor;
        }
    }
    ll->tamanho = novo_tamanho;
}

// ======== SUBSTITUIÇÃO E INVERSÃO ========
void substituir_em_indice_lista_linear(lista_linear_t *ll, int indice, int valor) {
    if (!ll || indice < 0 || indice >= ll->tamanho) return;
    ll->elementos[indice] = valor;
}

void inverter_lista_linear(lista_linear_t *ll) {
    if (!ll || lista_linear_vazia(ll)) return;
    for (int i = 0, j = ll->tamanho - 1; i < j; i++, j--) {
        int temp = ll->elementos[i];
        ll->elementos[i] = ll->elementos[j];
        ll->elementos[j] = temp;
    }
}

// ======== LIMPEZA E DESTRUIÇÃO ========
void limpar_lista_linear(lista_linear_t *ll) {
    if (!ll) return;
    ll->tamanho = 0;
}

void destruir_lista_linear(lista_linear_t *ll) {
    if (!ll) return;
    free(ll->elementos);
    free(ll);
}
