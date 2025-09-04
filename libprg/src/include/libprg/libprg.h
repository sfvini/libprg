#ifndef LIBPRG_H
#define LIBPRG_H

typedef struct pilha pilha_t;

pilha_t* criar(int capacidade);
int adicionar(pilha_t *p, int e);
int remover(pilha_t *p);
int topo(pilha_t *p);
int* listar(pilha_t *p);
int tamanho(pilha_t *p);
void apagar(pilha_t *p);


#endif