#include <stdio.h>

#define MAX_CIDADES 100

// Estrutura para armazenar os dados da cidade
typedef struct {
    char estado[50];
    int codigo;
    char nome[100];
    int populacao;
    float pib;
    float area;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Cidade;

// Função para calcular a densidade populacional
float calcular_densidade_populacional(int populacao, float area) {
    return populacao / area;
}

// Função para calcular o PIB per capita
float calcular_pib_per_capita(float pib, int populacao) {
    return pib / populacao;
}

// Função para registrar as informações de uma cidade
void registrar_cidade(Cidade* cidade) {
    printf("\nDigite o estado da cidade: ");
    scanf("%s", cidade->estado);

    printf("Digite o código da cidade: ");
    scanf("%d", &cidade->codigo);

    printf("Digite o nome da cidade: ");
    scanf("%s", cidade->nome);

    printf("Digite a população da cidade: ");
    scanf("%d", &cidade->populacao);

    printf("Digite o PIB da cidade (em milhões de R$): ");
    scanf("%f", &cidade->pib);

    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &cidade->area);

    printf("Digite o número de pontos turísticos da cidade: ");
    scanf("%d", &cidade->pontos_turisticos);

    // Calcular propriedades derivadas
    cidade->densidade_populacional = calcular_densidade_populacional(cidade->populacao, cidade->area);
    cidade->pib_per_capita = calcular_pib_per_capita(cidade->pib, cidade->populacao);
}

// Função para exibir os dados da cidade
void exibir_dados_cidade(Cidade cidade) {
    printf("\n\nInformações da Cidade: %s - Código: %d\n", cidade.nome, cidade.codigo);
    printf("Estado: %s\n", cidade.estado);
    printf("População: %d\n", cidade.populacao);
    printf("PIB: R$ %.2f milhões\n", cidade.pib);
    printf("Área: %.2f km²\n", cidade.area);
    printf("Pontos Turísticos: %d\n", cidade.pontos_turisticos);
    printf("Densidade Populacional: %.2f habitantes por km²\n", cidade.densidade_populacional);
    printf("PIB per Capita: R$ %.2f\n", cidade.pib_per_capita);
}

int main() {
    Cidade cidades[MAX_CIDADES];
    int n, i;

    printf("Digite o número de cidades a registrar: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nRegistrando cidade %d\n", i + 1);
        registrar_cidade(&cidades[i]);
        exibir_dados_cidade(cidades[i]);
    }

    return 0;
}
