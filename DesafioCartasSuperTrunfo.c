#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo uma estrutura para armazenar os dados de um país
typedef struct {
    char nome[50];
    int populacao;
    int area;
    int pib;
} Pais;

// Função para inicializar os países
void inicializarCartas(Pais cartas[]) {
    // Países fictícios com seus respectivos dados
    strcpy(cartas[0].nome, "Brasil");
    cartas[0].populacao = 213993437;
    cartas[0].area = 8515767;  // em km²
    cartas[0].pib = 2085000;   // em bilhões de USD

    strcpy(cartas[1].nome, "Estados Unidos");
    cartas[1].populacao = 332915073;
    cartas[1].area = 9833517;  // em km²
    cartas[1].pib = 21433225;  // em bilhões de USD

    strcpy(cartas[2].nome, "China");
    cartas[2].populacao = 1444216107;
    cartas[2].area = 9596961;  // em km²
    cartas[2].pib = 14342903;  // em bilhões de USD

    strcpy(cartas[3].nome, "Índia");
    cartas[3].populacao = 1380004385;
    cartas[3].area = 3287263;  // em km²
    cartas[3].pib = 2875000;   // em bilhões de USD

    strcpy(cartas[4].nome, "Alemanha");
    cartas[4].populacao = 83783942;
    cartas[4].area = 357022;   // em km²
    cartas[4].pib = 3845630;   // em bilhões de USD
}

// Função para exibir a carta de um país
void exibirCarta(Pais pais) {
    printf("País: %s\n", pais.nome);
    printf("População: %d\n", pais.populacao);
    printf("Área: %d km²\n", pais.area);
    printf("PIB: $%d bilhões\n", pais.pib);
}

// Função para comparar os atributos entre dois países
int compararAtributos(Pais pais1, Pais pais2, int atributo) {
    switch (atributo) {
        case 1:
            return pais1.populacao - pais2.populacao;  // Comparar população
        case 2:
            return pais1.area - pais2.area;  // Comparar área
        case 3:
            return pais1.pib - pais2.pib;  // Comparar PIB
        default:
            return 0;
    }
}

// Função para escolher qual atributo o jogador quer comparar
int escolherAtributo() {
    int opcao;
    printf("\nEscolha o atributo para a comparação:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    return opcao;
}

// Função principal do jogo
void jogarSuperTrunfo() {
    Pais cartas[5];
    inicializarCartas(cartas);

    printf("Bem-vindo ao Super Trunfo - Países!\n");

    int pontosJogador = 0, pontosComputador = 0;
    int rodada;

    for (rodada = 0; rodada < 5; rodada++) {
        printf("\nRodada %d\n", rodada + 1);

        // Jogador escolhe um país e o computador escolhe outro aleatoriamente
        int paisJogador = rand() % 5;
        int paisComputador = rand() % 5;
        while (paisComputador == paisJogador) {
            paisComputador = rand() % 5;  // Garantir que não será o mesmo país
        }

        // Exibir as cartas
        printf("\nSua carta:\n");
        exibirCarta(cartas[paisJogador]);
        printf("\nCarta do Computador:\n");
        exibirCarta(cartas[paisComputador]);

        // O jogador escolhe o atributo para comparar
        int atributo = escolherAtributo();

        // Comparar os atributos escolhidos
        int resultado = compararAtributos(cartas[paisJogador], cartas[paisComputador], atributo);

        if (resultado > 0) {
            printf("\nVocê venceu a rodada!\n");
            pontosJogador++;
        } else if (resultado < 0) {
            printf("\nO computador venceu a rodada!\n");
            pontosComputador++;
        } else {
            printf("\nEmpate na rodada!\n");
        }

        printf("\nPontos - Você: %d | Computador: %d\n", pontosJogador, pontosComputador);
    }

    // Exibir o vencedor
    if (pontosJogador > pontosComputador) {
        printf("\nParabéns, você venceu o jogo!\n");
    } else if (pontosJogador < pontosComputador) {
        printf("\nO computador venceu o jogo!\n");
    } else {
        printf("\nO jogo terminou em empate!\n");
    }
}

int main() {
    jogarSuperTrunfo();
    return 0;
}