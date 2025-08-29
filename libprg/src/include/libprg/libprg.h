#ifndef LIBPRG_H
#define LIBPRG_H

typedef struct pilha {
    int *elementos;
    int topo;
    int capacidade;
} pilha;

pilha* criar(int capacidade);
int adicionar(pilha* pilha, int* e);

#endif