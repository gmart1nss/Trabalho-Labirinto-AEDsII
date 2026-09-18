#ifndef FILA_H
#define FILA_H

#include <stdbool.h>
#include "posicao.h"

struct no {
    struct posicao posicao;
    struct no *proximo;
};

struct fila {
    struct no *frente;
    struct no *fundo;
};

struct fila criar_fila(void);

bool ehVazia(struct fila fila);

struct fila enfileirar(struct fila fila, struct posicao posicao);

struct fila desenfileirar(struct fila fila, struct posicao *posicao);

#endif