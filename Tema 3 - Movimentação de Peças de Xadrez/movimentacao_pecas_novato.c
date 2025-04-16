#include <stdio.h>

int main() {
    // -------------------- TORRE --------------------
    // A Torre se move em linha reta, neste caso, 5 casas para a direita
    int movimentosTorre = 5;
    printf("Movimento da Torre (5 casas para a direita):\n");

    for (int i = 1; i <= movimentosTorre; i++) {
        printf("Direita\n");
    }

    // -------------------- BISPO --------------------
    // O Bispo se move na diagonal, neste caso, 5 casas para cima e à direita
    int movimentosBispo = 5;
    int i = 1;
    printf("\nMovimento do Bispo (5 casas na diagonal para cima e à direita):\n");

    while (i <= movimentosBispo) {
        printf("Cima Direita\n");
        i++;
    }

    // -------------------- RAINHA --------------------
    // A Rainha se move em todas as direções. Neste caso, 8 casas para a esquerda
    int movimentosRainha = 8;
    int contador = 1;
    printf("\nMovimento da Rainha (8 casas para a esquerda):\n");

    do {
        printf("Esquerda\n");
        contador++;
    } while (contador <= movimentosRainha);

    return 0;
}
