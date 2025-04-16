#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define OCUPADO 3
#define AGUA 0
#define HABILIDADE 5
#define TAM_HABILIDADE 5

// Função para inicializar o tabuleiro com 0 (água)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Posiciona navios fixos no tabuleiro
void posicionarNavios(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    // Navio horizontal
    int linha1 = 1, coluna1 = 2;
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha1][coluna1 + i] = OCUPADO;
    }

    // Navio vertical
    int linha2 = 3, coluna2 = 5;
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha2 + i][coluna2] = OCUPADO;
    }

    // Navio diagonal \ (linha == coluna)
    int linha3 = 6, coluna3 = 6;
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha3 + i][coluna3 + i] = OCUPADO;
    }

    // Navio diagonal / (linha + coluna == constante)
    int linha4 = 0, coluna4 = 9;
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha4 + i][coluna4 - i] = OCUPADO;
    }
}

// Função para aplicar matriz de habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origemX, int origemY) {
    int offset = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int tabX = origemX - offset + i;
            int tabY = origemY - offset + j;

            if (tabX >= 0 && tabX < TAM_TABULEIRO && tabY >= 0 && tabY < TAM_TABULEIRO) {
                if (habilidade[i][j] == 1 && tabuleiro[tabX][tabY] == AGUA) {
                    tabuleiro[tabX][tabY] = HABILIDADE;
                }
            }
        }
    }
}

// Constrói habilidade cone
void construirCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (j >= TAM_HABILIDADE / 2 - i && j <= TAM_HABILIDADE / 2 + i) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Constrói habilidade cruz
void construirCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Constrói habilidade octaedro (losango)
void construirOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - TAM_HABILIDADE / 2) + abs(j - TAM_HABILIDADE / 2) <= TAM_HABILIDADE / 2) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

    construirCone(cone);
    construirCruz(cruz);
    construirOctaedro(octaedro);

    aplicarHabilidade(tabuleiro, cone, 2, 2);        // Cone aplicado em (2,2)
    aplicarHabilidade(tabuleiro, cruz, 5, 5);        // Cruz aplicado em (5,5)
    aplicarHabilidade(tabuleiro, octaedro, 8, 8);    // Octaedro em (8,8)

    printf("TABULEIRO COM NAVIOS E HABILIDADES:\n\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
