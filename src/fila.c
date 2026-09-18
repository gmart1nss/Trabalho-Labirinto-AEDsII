#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct fila criar_fila(void) {
    struct fila fila;
    fila.frente = NULL;
    fila.fundo = NULL;
    return fila;
}

bool ehVazia(struct fila fila) {
    return (fila.frente == NULL);
}

struct fila enfileirar(struct fila fila, struct posicao posicao) {

    struct no *novo = (struct no *)malloc(sizeof(struct no));

    if (novo == NULL) {
        printf("Erro ao alocar memória para o novo nó.\n");
        return fila;
    }

    novo->posicao = posicao;
    novo->proximo = NULL;

    if (ehVazia(fila)) {
        fila.frente = novo;
        fila.fundo = novo;
    } else {
        fila.fundo->proximo = novo;
        fila.fundo = novo;
    }

    return fila;
}

struct fila desenfileirar(struct fila fila, struct posicao *posicao) {

    struct no *aux;

    if (ehVazia(fila)) {
        return fila;
    }

    aux = fila.frente;

    *posicao = aux->posicao;
    
    fila.frente = fila.frente->proximo;

    if (fila.frente == NULL) {
        fila.fundo = NULL;
    }

    free(aux);

    return fila;
}
