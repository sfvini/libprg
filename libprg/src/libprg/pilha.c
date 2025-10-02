#include <stdlib.h>
#include <stdio.h>
#include <libprg/libprg.h>

typedef struct pilha {
    int *elementos;
    int topo;
    int capacidade;
} pilha_t;

pilha_t* criar_pilha(int capacidade) {
    pilha_t *p = malloc(sizeof(pilha_t));
    p->elementos = malloc(sizeof(int) * capacidade);
    p->topo = -1;
    p->capacidade = capacidade;
    return p;
}

int empilhar(pilha_t *p, int valor) {
    if (p->topo < p->capacidade - 1) {
        p->topo++;
        p->elementos[p->topo] = valor;
        return 1;
    }
    return 0;
}

int desempilhar(pilha_t *p) {
    if (p->topo >= 0) {
        int valor = p->elementos[p->topo];
        p->topo--;
        return valor;
    }
    return -1;
}

int topo_pilha(pilha_t *p) {
    if (p->topo >= 0) {
        return p->elementos[p->topo];
    }
    return -1;
}

int tamanho_pilha(pilha_t *p) {
    return p->topo + 1;
}

void listar_pilha(pilha_t *p) {
    if (p->topo < 0) {
        printf("A pilha está vazia.\n");
        return;
    }
    printf("Elementos da pilha: ");
    for (int i = 0; i <= p->topo; i++) {
        printf("%d ", p->elementos[i]);
    }
    printf("\n");
}

void destruir_pilha(pilha_t *p) {
    free(p->elementos);
    free(p);
}
