// Super Trunfo - Cidades Brasileiras
// Implementação em C

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
} Carta;


int main() {

    printf("Super Trunfo - Cidades Brasileiras\n\n");
   
    Carta codo = {
        "Maranhão",    // estado
        "COD01",       // código da carta
        "Codó",        // cidade
        123,           // população em milhares
        4364.6,        // área em km²
        1.0,           // PIB em bilhões de reais
        5              // pontos turísticos
    };

    Carta teresina = {
        "Piauí",       // estado
        "TER01",       // código da carta
        "Teresina",    // cidade
        868,           // população em milhares
        1391.0,        // área em km²
        8.5,           // PIB em bilhões de reais
        7              // pontos turísticos
    };


    printf("Cidade: %s\n", codo.cidade);
    printf("Estado: %s\n", codo.estado);
    printf("Código: %s\n", codo.codigo);
    printf("População: %d mil\n", codo.populacao);
    printf("Área: %.1f km²\n", codo.area);
    printf("PIB: %.1f bilhões de reais\n", codo.pib);
    printf("Pontos turísticos: %d\n\n", codo.pontos_turisticos);
  

    printf("Cidade: %s\n", teresina.cidade);
    printf("Estado: %s\n", teresina.estado);
    printf("Código: %s\n", teresina.codigo);
    printf("População: %d mil\n", teresina.populacao);
    printf("Área: %.1f km²\n", teresina.area);
    printf("PIB: %.1f bilhões de reais\n", teresina.pib);
    printf("Pontos turísticos: %d\n", teresina.pontos_turisticos);
  
    return 0;
}

