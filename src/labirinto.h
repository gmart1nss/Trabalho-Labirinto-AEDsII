#ifndef LABIRINTO_H
#define LABIRINTO_H

#include "posicao.h"

#define TAMANHO 10

void ler_labirinto(char labirinto[TAMANHO][TAMANHO], const char *nome_arquivo);

void imprimir_labirinto(char labirinto[TAMANHO][TAMANHO]);

struct posicao encontrar_entrada(char labirinto[TAMANHO][TAMANHO]);

struct posicao encontrar_saida(char labirinto[TAMANHO][TAMANHO]);

#endif