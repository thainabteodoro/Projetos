#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[30];           // Nome do estado
    char codigo[10];           // Código da carta
    char cidade[30];           // Nome da cidade
    int populacao;             // População em milhares
    float area;                // Área em km²
    float pib;                 // PIB em bilhões de reais
    int pontos_turisticos;     // Número de pontos turísticos
    int pib_per_capita;       // PIB per capita
    float densidade_populacional; // Densidade populacional 
} Carta;


int main() {

    printf("Super Trunfo - Cidades Brasileiras\n\n");
   
    Carta codo = {
        "Maranhão",    // estado
        "COD01",       // código da carta
        "Codó",        // cidade
        123,            // população em milhares
        4364.6,         // área em km²
        1.0,            // PIB em bilhões de reais
        5,              // pontos turísticos
        1336478,        // PIB per capita
        2620            // Densidade populacional
    };

    Carta teresina = {
        "Piauí",        // estado
        "TER01",        // código da carta
        "Teresina",     // cidade
        868,             // população em milhares
        1391.0,          // área em km²
        8.5,             // PIB em bilhões de reais
        7,               // pontos turísticos
        2743028,         // PIB per capita
        62266            // Densidade populacional
    };



    printf("Cidade: %s\n", codo.cidade);
    printf("Estado: %s\n", codo.estado);
    printf("Código: %s\n", codo.codigo);
    printf("População: %d mil\n", codo.populacao);
    printf("Área: %.1f km²\n", codo.area);
    printf("PIB: %.1f bilhões de reais\n", codo.pib);
    printf("Pontos turísticos: %d\n\n", codo.pontos_turisticos);
    printf("PIB per capita: %.2f\n", codo.pib/codo.populacao*1000);
    printf("Densidade populacional: %.2f\n\n", (float)codo.populacao/codo.area*1000);


    printf("Cidade: %s\n", teresina.cidade);
    printf("Estado: %s\n", teresina.estado);
    printf("Código: %s\n", teresina.codigo);
    printf("População: %d mil\n", teresina.populacao);
    printf("Área: %.1f km²\n", teresina.area);
    printf("PIB: %.1f bilhões de reais\n", teresina.pib);
    printf("Pontos turísticos: %d\n", teresina.pontos_turisticos);
    printf("PIB per capita: %.2f\n", teresina.pib/teresina.populacao*1000);
    printf("Densidade populacional: %.2f\n", (float)teresina.populacao/teresina.area*1000);
   
    return 0;
}

    //Nesta atividade se teeve como objetivo ''evoluir'' o código do super trunfo,
    //adicionando o cálculo do PIB per capita e da densidade populacional.
    //O PIB per capita é calculado dividindo o PIB pela população (convertida para
    //número total de habitantes). A densidade populacional é calculada dividindo a
    //população (convertida para número total de habitantes) pela área da cidade.
    //Esses cálculos fornecem informações adicionais sobre as cidades representadas
    //nas cartas, permitindo comparações mais detalhadas entre elas.
    //O código foi testado e está funcionando corretamente, exibindo as informações
    //das cidades, incluindo o PIB per capita e a densidade populacional.