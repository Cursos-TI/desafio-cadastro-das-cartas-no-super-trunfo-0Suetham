#include <stdio.h>

int main() {
    // Declaração de variáveis para a primeira carta
    char estado1[3], codigo1[4], nome1[30];
    unsigned long int populacao1;
    int pontosTuristicos1;
    float area1, pib1, densidade1, pibPerCapita1, superPoder1;

    // Declaração de variáveis para a segunda carta
    char estado2[3], codigo2[4], nome2[30];
    unsigned long int populacao2;
    int pontosTuristicos2;
    float area2, pib2, densidade2, pibPerCapita2, superPoder2;

    // Cadastro da primeira carta
    printf("Cadastro da Carta 1\n");
    printf("Informe o estado (ex: SP): ");
    scanf("%s", estado1);

    printf("Informe o código da cidade (ex: A01): ");
    scanf("%s", codigo1);

    printf("Informe o nome da cidade: ");
    scanf("%s", nome1);

    printf("População: ");
    scanf("%lu", &populacao1);

    printf("Área (em km²): ");
    scanf("%f", &area1);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);

    printf("Número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // Cálculos da primeira carta
    densidade1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000) / populacao1;
    superPoder1 = (float)populacao1 + area1 + (pib1 * 1000000000) + pontosTuristicos1 + pibPerCapita1 + (1 / densidade1);

    // Cadastro da segunda carta
    printf("\nCadastro da Carta 2\n");
    printf("Informe o estado (ex: RJ): ");
    scanf("%s", estado2);

    printf("Informe o código da cidade (ex: B02): ");
    scanf("%s", codigo2);

    printf("Informe o nome da cidade: ");
    scanf("%s", nome2);

    printf("População: ");
    scanf("%lu", &populacao2);

    printf("Área (em km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculos da segunda carta
    densidade2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;
    superPoder2 = (float)populacao2 + area2 + (pib2 * 1000000000) + pontosTuristicos2 + pibPerCapita2 + (1 / densidade2);

    // Exibição das cartas
    printf("\n--- Dados das Cartas Cadastradas ---\n");

    printf("\nCarta 1\n");
    printf("Estado: %s\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome: %s\n", nome1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Pontos turísticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);
    printf("Super Poder: %.2f\n", superPoder1);

    printf("\nCarta 2\n");
    printf("Estado: %s\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome: %s\n", nome2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Pontos turísticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);
    printf("Super Poder: %.2f\n", superPoder2);

    // Menu interativo
    int opcao;
    printf("\n--- Escolha o atributo para comparação ---\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);

    printf("\n--- Comparação ---\n");

    switch (opcao) {
        case 1:
            printf("Comparando População:\n");
            printf("%s: %lu\n", nome1, populacao1);
            printf("%s: %lu\n", nome2, populacao2);
            if (populacao1 > populacao2)
                printf("Resultado: %s venceu!\n", nome1);
            else if (populacao2 > populacao1)
                printf("Resultado: %s venceu!\n", nome2);
            else
                printf("Resultado: Empate!\n");
            break;
        case 2:
            printf("Comparando Área:\n");
            printf("%s: %.2f km²\n", nome1, area1);
            printf("%s: %.2f km²\n", nome2, area2);
            if (area1 > area2)
                printf("Resultado: %s venceu!\n", nome1);
            else if (area2 > area1)
                printf("Resultado: %s venceu!\n", nome2);
            else
                printf("Resultado: Empate!\n");
            break;
        case 3:
            printf("Comparando PIB:\n");
            printf("%s: %.2f bilhões\n", nome1, pib1);
            printf("%s: %.2f bilhões\n", nome2, pib2);
            if (pib1 > pib2)
                printf("Resultado: %s venceu!\n", nome1);
            else if (pib2 > pib1)
                printf("Resultado: %s venceu!\n", nome2);
            else
                printf("Resultado: Empate!\n");
            break;
        case 4:
            printf("Comparando Pontos Turísticos:\n");
            printf("%s: %d\n", nome1, pontosTuristicos1);
            printf("%s: %d\n", nome2, pontosTuristicos2);
            if (pontosTuristicos1 > pontosTuristicos2)
                printf("Resultado: %s venceu!\n", nome1);
            else if (pontosTuristicos2 > pontosTuristicos1)
                printf("Resultado: %s venceu!\n", nome2);
            else
                printf("Resultado: Empate!\n");
            break;
        case 5:
            printf("Comparando Densidade Demográfica:\n");
            printf("%s: %.2f hab/km²\n", nome1, densidade1);
            printf("%s: %.2f hab/km²\n", nome2, densidade2);
            if (densidade1 < densidade2)
                printf("Resultado: %s venceu!\n", nome1);
            else if (densidade2 < densidade1)
                printf("Resultado: %s venceu!\n", nome2);
            else
                printf("Resultado: Empate!\n");
            break;
        default:
            printf("Opção inválida! Por favor, escolha uma opção entre 1 e 5.\n");
    }

    return 0;
}
