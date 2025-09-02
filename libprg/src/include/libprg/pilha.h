#ifndef PILHA_H
#define PILHA_H

typedef struct pilha {
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