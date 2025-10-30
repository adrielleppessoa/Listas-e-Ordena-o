#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 10
#define MAX_NOME 30
#define MAX_TIPO 20

// =============================
// STRUCT PRINCIPAL DO JOGO
// =============================

// Estrutura que representa um item do inventário
typedef struct {
    char nome[MAX_NOME];   // Nome do item (ex: "Pistola", "Bandagem")
    char tipo[MAX_TIPO];   // Tipo do item (ex: "Arma", "Cura", "Munição")
    int quantidade;        // Quantidade do item
} Item;

// Estrutura que representa a mochila (lista de itens)
typedef struct {
    Item itens[MAX_ITENS];
    int total; // quantidade atual de itens cadastrados
} Mochila;

// =============================
// FUNÇÕES DO INVENTÁRIO
// =============================

void inicializarMochila(Mochila *m) {
    m->total = 0;
}

// Função para inserir um novo item na mochila
void inserirItem(Mochila *m, const char *nome, const char *tipo, int quantidade) {
    if (m->total >= MAX_ITENS) {
        printf(" Mochila cheia! Nao e possivel adicionar mais itens.\n");
        return;
    }

    strcpy(m->itens[m->total].nome, nome);
    strcpy(m->itens[m->total].tipo, tipo);
    m->itens[m->total].quantidade = quantidade;

    m->total++;
    printf(" Item \"%s\" adicionado com sucesso!\n", nome);
}

// Função para remover item pelo nome
void removerItem(Mochila *m, const char *nome) {
    int i, pos = -1;
    for (i = 0; i < m->total; i++) {
        if (strcmp(m->itens[i].nome, nome) == 0) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf(" Item \"%s\" nao encontrado.\n", nome);
        return;
    }

    // Desloca os itens para preencher o espaço removido
    for (i = pos; i < m->total - 1; i++) {
        m->itens[i] = m->itens[i + 1];
    }

    m->total--;
    printf(" Item \"%s\" removido com sucesso!\n", nome);
}

// Função para listar todos os itens
void listarItens(const Mochila *m) {
    if (m->total == 0) {
        printf(" A mochila esta vazia.\n");
        return;
    }

    printf("\n--------- ITENS NA MOCHILA ---------\n");
    printf("\n       ITEM    |     TIPO     | QUANTIDADE\n");
    for (int i = 0; i < m->total; i++) {
        printf("%d.    %s    |    %s    | %d \n",
               i + 1,
               m->itens[i].nome,
               m->itens[i].tipo,
               m->itens[i].quantidade);
    }
    printf("------------------------\n");
}

// Função para buscar um item pelo nome (busca sequencial)
void buscarItem(const Mochila *m, const char *nome) {
    for (int i = 0; i < m->total; i++) {
        if (strcmp(m->itens[i].nome, nome) == 0) {
            printf(" Item encontrado!\n");
            printf("Nome: %s\nTipo: %s\nQuantidade: %d\n",
                   m->itens[i].nome,
                   m->itens[i].tipo,
                   m->itens[i].quantidade);
            return;
        }
    }
    printf(" Item \"%s\" nao encontrado.\n", nome);
}

// =============================
// FUNÇÃO PRINCIPAL (MENU)
// =============================

int main() {
    Mochila mochila;
    inicializarMochila(&mochila);

    int opcao;
    char nome[MAX_NOME];
    char tipo[MAX_TIPO];
    int quantidade;

    do {
        printf("\n=============================================\n");
        printf("      MOCHILA DE SOBREVIVENCIA - CODIGO DA ILHA\n");
        printf("=============================================\n");
        printf("1. Adicionar item (loot)\n");
        printf("2. Remover item\n");
        printf("3. Listar itens na mochila\n");
        printf("4. Buscar item\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // limpa o \n do buffer

        switch (opcao) {
            case 1:
                printf("Digite o nome do item: ");
                fgets(nome, MAX_NOME, stdin);
                nome[strcspn(nome, "\n")] = '\0';

                printf("Digite o tipo do item (arma, cura, ferramenta...): ");
                fgets(tipo, MAX_TIPO, stdin);
                tipo[strcspn(tipo, "\n")] = '\0';

                printf("Digite a quantidade: ");
                scanf("%d", &quantidade);
                getchar();

                inserirItem(&mochila, nome, tipo, quantidade);
                listarItens(&mochila);
                break;

            case 2:
                printf("Digite o nome do item a remover: ");
                fgets(nome, MAX_NOME, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                removerItem(&mochila, nome);
                listarItens(&mochila);
                break;

            case 3:
                listarItens(&mochila);
                break;

            case 4:
                printf("Digite o nome do item para buscar: ");
                fgets(nome, MAX_NOME, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                buscarItem(&mochila, nome);
                break;

            case 0:
                printf(" Saindo da mochila...\n");
                break;

            default:
                printf(" Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}



