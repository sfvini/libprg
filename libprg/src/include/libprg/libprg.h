#ifndef LIBPRG_H
#define LIBPRG_H
#include <stdbool.h>

//PILHA
typedef struct pilha pilha_t;
pilha_t* criar_pilha(int capacidade);
int empilhar(pilha_t *p, int valor);
int desempilhar(pilha_t *p);
int topo_pilha(pilha_t *p);
int tamanho_pilha(pilha_t *p);
void listar_pilha(pilha_t *p);
void apagar_pilha(pilha_t *p);

//FILA
typedef struct fila fila_t;
fila_t* criar_fila(int capacidade);
int tamanho_fila(fila_t *f);
int inicio_fila(fila_t *f);
int fim_fila(fila_t *f);
void enfileirar(fila_t* f, int valor);
void desenfileirar(fila_t* f);
void listar_fila(fila_t *f);
void apagar_fila(fila_t *f);
bool fila_cheia(fila_t* f);
bool fila_vazia(fila_t* f);

//LISTA LINEAR
typedef struct lista_linear lista_linear_t;
lista_linear_t *criar_lista_linear(int capacidade);
int buscar_lista_linear(lista_linear_t *ll, int indice);
int tamanho_lista_linear(lista_linear_t *ll);
void inserir_lista_linear(lista_linear_t *ll, int valor);
void apagar_lista_linear(lista_linear_t *ll);
void excluir_elemento_lista_linear(lista_linear_t *ll);
void listar_lista_linear(lista_linear_t *ll);
bool lista_linear_cheia(lista_linear_t *ll);
bool lista_linear_vazia(lista_linear_t *ll);

#endif