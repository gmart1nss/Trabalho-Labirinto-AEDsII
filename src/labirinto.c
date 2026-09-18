#include <stdio.h>
#include "labirinto.h"

/*Lê o labirinto a partir de um arquivo e coloca os caracteres na matriz*/
void ler_labirinto(char labirinto[TAMANHO][TAMANHO], const char *nome_arquivo) {
    FILE *arquivo;

    int linha, coluna;

    arquivo = fopen(nome_arquivo, "r");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nome_arquivo);
        return;
    }

    /*percorre as posições da matriz*/
    for (linha = 0; linha < TAMANHO; linha++) {
        for (coluna = 0; coluna < TAMANHO; coluna++) {
            fscanf(arquivo, " %c", &labirinto[linha][coluna]);
        }
    }

    fclose(arquivo);
}

/*Imprime o labirinto no terminal*/
void imprimir_labirinto(char labirinto[TAMANHO][TAMANHO]) {

    int linha, coluna;

    for (linha = 0; linha < TAMANHO; linha++) {
        for (coluna = 0; coluna < TAMANHO; coluna++) {
            printf("%c ", labirinto[linha][coluna]);
        }
        printf("\n");
    }
}

/*Procura a entrada E do labirinto e retorna a posição dela */
struct posicao encontrar_entrada(char labirinto[TAMANHO][TAMANHO]) {

    struct posicao posicao;

    int linha, coluna;

    posicao.linha = -1;
    posicao.coluna = -1;

    for (linha = 0; linha < TAMANHO; linha++) {
        for (coluna = 0; coluna < TAMANHO; coluna++) {
            if (labirinto[linha][coluna] == 'E') {
                posicao.linha = linha;
                posicao.coluna = coluna;

                return posicao;
            }
        }
    }

    return posicao;
}

/*Procura a saída S do labirinto e retorna a posição dela */
struct posicao encontrar_saida(char labirinto[TAMANHO][TAMANHO]) {

    struct posicao posicao;

    int linha, coluna;

    posicao.linha = -1;
    posicao.coluna = -1;

    for (linha = 0; linha < TAMANHO; linha++) {
        for (coluna = 0; coluna < TAMANHO; coluna++) {
            if (labirinto[linha][coluna] == 'S') {
                posicao.linha = linha;
                posicao.coluna = coluna;

                return posicao;
            }
        }
    }

    return posicao;
}