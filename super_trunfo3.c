// Super Trunfo - versão limpa e funcional
#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[30];
    char codigo[10];
    char cidade[30];
    int populacao;             // em milhares
    float area;                // km²
    float pib;                 // bilhões
    int pontos_turisticos;
    int pib_per_capita;        // unidades inteiras
    float densidade_populacional;
    float super_poder;
} Carta;

// Função que compara atributos e imprime resultado
void comparar_atributos(const Carta *c1, const Carta *c2, int escolha, const char *nome_atributo) {
    float valor1 = 0.0f, valor2 = 0.0f;

    switch (escolha) {
        case 1: // População (int)
            valor1 = (float)c1->populacao;
            valor2 = (float)c2->populacao;
            break;
        case 2: // Área (float)
            valor1 = c1->area;
            valor2 = c2->area;
            break;
        case 3: // PIB (float)
            valor1 = c1->pib;
            valor2 = c2->pib;
            break;
        case 4: // Pontos Turísticos (int)
            valor1 = (float)c1->pontos_turisticos;
            valor2 = (float)c2->pontos_turisticos;
            break;
        case 5: // PIB per capita (int)
            valor1 = (float)c1->pib_per_capita;
            valor2 = (float)c2->pib_per_capita;
            break;
        case 6: // Densidade populacional (float)
            valor1 = c1->densidade_populacional;
            valor2 = c2->densidade_populacional;
            break;
        case 7: // Super poder (float)
            valor1 = c1->super_poder;
            valor2 = c2->super_poder;
            break;
        default:
            printf("Erro: escolha invalida.\n");
            return;
    }

    printf("\n--- Rodada Super Trunfo ---\n");
    printf("Atributo escolhido: %s\n", nome_atributo);
    printf("Carta %s: %.2f\n", c1->cidade, valor1);
    printf("Carta %s: %.2f\n", c2->cidade, valor2);
    printf("---------------------------\n");

    if (valor1 > valor2) {
        printf("*** VENCEDOR: %s (%s) ***\n", c1->cidade, c1->codigo);
    } else if (valor2 > valor1) {
        printf("*** VENCEDOR: %s (%s) ***\n", c2->cidade, c2->codigo);
    } else {
        printf("*** RESULTADO: Empate! ***\n");
    }
}

int main(void) {
    int escolha;
    char atributo_nome[40];

    // Definição das cartas
    Carta codo = {"Maranhão", "COD01", "Codó", 123, 4364.6f, 1.0f, 5, 1336478, 2620.0f, 0.0f};
    Carta teresina = {"Piauí", "TER01", "Teresina", 868, 1391.0f, 8.5f, 7, 2743028, 62266.0f, 0.0f};

    // Calcular um 'super_poder' simples (exemplo): combinação linear leve
    codo.super_poder = codo.pontos_turisticos + codo.pib + (float)codo.populacao / 1000.0f + codo.area / 1000.0f;
    teresina.super_poder = teresina.pontos_turisticos + teresina.pib + (float)teresina.populacao / 1000.0f + teresina.area / 1000.0f;

    printf("Super Trunfo - Cidades Brasileiras\n\n");

    printf("Qual atributo deseja comparar? Digite o numero:\n");
    printf("1. Populacao (em milhares)\n");
    printf("2. Area (km²)\n");
    printf("3. PIB (bilhões)\n");
    printf("4. Pontos Turisticos\n");
    printf("5. PIB Per Capita\n");
    printf("6. Densidade Populacional\n");
    printf("7. Super Poder\n");
    printf("\nSua escolha: ");
    if (scanf("%d", &escolha) != 1) {
        printf("Entrada invalida. Saindo.\n");
        return 1;
    }

    switch (escolha) {
        case 1: strcpy(atributo_nome, "Populacao (mil)"); break;
        case 2: strcpy(atributo_nome, "Area (km²)"); break;
        case 3: strcpy(atributo_nome, "PIB (bilhões)"); break;
        case 4: strcpy(atributo_nome, "Pontos Turisticos"); break;
        case 5: strcpy(atributo_nome, "PIB Per Capita"); break;
        case 6: strcpy(atributo_nome, "Densidade Populacional"); break;
        case 7: strcpy(atributo_nome, "Super Poder"); break;
        default: strcpy(atributo_nome, "INVALIDO"); break;
    }

    if (escolha >= 1 && escolha <= 7) {
        comparar_atributos(&codo, &teresina, escolha, atributo_nome);
    } else {
        printf("Opcao invalida. Reinicie e escolha entre 1 e 7.\n");
    }

    return 0;
}