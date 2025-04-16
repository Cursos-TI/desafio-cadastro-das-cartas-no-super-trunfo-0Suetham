#include <stdio.h>

int main() {
    // Declaração das variáveis das cartas
    char nome1[30], nome2[30];
    unsigned long int populacao1, populacao2;
    float area1, area2, pib1, pib2, densidade1, densidade2, pibPerCapita1, pibPerCapita2;
    int pontosTuristicos1, pontosTuristicos2;

    // Entrada dos dados da Carta 1
    printf("Cadastro da Carta 1\n");
    printf("Nome do país: ");
    scanf("%s", nome1);
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área (km²): ");
    scanf("%f", &area1);
    printf("PIB (em bilhões): ");
    scanf("%f", &pib1);
    printf("Número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // Cálculo dos indicadores derivados
    densidade1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000) / populacao1;

    // Entrada dos dados da Carta 2
    printf("\nCadastro da Carta 2\n");
    printf("Nome do país: ");
    scanf("%s", nome2);
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área (km²): ");
    scanf("%f", &area2);
    printf("PIB (em bilhões): ");
    scanf("%f", &pib2);
    printf("Número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculo dos indicadores derivados
    densidade2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;

    // Exibe menu de atributos
    int opcao1, opcao2;
    float valor1_carta1 = 0, valor1_carta2 = 0;
    float valor2_carta1 = 0, valor2_carta2 = 0;

    printf("\nEscolha o primeiro atributo para comparar:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos turísticos\n");
    printf("5. Densidade demográfica\n");
    printf("6. PIB per capita\n");
    printf("Opção: ");
    scanf("%d", &opcao1);

    do {
        printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
        if (opcao1 != 1) printf("1. População\n");
        if (opcao1 != 2) printf("2. Área\n");
        if (opcao1 != 3) printf("3. PIB\n");
        if (opcao1 != 4) printf("4. Pontos turísticos\n");
        if (opcao1 != 5) printf("5. Densidade demográfica\n");
        if (opcao1 != 6) printf("6. PIB per capita\n");
        printf("Opção: ");
        scanf("%d", &opcao2);
        if (opcao1 == opcao2) {
            printf("Você não pode escolher o mesmo atributo duas vezes.\n");
        }
    } while (opcao1 == opcao2);

    // Função auxiliar para atribuir valores aos atributos selecionados
    switch (opcao1) {
        case 1: valor1_carta1 = populacao1; valor1_carta2 = populacao2; break;
        case 2: valor1_carta1 = area1; valor1_carta2 = area2; break;
        case 3: valor1_carta1 = pib1; valor1_carta2 = pib2; break;
        case 4: valor1_carta1 = pontosTuristicos1; valor1_carta2 = pontosTuristicos2; break;
        case 5: valor1_carta1 = densidade1; valor1_carta2 = densidade2; break;
        case 6: valor1_carta1 = pibPerCapita1; valor1_carta2 = pibPerCapita2; break;
        default: printf("Opção inválida.\n"); return 1;
    }

    switch (opcao2) {
        case 1: valor2_carta1 = populacao1; valor2_carta2 = populacao2; break;
        case 2: valor2_carta1 = area1; valor2_carta2 = area2; break;
        case 3: valor2_carta1 = pib1; valor2_carta2 = pib2; break;
        case 4: valor2_carta1 = pontosTuristicos1; valor2_carta2 = pontosTuristicos2; break;
        case 5: valor2_carta1 = densidade1; valor2_carta2 = densidade2; break;
        case 6: valor2_carta1 = pibPerCapita1; valor2_carta2 = pibPerCapita2; break;
        default: printf("Opção inválida.\n"); return 1;
    }

    // Regras de comparação
    float ponto1_carta1 = (opcao1 == 5) ? (1 / valor1_carta1) : valor1_carta1;
    float ponto1_carta2 = (opcao1 == 5) ? (1 / valor1_carta2) : valor1_carta2;
    float ponto2_carta1 = (opcao2 == 5) ? (1 / valor2_carta1) : valor2_carta1;
    float ponto2_carta2 = (opcao2 == 5) ? (1 / valor2_carta2) : valor2_carta2;

    float somaCarta1 = ponto1_carta1 + ponto2_carta1;
    float somaCarta2 = ponto1_carta2 + ponto2_carta2;

    // Exibição dos resultados
    printf("\n--- Comparação entre %s e %s ---\n", nome1, nome2);
    printf("Atributo 1 (opção %d): %.2f vs %.2f\n", opcao1, valor1_carta1, valor1_carta2);
    printf("Atributo 2 (opção %d): %.2f vs %.2f\n", opcao2, valor2_carta1, valor2_carta2);
    printf("Soma dos pontos: %s = %.2f | %s = %.2f\n", nome1, somaCarta1, nome2, somaCarta2);

    // Resultado final
    if (somaCarta1 > somaCarta2) {
        printf("Resultado: %s venceu!\n", nome1);
    } else if (somaCarta2 > somaCarta1) {
        printf("Resultado: %s venceu!\n", nome2);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
