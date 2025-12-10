#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libprg/libprg.h"

#define max(a,b) ((a) > (b) ? (a) : (b))

typedef struct no_arvore {
    int valor;
    int altura;
    struct no_arvore *esq, *dir;
} no_arvore_t;

typedef struct fila {
    no_arvore_t *no;
    struct fila *prox;
} fila_t;

int altura_arvore(no_arvore_t *no) {
    return no ? no->altura : -1;
}

int balanceamento(no_arvore_t *no) {
    return altura_arvore(no->esq) - altura_arvore(no->dir);
}

no_arvore_t *novo_no(int valor) {
    no_arvore_t *no = malloc(sizeof(no_arvore_t));
    no->valor = valor;
    no->altura = 0;
    no->esq = no->dir = NULL;
    return no;
}

no_arvore_t *rot_dir(no_arvore_t *raiz) {
    no_arvore_t *nova_raiz = raiz->esq;
    raiz->esq = nova_raiz->dir;
    nova_raiz->dir = raiz;
    raiz->altura = max(altura_arvore(raiz->esq), altura_arvore(raiz->dir)) + 1;
    nova_raiz->altura = max(altura_arvore(nova_raiz->esq), altura_arvore(nova_raiz->dir)) + 1;
    return nova_raiz;
}

no_arvore_t *rot_esq(no_arvore_t *raiz) {
    no_arvore_t *nova_raiz = raiz->dir;
    raiz->dir = nova_raiz->esq;
    nova_raiz->esq = raiz;
    raiz->altura = max(altura_arvore(raiz->esq), altura_arvore(raiz->dir)) + 1;
    nova_raiz->altura = max(altura_arvore(nova_raiz->esq), altura_arvore(nova_raiz->dir)) + 1;
    return nova_raiz;
}

no_arvore_t *balancear(no_arvore_t *raiz) {
    int f = balanceamento(raiz);
    if (f > 1 && balanceamento(raiz->esq) >= 0) return rot_dir(raiz);
    if (f > 1 && balanceamento(raiz->esq) < 0) {
        raiz->esq = rot_esq(raiz->esq);
        return rot_dir(raiz);
    }
    if (f < -1 && balanceamento(raiz->dir) <= 0) return rot_esq(raiz);
    if (f < -1 && balanceamento(raiz->dir) > 0) {
        raiz->dir = rot_dir(raiz->dir);
        return rot_esq(raiz);
    }
    return raiz;
}

no_arvore_t *inserir_arvore_avl(no_arvore_t *raiz, int valor) {
    if (!raiz) return novo_no(valor);
    if (valor < raiz->valor) raiz->esq = inserir_arvore_avl(raiz->esq, valor);
    else if (valor > raiz->valor) raiz->dir = inserir_arvore_avl(raiz->dir, valor);
    else return raiz;
    raiz->altura = max(altura_arvore(raiz->esq), altura_arvore(raiz->dir)) + 1;
    return balancear(raiz);
}

no_arvore_t *inserir_arvore_bst(no_arvore_t *raiz, int valor) {
    if (!raiz) return novo_no(valor);

    if (valor < raiz->valor)
        raiz->esq = inserir_arvore_bst(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = inserir_arvore_bst(raiz->dir, valor);

    return raiz;
}


no_arvore_t *menor_no(no_arvore_t *no) {
    while (no->esq) no = no->esq;
    return no;
}

no_arvore_t *remover_arvore_avl(no_arvore_t *raiz, int valor) {
    if (!raiz) return raiz;

    if (valor < raiz->valor) raiz->esq = remover_arvore_avl(raiz->esq, valor);
    else if (valor > raiz->valor) raiz->dir = remover_arvore_avl(raiz->dir, valor);
    else {
        if (!raiz->esq || !raiz->dir) {
            no_arvore_t *t = raiz->esq ? raiz->esq : raiz->dir;
            free(raiz);
            return t;
        }
        no_arvore_t *t = menor_no(raiz->dir);
        raiz->valor = t->valor;
        raiz->dir = remover_arvore_avl(raiz->dir, t->valor);
    }

    raiz->altura = max(altura_arvore(raiz->esq), altura_arvore(raiz->dir)) + 1;
    return balancear(raiz);
}

no_arvore_t *remover_arvore_bst(no_arvore_t *raiz, int valor) {
    if (!raiz) return NULL;

    if (valor < raiz->valor)
        raiz->esq = remover_arvore_bst(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = remover_arvore_bst(raiz->dir, valor);
    else {
        if (!raiz->esq || !raiz->dir) {
            no_arvore_t *t = raiz->esq ? raiz->esq : raiz->dir;
            free(raiz);
            return t;
        }
        no_arvore_t *t = menor_no(raiz->dir);
        raiz->valor = t->valor;
        raiz->dir = remover_arvore_bst(raiz->dir, t->valor);
    }
    return raiz;
}

bool busca_arvore(no_arvore_t *raiz, int valor) {
    if (!raiz) return false;
    if (valor == raiz->valor) return true;
    return busca_arvore(valor < raiz->valor ? raiz->esq : raiz->dir, valor);
}

int menor_valor_arvore(no_arvore_t *raiz) {
    if (!raiz) return -1;
    while (raiz->esq)
        raiz = raiz->esq;
    return raiz->valor;
}

int maior_valor_arvore(no_arvore_t *raiz) {
    if (!raiz) return -1;
    while (raiz->dir)
        raiz = raiz->dir;
    return raiz->valor;
}

void pre_arvore(no_arvore_t *raiz) {
    if (!raiz) return;
    printf("%d ", raiz->valor);
    pre_arvore(raiz->esq);
    pre_arvore(raiz->dir);
}

void em_arvore(no_arvore_t *raiz) {
    if (!raiz) return;
    em_arvore(raiz->esq);
    printf("%d ", raiz->valor);
    em_arvore(raiz->dir);
}

void pos_arvore(no_arvore_t *raiz) {
    if (!raiz) return;
    pos_arvore(raiz->esq);
    pos_arvore(raiz->dir);
    printf("%d ", raiz->valor);
}

void imprimir_largura(no_arvore_t *raiz) {
    if (!raiz) return;

    int altura = altura_arvore(raiz) + 1;
    int capacidade = 1 << altura;

    fila_t *fila = criar_fila(capacidade);

    no_arvore_t **buffer = malloc(sizeof(no_arvore_t*) * capacidade);

    int proximo = 1;

    buffer[0] = raiz;
    enfileirar(fila, 0);

    while (tamanho_fila(fila) > 0) {
        int index = inicio_fila(fila);
        desenfileirar(fila);

        no_arvore_t *atual = buffer[index];

        printf("%d ", atual->valor);

        if (atual->esq) {
            buffer[proximo] = atual->esq;
            enfileirar(fila, proximo);
            proximo++;
        }

        if (atual->dir) {
            buffer[proximo] = atual->dir;
            enfileirar(fila, proximo);
            proximo++;
        }
    }

    free(buffer);
    destruir_fila(fila);
}

void destruir_arvore(no_arvore_t *raiz) {
    if (!raiz) return;
    destruir_arvore(raiz->esq);
    destruir_arvore(raiz->dir);
    free(raiz);
}

int contar_nos(no_arvore_t *raiz) {
    if (!raiz) return 0;
    return 1 + contar_nos(raiz->esq) + contar_nos(raiz->dir);
}

int contar_folhas(no_arvore_t *raiz) {
    if (!raiz) return 0;
    if (!raiz->esq && !raiz->dir) return 1;
    return contar_folhas(raiz->esq) + contar_folhas(raiz->dir);
}

no_arvore_t* buscar_no_ptr(no_arvore_t *raiz, int valor) {
    if (!raiz) return NULL;
    if (valor == raiz->valor) return raiz;
    if (valor < raiz->valor) return buscar_no_ptr(raiz->esq, valor);
    return buscar_no_ptr(raiz->dir, valor);
}