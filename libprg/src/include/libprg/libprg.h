#ifndef LIBPRG_H
#define LIBPRG_H

typedef struct pilha {
    int *elementos;
    int topo;
    int capacidade;
} pilha;

pilha* criar_pilha(int capacidade);

#endif