#include <stdlib.h>
#include <libprg/libprg.h>

pilha* criar_pilha(int capacidade) {
    pilha *p = malloc(sizeof(pilha));
    p->elementos = malloc(sizeof(int) * capacidade);
    p->topo = -1;
    p->capacidade = capacidade;
    return p;
}
