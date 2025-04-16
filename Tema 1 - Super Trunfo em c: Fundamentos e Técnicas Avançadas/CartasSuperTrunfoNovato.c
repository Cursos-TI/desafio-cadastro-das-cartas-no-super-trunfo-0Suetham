#include <stdio.h>

int main() {
    // Declaração de variáveis para a primeira carta
    char codigo1[4], nome1[30];
    int populacao1, pontosTuristicos1;
    float area1, pib1;

    // Declaração de variáveis para a segunda carta
    char codigo2[4], nome2[30];
    int populacao2, pontosTuristicos2;
    float area2, pib2;

    // Cadastro da primeira carta
    printf("Cadastro da Carta 1\n");
    printf("Informe o código da cidade (ex: A01): ");

    scanf("%s", codigo1);

    printf("Informe o nome da cidade: ");
    scanf("%s", nome1);

    printf("População: ");
    scanf("%d", &populacao1);

    printf("Área: ");
    scanf("%f", &area1);

    printf("PIB: ");
    scanf("%f", &pib1);

    printf("Número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // Cadastro da segunda carta
    printf("\nCadastro da Carta 2\n");

    printf("Informe o código da cidade (ex: B02): ");
    scanf("%s", codigo2);

    printf("Informe o nome da cidade: ");
    scanf("%s", nome2);

    printf("População: ");
    scanf("%d", &populacao2);

    printf("Área: ");
    scanf("%f", &area2);

    printf("PIB: ");
    scanf("%f", &pib2);
    
    printf("Número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // Exibição dos dados cadastrados
    printf("\n--- Dados das Cartas Cadastradas ---\n");

    printf("\nCarta 1\n");
    printf("Código: %s\n", codigo1);
    printf("Nome: %s\n", nome1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f\n", area1);
    printf("PIB: %.2f\n", pib1);
    printf("Pontos turísticos: %d\n", pontosTuristicos1);

    printf("\nCarta 2\n");
    printf("Código: %s\n", codigo2);
    printf("Nome: %s\n", nome2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f\n", area2);
    printf("PIB: %.2f\n", pib2);
    printf("Pontos turísticos: %d\n", pontosTuristicos2);

    return 0;
}