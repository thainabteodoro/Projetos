#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CONSTANTES GLOBAIS
#define MAX_LIVROS 50
#define TAM_STRING 100

// DEFINIÇÃO DA ESTRUTURA (STRUCT) COM NOME LIVRO

struct Livro {
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edição;
    int ano;
};

// -- função para limpar o buffer de entrada --

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// -------- FUNÇÃO PARA SALVAR LIVROS --------

void salvarLivros(struct Livro biblioteca[], int totalLivros) {

    FILE *arquivo = fopen("livros.dat", "wb");

    if (arquivo == NULL) {
        printf("Erro ao salvar arquivo!\n");
        return;
    }

    fwrite(&totalLivros, sizeof(int), 1, arquivo);
    fwrite(biblioteca, sizeof(struct Livro), totalLivros, arquivo);

    fclose(arquivo);
}

// -------- FUNÇÃO PARA CARREGAR LIVROS --------

void carregarLivros(struct Livro biblioteca[], int *totalLivros) {

    FILE *arquivo = fopen("livros.dat", "rb");

    if (arquivo == NULL) {
        *totalLivros = 0;
        return;
    }

    fread(totalLivros, sizeof(int), 1, arquivo);
    fread(biblioteca, sizeof(struct Livro), *totalLivros, arquivo);

    fclose(arquivo);
}

// -------- FUNÇÃO PRINCIPAL --------

int main() {

    struct Livro biblioteca[MAX_LIVROS];
    int totalLivros = 0;
    int opcao;

    // CARREGA OS LIVROS SALVOS
    carregarLivros(biblioteca, &totalLivros);

    // LAÇO PRINCIPAL DO MENU
    do {

        printf("===============================\n");
        printf("\n--- SISTEMA DE BIBLIOTECA ---\n");
        printf("BIBLIOTECA - PARTE 1\n");
        printf("===============================\n");
        printf("1. Cadastrar novo Livro\n");
        printf("2. Listar Livros Cadastrados\n");
        printf("0. Sair\n");
        printf("--------------------------------\n");
        printf("Escolha uma opção: ");

        scanf("%d", &opcao);
        limparBuffer();

        // --- PROCESSAMENTO DA OPÇÃO ---

        switch (opcao) {

            case 1: // CADASTRAR LIVRO

                if (totalLivros < MAX_LIVROS) {

                    struct Livro novoLivro;

                    printf("Digite o nome do livro: ");
                    fgets(novoLivro.nome, TAM_STRING, stdin);
                    novoLivro.nome[strcspn(novoLivro.nome, "\n")] = '\0';

                    printf("Digite o autor do livro: ");
                    fgets(novoLivro.autor, TAM_STRING, stdin);
                    novoLivro.autor[strcspn(novoLivro.autor, "\n")] = '\0';

                    printf("Digite a editora do livro: ");
                    fgets(novoLivro.editora, TAM_STRING, stdin);
                    novoLivro.editora[strcspn(novoLivro.editora, "\n")] = '\0';

                    printf("Digite a edição do livro: ");
                    scanf("%d", &novoLivro.edição);
                    limparBuffer();

                    biblioteca[totalLivros] = novoLivro;

                    totalLivros++;

                    // SALVA NO ARQUIVO
                    salvarLivros(biblioteca, totalLivros);

                    printf("Livro cadastrado com sucesso!\n");

                } else {

                    printf("Capacidade máxima de livros atingida!\n");
                }

                break;

            case 2: // LISTAR LIVROS

                if (totalLivros > 0) {

                    printf("\n--- Livros Cadastrados ---\n");

                    for (int i = 0; i < totalLivros; i++) {

                        printf("Livro %d:\n", i + 1);
                        printf("Nome: %s\n", biblioteca[i].nome);
                        printf("Autor: %s\n", biblioteca[i].autor);
                        printf("Editora: %s\n", biblioteca[i].editora);
                        printf("Edição: %d\n", biblioteca[i].edição);

                        printf("-------------------------\n");
                    }

                } else {

                    printf("Nenhum livro cadastrado!\n");
                }

                break;

            case 0:

                printf("Saindo do sistema...\n");
                break;

            default:

                printf("Opção inválida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}