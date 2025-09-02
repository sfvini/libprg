#include <stdlib.h>
#include <libprg/pilha.h>

pilha* criar(int capacidade) {
    pilha *p = malloc(sizeof(pilha));
    p->elementos = malloc(sizeof(int) * capacidade);
    p->topo = -1;
    p->capacidade = capacidade;
    return p;
}

int adicionar(pilha *p, int e) {
    if (p->topo < p->capacidade - 1) {
        p->topo++;
        p->elementos[p->topo] = e;
        return 1;
    } else {
        return 0;
    }
}

int remover(pilha *p) {
    if (p->topo >= 0) {
        int elemento = p->elementos[p->topo];
        p->topo--;
        return elemento;
    }
    else {
        return -1;
    }
}

int topo(pilha *p) {
    if (p->topo >= 0) {
        return p->elementos[p->topo];
    } else {
        return -1;
    }
}

int* listar(pilha *p) {
    int* cc = malloc(sizeof(int) * (p->topo + 1));
    for (int i = 0; i <= p->topo; i++) {
        cc[i] = p->elementos[i];
    }
    return cc;
}

int tamanho(pilha *p) {
    return p->topo + 1;
}

void apagar(pilha *p) {
    free(p->elementos);
    free(p);
}