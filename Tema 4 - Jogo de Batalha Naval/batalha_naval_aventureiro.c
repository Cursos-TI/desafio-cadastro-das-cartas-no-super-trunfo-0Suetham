#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define AGUA 0
#define OCUPADO 3

// Função para verificar se a posição está livre para o navio
int podePosicionar(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha;
        int c = coluna;

        if (diagonal == 1) {          // Diagonal principal (↘)
            l += i;
            c += i;
        } else if (diagonal == 2) {   // Diagonal secundária (↙)
            l += i;
            c -= i;
        } else if (direcao == 0) {    // Horizontal →
            c += i;
        } else if (direcao == 1) {    // Vertical ↓
            l += i;
        }

        // Verifica limites e se já está ocupado
        if (l >= TAM_TABULEIRO || c >= TAM_TABULEIRO || l < 0 || c < 0 || tabuleiro[l][c] == OCUPADO) {
            return 0;
        }
    }

    return 1;
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int direcao, int diagonal) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha;
        int c = coluna;

        if (diagonal == 1) {          // Diagonal principal (↘)
            l += i;
            c += i;
        } else if (diagonal == 2) {   // Diagonal secundária (↙)
            l += i;
            c -= i;
        } else if (direcao == 0) {    // Horizontal →
            c += i;
        } else if (direcao == 1) {    // Vertical ↓
            l += i;
        }

        tabuleiro[l][c] = OCUPADO;
    }
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("\nTabuleiro:\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa com água
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Coordenadas dos navios
    // Horizontal (linha 0, coluna 0)
    if (podePosicionar(tabuleiro, 0, 0, 0, 0)) {
        posicionarNavio(tabuleiro, 0, 0, 0, 0);
    }

    // Vertical (linha 2, coluna 5)
    if (podePosicionar(tabuleiro, 2, 5, 1, 0)) {
        posicionarNavio(tabuleiro, 2, 5, 1, 0);
    }

    // Diagonal ↘ (linha 4, coluna 1)
    if (podePosicionar(tabuleiro, 4, 1, 0, 1)) {
        posicionarNavio(tabuleiro, 4, 1, 0, 1);
    }

    // Diagonal ↙ (linha 1, coluna 8)
    if (podePosicionar(tabuleiro, 1, 8, 0, 2)) {
        posicionarNavio(tabuleiro, 1, 8, 0, 2);
    }

    // Exibe o tabuleiro final
    imprimirTabuleiro(tabuleiro);

    return 0;
}
