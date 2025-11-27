#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *cpf;
    char *nome;
    char *email;
} pessoa_t;

typedef struct no {
    char *chave;
    pessoa_t *valor;
    struct no *prox;
} no_t;

typedef struct dicionario {
    int tamanho;
    no_t **vetor;
} dicionario_t;

dicionario_t *criar_dicionario(int m) {
    dicionario_t *d = NULL;
    if (m < 1) {
        return NULL;
    }
    if ((d = (dicionario_t *)malloc(sizeof(dicionario_t))) == NULL) {
        return NULL;
    }
    d->tamanho = m;
    if ((d->vetor = calloc(m, sizeof(no_t *))) == NULL) {
        return NULL;
    }
    for (int i = 0; i < m; ++i) {
        d->vetor[i] = NULL;
    }
    return d;
}

void destruir_pessoa(pessoa_t *pessoa) {
    if (pessoa->cpf != NULL) {
        free(pessoa->cpf);
    }
    if (pessoa->nome != NULL) {
        free(pessoa->nome);
    }
    if (pessoa->email != NULL) {
        free(pessoa->email);
    }
    free(pessoa);
}

void destruir_no(no_t *no) {
    if (no != NULL) {
        free(no->chave);
        destruir_pessoa(no->valor);
        free(no);
    }
}

void destruir_dicionario(dicionario_t *d) {
    if (d != NULL) {
        for (int i = 0; i < d->tamanho; ++i) {
            destruir_no(d->vetor[i]);
        }
        free(d->vetor);
        free(d);
    }
}

int hash(const char *chave, int m) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        soma += (i + 1) * chave[i];
    }
    return soma % m;
}

bool inserir_dicionario(dicionario_t *d, char *chave, pessoa_t *valor) {
    int indice = hash(chave, d->tamanho);
    no_t *no = malloc(sizeof(no_t));
    if (no == NULL) {
        return false;
    }
    no->chave = strdup(chave);
    if (no->chave == NULL) {
        free(no);
        return false;
    }
    no->valor = valor;
    no->prox = NULL;
    destruir_no(d->vetor[indice]);
    d->vetor[indice] = no;
    return true;
}

pessoa_t *buscar_dicionario(dicionario_t *d, char *chave) {
    int indice = hash(chave, d->tamanho);
    if (d->vetor[indice] != NULL) {
        if (strcmp(d->vetor[indice]->chave, chave) == 0) {
            return d->vetor[indice]->valor;
        }
    }
    return NULL;
}

void imprimir_pessoa(dicionario_t *d, char *chave) {
    pessoa_t *p = buscar_dicionario(d, chave);
    if (p != NULL) {
        printf("CPF: %s\tNome: %s\tEmail: %s\n", p->cpf, p->nome, p->email);
    } else {
        printf("Pessoa com CPF %s não encontrada\n", chave);
    }
}