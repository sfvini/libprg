#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int altura_arvore(no_arvore_t *n) {
    return n ? n->altura : -1;
}

int fb(no_arvore_t *n) {
    return altura_arvore(n->esq) - altura_arvore(n->dir);
}

no_arvore_t *novo_no(int v) {
    no_arvore_t *n = malloc(sizeof(no_arvore_t));
    n->valor = v;
    n->altura = 0;
    n->esq = n->dir = NULL;
    return n;
}

no_arvore_t *rot_dir(no_arvore_t *y) {
    no_arvore_t *x = y->esq;
    y->esq = x->dir;
    x->dir = y;
    y->altura = max(altura_arvore(y->esq), altura_arvore(y->dir)) + 1;
    x->altura = max(altura_arvore(x->esq), altura_arvore(x->dir)) + 1;
    return x;
}

no_arvore_t *rot_esq(no_arvore_t *x) {
    no_arvore_t *y = x->dir;
    x->dir = y->esq;
    y->esq = x;
    x->altura = max(altura_arvore(x->esq), altura_arvore(x->dir)) + 1;
    y->altura = max(altura_arvore(y->esq), altura_arvore(y->dir)) + 1;
    return y;
}

no_arvore_t *balancear(no_arvore_t *r) {
    int f = fb(r);
    if (f > 1 && fb(r->esq) >= 0) return rot_dir(r);
    if (f > 1 && fb(r->esq) < 0) {
        r->esq = rot_esq(r->esq);
        return rot_dir(r);
    }
    if (f < -1 && fb(r->dir) <= 0) return rot_esq(r);
    if (f < -1 && fb(r->dir) > 0) {
        r->dir = rot_dir(r->dir);
        return rot_esq(r);
    }
    return r;
}

no_arvore_t *inserir_arvore(no_arvore_t *r, int v) {
    if (!r) return novo_no(v);
    if (v < r->valor) r->esq = inserir_arvore(r->esq, v);
    else if (v > r->valor) r->dir = inserir_arvore(r->dir, v);
    else return r;
    r->altura = max(altura_arvore(r->esq), altura_arvore(r->dir)) + 1;
    return balancear(r);
}

no_arvore_t *menor_no(no_arvore_t *n) {
    while (n->esq) n = n->esq;
    return n;
}

no_arvore_t *remover_arvore(no_arvore_t *r, int v) {
    if (!r) return r;

    if (v < r->valor) r->esq = remover_arvore(r->esq, v);
    else if (v > r->valor) r->dir = remover_arvore(r->dir, v);
    else {
        if (!r->esq || !r->dir) {
            no_arvore_t *t = r->esq ? r->esq : r->dir;
            free(r);
            return t;
        }
        no_arvore_t *t = menor_no(r->dir);
        r->valor = t->valor;
        r->dir = remover_arvore(r->dir, t->valor);
    }

    r->altura = max(altura_arvore(r->esq), altura_arvore(r->dir)) + 1;
    return balancear(r);
}

bool busca_arvore(no_arvore_t *r, int v) {
    if (!r) return false;
    if (v == r->valor) return true;
    return busca_arvore(v < r->valor ? r->esq : r->dir, v);
}

void pre_arvore(no_arvore_t *r) {
    if (!r) return;
    printf("%d ", r->valor);
    pre_arvore(r->esq);
    pre_arvore(r->dir);
}

void em_arvore(no_arvore_t *r) {
    if (!r) return;
    em_arvore(r->esq);
    printf("%d ", r->valor);
    em_arvore(r->dir);
}

void pos_arvore(no_arvore_t *r) {
    if (!r) return;
    pos_arvore(r->esq);
    pos_arvore(r->dir);
    printf("%d ", r->valor);
}

void enfileirar(fila_t **i, fila_t **f, no_arvore_t *n) {
    fila_t *o = malloc(sizeof(fila_t));
    o->no = n;
    o->prox = NULL;
    if (!*i) *i = o;
    else (*f)->prox = o;
    *f = o;
}

no_arvore_t *desenfileirar(fila_t **i) {
    fila_t *t = *i;
    no_arvore_t *n = t->no;
    *i = t->prox;
    free(t);
    return n;
}

void largura_arvore(no_arvore_t *r) {
    if (!r) return;
    fila_t *i = NULL, *f = NULL;
    enfileirar(&i, &f, r);
    while (i) {
        no_arvore_t *n = desenfileirar(&i);
        printf("%d ", n->valor);
        if (n->esq) enfileirar(&i, &f, n->esq);
        if (n->dir) enfileirar(&i, &f, n->dir);
    }
}

void destruir_arvore(no_arvore_t *r) {
    if (!r) return;
    destruir_arvore(r->esq);
    destruir_arvore(r->dir);
    free(r);
}
