
 

#include <stdio.h>

// Estrutura para representar uma carta do Super Trunfo
typedef struct {
    char estado[30];
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float PIB;
    int pontosTuristicos;
    float densidadePopulacional;
    float PIBperCapita;
} Carta;

// Função para calcular densidade populacional e PIB per capita
void calcularAtributos(Carta *carta) {
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->PIBperCapita = carta->PIB / carta->populacao;
}

// Função para comparar as cartas com base no atributo escolhido
void compararCartas(Carta c1, Carta c2, int atributo) {
    printf("Comparação de cartas (Atributo: ");
    
    float valor1, valor2;
    switch (atributo) {
        case 1:
            printf("População):\n");
            valor1 = c1.populacao;
            valor2 = c2.populacao;
            break;
        case 2:
            printf("Área):\n");
            valor1 = c1.area;
            valor2 = c2.area;
            break;
        case 3:
            printf("PIB):\n");
            valor1 = c1.PIB;
            valor2 = c2.PIB;
            break;
        case 4:
            printf("Densidade Populacional):\n");
            valor1 = c1.densidadePopulacional;
            valor2 = c2.densidadePopulacional;
            break;
        case 5:
            printf("PIB per Capita):\n");
            valor1 = c1.PIBperCapita;
            valor2 = c2.PIBperCapita;
            break;
        default:
            printf("Atributo inválido!\n");
            return;
    }

    printf("Carta 1 - %s (%s): %.2f\n", c1.nome, c1.estado, valor1);
    printf("Carta 2 - %s (%s): %.2f\n", c2.nome, c2.estado, valor2);

    // Determinar vencedor
    if ((atributo == 4 && valor1 < valor2) || (atributo != 4 && valor1 > valor2)) {
        printf("Resultado: Carta 1 (%s) venceu!\n", c1.nome);
    } else if (valor1 == valor2) {
        printf("Resultado: Empate!\n");
    } else {
        printf("Resultado: Carta 2 (%s) venceu!\n", c2.nome);
    }
}

int main() {
    // Criando duas cartas com valores fictícios
    Carta carta1 = {"SP", "001", "São Paulo", 12300000, 1521.11, 2370000000000, 100};
    Carta carta2 = {"RJ", "002", "Rio de Janeiro", 6748000, 1182.30, 815000000000, 80};

    // Calculando densidade populacional e PIB per capita
    calcularAtributos(&carta1);
    calcularAtributos(&carta2);

    // Escolha do atributo (1: População, 2: Área, 3: PIB, 4: Densidade Populacional, 5: PIB per capita)
    int atributoEscolhido = 1; // Altere este valor para testar diferentes atributos

    // Comparando as cartas
    compararCartas(carta1, carta2, atributoEscolhido);

    return 0;
}

