#include <stdlib.h>
#include <libprg/libprg.h>

typedef struct pilha {
    int *elementos;
    int topo;
    int capacidade;
} pilha_t;

pilha_t* criar(int capacidade) {
    pilha_t *p = malloc(sizeof(pilha_t));
    p->elementos = malloc(sizeof(int) * capacidade);
    p->topo = -1;
    p->capacidade = capacidade;
    return p;
}

int adicionar(pilha_t *p, int e) {
    if (p->topo < p->capacidade - 1) {
        p->topo++;
        p->elementos[p->topo] = e;
        return 1;
    } else {
        return 0;
    }
}

int remover(pilha_t *p) {
    if (p->topo >= 0) {
        int elemento = p->elementos[p->topo];
        p->topo--;
        return elemento;
    }
    else {
        return -1;
    }
}

int topo(pilha_t *p) {
    if (p->topo >= 0) {
        return p->elementos[p->topo];
    } else {
        return -1;
    }
}

int* listar(pilha_t *p) {
    int* cc = malloc(sizeof(int) * (p->topo + 1));
    for (int i = 0; i <= p->topo; i++) {
        cc[i] = p->elementos[i];
    }
    return cc;
}

int tamanho(pilha_t *p) {
    return p->topo + 1;
}

void apagar(pilha_t *p) {
    free(p->elementos);
    free(p);
}
