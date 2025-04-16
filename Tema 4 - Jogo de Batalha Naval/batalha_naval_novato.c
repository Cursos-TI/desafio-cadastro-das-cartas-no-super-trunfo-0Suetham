#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define OCUPADO 3
#define AGUA 0

int main() {
    // ---------- Inicialização da Matriz ----------
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Preenchendo o tabuleiro com água (0)
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // ---------- Definindo os Navios ----------
    int navioHorizontal[TAM_NAVIO] = {OCUPADO, OCUPADO, OCUPADO};
    int navioVertical[TAM_NAVIO] = {OCUPADO, OCUPADO, OCUPADO};

    // ---------- Coordenadas Iniciais ----------
    int linhaHorizontal = 2;
    int colunaHorizontal = 4;

    int linhaVertical = 5;
    int colunaVertical = 7;

    // ---------- Validação Simples ----------
    // Verifica se os navios cabem no tabuleiro
    if (colunaHorizontal + TAM_NAVIO <= TAM_TABULEIRO &&
        linhaVertical + TAM_NAVIO <= TAM_TABULEIRO) {

        // Verifica se há sobreposição (opcional no nível novato)
        int sobreposicao = 0;
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaHorizontal][colunaHorizontal + i] != AGUA ||
                tabuleiro[linhaVertical + i][colunaVertical] != AGUA) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            // ---------- Posicionando os Navios ----------
            // Navio Horizontal
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaHorizontal][colunaHorizontal + i] = navioHorizontal[i];
            }

            // Navio Vertical
            for (int i = 0; i < TAM_NAVIO; i++) {
                tabuleiro[linhaVertical + i][colunaVertical] = navioVertical[i];
            }

            // ---------- Exibindo o Tabuleiro ----------
            printf("\nTabuleiro:\n\n");
            for (int i = 0; i < TAM_TABULEIRO; i++) {
                for (int j = 0; j < TAM_TABULEIRO; j++) {
                    printf("%d ", tabuleiro[i][j]);
                }
                printf("\n");
            }

        } else {
            printf("Erro: Os navios se sobrepõem!\n");
        }

    } else {
        printf("Erro: Um dos navios ultrapassa os limites do tabuleiro!\n");
    }

    return 0;
}
