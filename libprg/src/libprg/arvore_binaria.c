#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max(a,b) ((a) > (b) ? (a) : (b))

typedef struct no_arvore {
    int valor;
    int altura;
    struct no_arvore *esquerda;
    struct no_arvore *direita;
} no_arvore_t;

int altura(no_arvore_t *no) {
    if (!no) return -1;
    return no->altura;
}

no_arvore_t *criar_no(int valor) {
    no_arvore_t *novo = (no_arvore_t*)malloc(sizeof(no_arvore_t));
    novo->valor = valor;
    novo->altura = 0;
    novo->esquerda = novo->direita = NULL;
    return novo;
}

int fator_balanceamento(no_arvore_t *no) {
    if (!no) return 0;
    return altura(no->esquerda) - altura(no->direita);
}

no_arvore_t *rotacao_direita(no_arvore_t *y) {
    no_arvore_t *x = y->esquerda;
    no_arvore_t *T2 = x->direita;
    x->direita = y;
    y->esquerda = T2;
    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;
    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;
    return x;
}

no_arvore_t *rotacao_esquerda(no_arvore_t *x) {
    no_arvore_t *y = x->direita;
    no_arvore_t *T2 = y->esquerda;
    y->esquerda = x;
    x->direita = T2;
    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;
    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;
    return y;
}

no_arvore_t *balancear(no_arvore_t *no) {
    int fb = fator_balanceamento(no);

    if (fb > 1 && fator_balanceamento(no->esquerda) >= 0)
        return rotacao_direita(no);

    if (fb > 1 && fator_balanceamento(no->esquerda) < 0) {
        no->esquerda = rotacao_esquerda(no->esquerda);
        return rotacao_direita(no);
    }

    if (fb < -1 && fator_balanceamento(no->direita) <= 0)
        return rotacao_esquerda(no);

    if (fb < -1 && fator_balanceamento(no->direita) > 0) {
        no->direita = rotacao_direita(no->direita);
        return rotacao_esquerda(no);
    }

    return no;
}

no_arvore_t *inserir_valor(no_arvore_t *raiz, int valor) {
    if (!raiz) return criar_no(valor);

    if (valor < raiz->valor)
        raiz->esquerda = inserir_valor(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = inserir_valor(raiz->direita, valor);
    else
        return raiz;

    raiz->altura = max(altura(raiz->esquerda), altura(raiz->direita)) + 1;

    return balancear(raiz);
}

no_arvore_t *menor_no(no_arvore_t *no) {
    no_arvore_t *atual = no;
    while (atual->esquerda)
        atual = atual->esquerda;
    return atual;
}

no_arvore_t *remover_valor(no_arvore_t *raiz, int valor) {
    if (!raiz) return raiz;

    if (valor < raiz->valor)
        raiz->esquerda = remover_valor(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = remover_valor(raiz->direita, valor);
    else {
        if (!raiz->esquerda || !raiz->direita) {
            no_arvore_t *temp = raiz->esquerda ? raiz->esquerda : raiz->direita;
            if (!temp) {
                temp = raiz;
                raiz = NULL;
            } else {
                *raiz = *temp;
            }
            free(temp);
        } else {
            no_arvore_t *temp = menor_no(raiz->direita);
            raiz->valor = temp->valor;
            raiz->direita = remover_valor(raiz->direita, temp->valor);
        }
    }

    if (!raiz) return raiz;

    raiz->altura = max(altura(raiz->esquerda), altura(raiz->direita)) + 1;

    return balancear(raiz);
}

bool busca(no_arvore_t *raiz, int valor) {
    if (!raiz) return false;
    if (valor == raiz->valor) return true;
    if (valor < raiz->valor) return busca(raiz->esquerda, valor);
    return busca(raiz->direita, valor);
}

void pre_ordem(no_arvore_t *raiz) {
    if (!raiz) return;
    printf("%d ", raiz->valor);
    pre_ordem(raiz->esquerda);
    pre_ordem(raiz->direita);
}

void em_ordem(no_arvore_t *raiz) {
    if (!raiz) return;
    em_ordem(raiz->esquerda);
    printf("%d ", raiz->valor);
    em_ordem(raiz->direita);
}

void pos_ordem(no_arvore_t *raiz) {
    if (!raiz) return;
    pos_ordem(raiz->esquerda);
    pos_ordem(raiz->direita);
    printf("%d ", raiz->valor);
}

typedef struct fila {
    no_arvore_t *no;
    struct fila *prox;
} fila_t;

void enfileirar(fila_t **ini, fila_t **fim, no_arvore_t *no) {
    fila_t *novo = malloc(sizeof(fila_t));
    novo->no = no;
    novo->prox = NULL;
    if (!*ini) *ini = novo;
    else (*fim)->prox = novo;
    *fim = novo;
}

no_arvore_t *desenfileirar(fila_t **ini) {
    fila_t *temp = *ini;
    no_arvore_t *no = temp->no;
    *ini = temp->prox;
    free(temp);
    return no;
}

void largura(no_arvore_t *raiz) {
    if (!raiz) return;
    fila_t *ini = NULL, *fim = NULL;
    enfileirar(&ini, &fim, raiz);
    while (ini) {
        no_arvore_t *no = desenfileirar(&ini);
        printf("%d ", no->valor);
        if (no->esquerda) enfileirar(&ini, &fim, no->esquerda);
        if (no->direita) enfileirar(&ini, &fim, no->direita);
    }
}

void destruir_arvore(no_arvore_t *raiz) {
    if (!raiz) return;
    destruir_arvore(raiz->esquerda);
    destruir_arvore(raiz->direita);
    free(raiz);
}

