#include <stdlib.h>
#include <libprg/libprg.h>

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