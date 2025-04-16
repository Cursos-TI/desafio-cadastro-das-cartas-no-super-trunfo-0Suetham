#include <stdio.h>

int main() {
    // -------------------- TORRE --------------------
    // A Torre se move em linha reta: 5 casas para a direita
    int movimentosTorre = 5;
    printf("Movimento da Torre (5 casas para a direita):\n");

    for (int i = 1; i <= movimentosTorre; i++) {
        printf("Direita\n");
    }

    // -------------------- BISPO --------------------
    // O Bispo se move na diagonal: 5 casas para cima e à direita
    int movimentosBispo = 5;
    int i = 1;
    printf("\nMovimento do Bispo (5 casas na diagonal para cima e à direita):\n");

    while (i <= movimentosBispo) {
        printf("Cima Direita\n");
        i++;
    }

    // -------------------- RAINHA --------------------
    // A Rainha se move em todas as direções: 8 casas para a esquerda
    int movimentosRainha = 8;
    int contador = 1;
    printf("\nMovimento da Rainha (8 casas para a esquerda):\n");

    do {
        printf("Esquerda\n");
        contador++;
    } while (contador <= movimentosRainha);

    // -------------------- CAVALO --------------------
    // O Cavalo se move em "L": duas casas para baixo e uma para a esquerda
    // Usando loops aninhados: for (externo) + while (interno)

    int movimentosVerticais = 2; // duas casas para baixo
    int movimentosHorizontais = 1; // uma casa para a esquerda

    printf("\nMovimento do Cavalo (duas casas para baixo e uma para a esquerda):\n");

    // Loop externo (for) para os movimentos verticais
    for (int j = 0; j < movimentosVerticais; j++) {
        printf("Baixo\n");

        // Loop interno (while) para o movimento horizontal (apenas na última iteração vertical)
        if (j == movimentosVerticais - 1) {
            int k = 0;
            while (k < movimentosHorizontais) {
                printf("Esquerda\n");
                k++;
            }
        }
    }

    return 0;
}
