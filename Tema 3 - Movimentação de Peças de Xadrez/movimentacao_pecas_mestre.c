#include <stdio.h>

// ------------------ Funções Recursivas ------------------

// Movimento da Torre: 5 casas para a direita
void moverTorre(int casas) {
    if (casas <= 0) return;
    printf("Direita\n");
    moverTorre(casas - 1);
}

// Movimento do Bispo com recursividade e loops aninhados
void moverBispoRecursivo(int casas) {
    if (casas <= 0) return;
    printf("Cima Direita\n");
    moverBispoRecursivo(casas - 1);
}

// Movimento da Rainha: 8 casas para a esquerda
void moverRainha(int casas) {
    if (casas <= 0) return;
    printf("Esquerda\n");
    moverRainha(casas - 1);
}

// ------------------ Função Principal ------------------
int main() {
    // -------- TORRE --------
    printf("Movimento da Torre (5 casas para a direita - recursivo):\n");
    moverTorre(5);

    // -------- BISPO --------
    printf("\nMovimento do Bispo (5 casas na diagonal para cima e à direita - recursivo):\n");
    moverBispoRecursivo(5);

    printf("\nMovimento do Bispo (5 casas - loops aninhados verticais e horizontais):\n");
    for (int i = 0; i < 5; i++) { // vertical
        for (int j = 0; j < 1; j++) { // horizontal, sempre 1 para simular diagonal
            printf("Cima Direita\n");
        }
    }

    // -------- RAINHA --------
    printf("\nMovimento da Rainha (8 casas para a esquerda - recursivo):\n");
    moverRainha(8);

    // -------- CAVALO --------
    printf("\nMovimento do Cavalo (duas casas para cima e uma para a direita - loops aninhados com múltiplas condições):\n");

    int verticais = 2;
    int horizontais = 1;

    for (int i = 1; i <= 3; i++) {  // Apenas controle de tentativas
        for (int j = 1; j <= 3; j++) {
            if (i == 1 && j <= verticais) {
                printf("Cima\n");
            } else if (i == 2 && j == 1) {
                printf("Direita\n");
                break; // Após mover para a direita, encerrar o movimento
            } else {
                continue; // Ignora outras combinações
            }
        }
        if (i == 2) break; // Limita o movimento a 2 verticais e 1 horizontal
    }

    return 0;
}
