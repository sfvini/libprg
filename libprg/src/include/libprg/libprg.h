#ifndef LIBPRG_H
#define LIBPRG_H

typedef struct libprg {
    int *elementos;
    int topo;
    int capacidade;
} pilha;

pilha* criar(int capacidade);
int adicionar(pilha *p, int e);
int remover(pilha *p);
int topo(pilha *p);
int* listar(pilha *p);
int tamanho(pilha *p);
void apagar(pilha *p);


#endif