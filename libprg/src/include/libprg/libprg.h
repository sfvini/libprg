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

//LISTA
typedef struct lista lista_t;
lista_t *criar_lista(int capacidade, bool ordenada);
int tamanho_lista(lista_t *l);
int obter_elemento_lista(lista_t *l, int indice);
int buscar_lista(lista_t *l, int valor);
void inserir_lista(lista_t *l, int valor);
void apagar_lista(lista_t *l);
void excluir_item_lista(lista_t *l, int valor);
void listar_lista(lista_t *l);

//LISTA ENCADEADA
typedef struct no no_t;
no_t* criar_lista_encadeada(int valor);
no_t* adicionar_lista_encadeada(no_t* inicio, int valor);

#endif