#ifndef LIBPRG_H
#define LIBPRG_H
#include <stdbool.h>

typedef struct pilha pilha_t;

pilha_t* criar(int capacidade);
int adicionar(pilha_t *p, int e);
int remover(pilha_t *p);
int topo(pilha_t *p);
int* listar(pilha_t *p);
int tamanho(pilha_t *p);
void apagar(pilha_t *p);

typedef struct fila fila_t;

fila_t* criar_fila(int capacidade);
int tamanho_fila(fila_t *f);
int inicio_fila(fila_t *f);
int fim_fila(fila_t *f);
void enfileirar(fila_t* fila, int valor);
void desenfileirar(fila_t* fila);
void listar_fila(fila_t *fila);
void apagar_fila(fila_t *f);
bool cheia(fila_t* fila);
bool vazia(fila_t* fila);

#endif