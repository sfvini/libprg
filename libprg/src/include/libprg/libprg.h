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

lista_linear_t *criar_lista_linear(int capacidade, bool ordenada);
int tamanho_lista_linear(lista_linear_t *l);
int obter_elemento_lista_linear(lista_linear_t *l, int indice);
int busca_lista_linear(lista_linear_t *l, int valor);
void inserir_lista_linear(lista_linear_t *l, int valor);
void apagar_lista_linear(lista_linear_t *l);
void excluir_item_lista_linear(lista_linear_t *l, int valor);
void listar_lista_linear(lista_linear_t *l);

//LISTA ENCADEADA
typedef struct no no_t;

no_t* criar_lista_encadeada(int valor);
void adicionar_lista_encadeada(no_t** inicio, int valor);

no_t* criar_lista_encadeada_circular(int valor);
void adicionar_lista_encadeada_circular(no_t** inicio, int valor);

no_t* buscar_lista_encadeada(no_t** inicio, int valor);
void remover_item_lista_encadeada(no_t** inicio, int valor);
void destruir_lista_encadeada(no_t** inicio);

#endif