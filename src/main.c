#include <stdio.h>
#include "labirinto.h"
#include "posicao.h"

int main(void) {
    char labirinto[TAMANHO][TAMANHO];
    struct posicao entrada;
    struct posicao saida;

    /* Lê o labirinto do arquivo */
    ler_labirinto(labirinto, "labirintos/labirinto1.txt");

    /* Mostra o labirinto na tela */
    imprimir_labirinto(labirinto);

    /* Procura a entrada e a saída */
    entrada = encontrar_entrada(labirinto);
    saida = encontrar_saida(labirinto);

    /* Mostra as posições encontradas */
    printf("\nEntrada: %d,%d\n", entrada.linha, entrada.coluna);
    printf("Saida: %d,%d\n", saida.linha, saida.coluna);

    return 0;
}