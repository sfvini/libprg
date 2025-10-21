#ifndef LIBPRG_H
#define LIBPRG_H

#include <stdbool.h>

// PILHA
typedef struct pilha pilha_t;

pilha_t* criar_pilha(int capacidade);
int empilhar(pilha_t *p, int valor);
int desempilhar(pilha_t *p);
int topo_pilha(pilha_t *p);
int tamanho_pilha(pilha_t *p);
void listar_pilha(pilha_t *p);
void destruir_pilha(pilha_t *p);
void limpar_pilha(pilha_t *p);
void inverter_pilha(pilha_t *p);
void imprimir_topo(pilha_t *p);

// FILA
typedef struct fila fila_t;

fila_t* criar_fila(int capacidade);
int tamanho_fila(fila_t *f);
int inicio_fila(fila_t *f);
int topo_fila(fila_t *f);
void enfileirar(fila_t* f, int valor);
void desenfileirar(fila_t* f);
void listar_fila(fila_t *f);
void destruir_fila(fila_t *f);
void limpar_fila(fila_t *f);
int buscar_fila(fila_t *f, int valor);
void inverter_fila(fila_t *f);

// LISTA LINEAR
typedef struct lista_linear lista_linear_t;

lista_linear_t *criar_lista_linear(int capacidade, bool ordenada);
bool lista_linear_cheia(const lista_linear_t *ll);
bool lista_linear_vazia(const lista_linear_t *ll);
int tamanho_lista_linear(const lista_linear_t *ll);
int busca_binaria(const lista_linear_t *ll, int valor);
int busca_linear(const lista_linear_t *ll, int valor);
int buscar_lista_linear(const lista_linear_t *ll, int valor);
int buscar_por_indice_lista_linear(const lista_linear_t *ll, int indice);
void listar_lista_linear(const lista_linear_t *ll);
void inserir_ordenada(lista_linear_t *ll, int valor);
void inserir_nao_ordenada(lista_linear_t *ll, int valor);
void inserir_lista_linear(lista_linear_t *ll, int valor);
void inserir_em_indice_lista_linear(lista_linear_t *ll, int indice, int valor);
void excluir_item_ordenada(lista_linear_t *ll, int valor);
void excluir_item_nao_ordenada(lista_linear_t *ll, int valor);
void excluir_item_lista_linear(lista_linear_t *ll, int valor);
void excluir_em_indice_lista_linear(lista_linear_t *ll, int indice);
void excluir_duplicatas_lista_linear(lista_linear_t *ll);
void substituir_em_indice_lista_linear(lista_linear_t *ll, int indice, int valor);
void inverter_lista_linear(lista_linear_t *ll);
void limpar_lista_linear(lista_linear_t *ll);
void destruir_lista_linear(lista_linear_t *ll);

// LISTA ENCADEADA
typedef struct no no_t;

no_t* criar_lista_encadeada(int valor);
no_t* criar_lista_encadeada_circular(int valor);
void inserir_lista_encadeada(no_t** inicio, int valor);
void inserir_lista_encadeada_circular(no_t** inicio, int valor);
void listar_lista_encadeada(no_t* inicio);
void listar_lista_encadeada_circular(no_t* inicio);
no_t* buscar_lista_encadeada(no_t** inicio, int valor);
int buscar_por_indice_lista_encadeada(no_t* inicio, int indice);
bool lista_encadeada_vazia(no_t* inicio);
int tamanho_lista_encadeada(no_t* inicio);
void substituir_em_indice_lista_encadeada(no_t* inicio, int indice, int valor);
void inverter_lista_encadeada(no_t** inicio);
void excluir_item_lista_encadeada(no_t** inicio, int valor);
void excluir_em_indice_lista_encadeada(no_t** inicio, int indice);
void limpar_lista_encadeada(no_t** inicio);
void destruir_lista_encadeada(no_t** inicio);

// LISTA ENCADEADA DUPLA
typedef struct no_duplo no_duplo_t;

no_duplo_t* criar_lista_encadeada_dupla(int valor);
void inserir_lista_encadeada_dupla(no_duplo_t** inicio, int valor);
no_duplo_t* buscar_lista_encadeada_dupla(no_duplo_t* inicio, int valor);
int buscar_por_indice_lista_encadeada_dupla(no_duplo_t* inicio, int indice);
void listar_lista_encadeada_dupla(no_duplo_t* inicio);
void substituir_em_indice_lista_encadeada_dupla(no_duplo_t* inicio, int indice, int valor);
void inverter_lista_encadeada_dupla(no_duplo_t** inicio);
int tamanho_lista_encadeada_dupla(no_duplo_t* inicio);
bool lista_encadeada_dupla_vazia(no_duplo_t* inicio);
void excluir_item_lista_encadeada_dupla(no_duplo_t** inicio, int valor);
void excluir_em_indice_lista_encadeada_dupla(no_duplo_t** inicio, int indice);
void destruir_lista_encadeada_dupla(no_duplo_t** inicio);

#endif
