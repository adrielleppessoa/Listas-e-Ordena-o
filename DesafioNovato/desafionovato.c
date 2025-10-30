#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Biblioteca necessária para funções de string (strcpy, strmp)

// Define uma constante para o comprimento máximo que cada texto pode ter.
#define MAX_NOME 30 // Tamanho máximo que cada nome deve ter
#define MAX_TIPO 20 // Tamanho máximo que cada tipo deve ter

// Define uma constante para número máximo de itens na lista
#define TAM_MAX 10 // Define o número máximo de itens na lista

// Estrutura que representa a lista estática
typedef struct {
    char nome[TAM_MAX][MAX_NOME]; // Matriz: 10 linjas (itens), 50 colunas (caracteres por item)
    int quantidade; // Este é o nosso contador de controle. Ele informa quantos itens estão realmente armazenados na lista
} ListaMochila;

// Função da Lista

void inicializarListaMochila(ListaMochila *lista);

void inserirListaMochila(ListaMochila *lista, const char* texto);
void removerListaMochila(const ListaMochila *lista);

// Implementação das funções

void inicializarListaMochila(listaMochila *lista) {
    lista->quantidade = 0;
}

void inserirListaMochila(ListaMochila *lista, const char* texto) {
    // Primeiro, ela verifica se lista->quantidade já atingiu TAM_MAX.
    // Se sim, a lista está cheia e a função retorna.
    if (lista->quantidade == TAM_MAX) {
        printf("Mochila cheia! Não é possível inserir mais item.\n");
        return;
    }
    // A inserção ocorre na primeira "linha" livre da matriz.
    // Comparação
    strcpy(lista->dados[lista->quantidade], texto);
    // Após a cópia, lista->quantidade é incrementado, pois agora temos mais um item na mochila.
    lista->quantidade++;
    printf("Texto \"%s\" inserido com sucesso. \n", texto);
}

void removerListaMochila(ListaMochila *lista, const char* texto) {
    int i, pos = -1;
    // Para comparar strings, usamos strcmp(). Retorna 0 se forem iguais.
    // A função percorre os itens em uso na lista (de 0 até quantidade).
    // Para comparar strings, usamos strcmp(string1, string2).
    // Essa função retorna 0 se as strings forem idênticas. Se encontrar, guarda a posição (pos) e para o loop.

    for (i = 0; i < lista->quantidade; i++) {
        if (strcmp(lista->dados[i], texto) == 0) {
            pos = i;
            break;
        }
    }

    // Tratamento de Erro: Se o loop terminar e pos continuar -1, oitem não foi encontrado.
    if (pos == -1) {
        printf(Erro: Texto \"%s\" não encontrado na lista. \n", texto);
        return;
    }

    // Fechar a Lacuna: Se removemos um item do meio da lista, criamos um "buraco".
    // Para preenchê-lo, movemos todos os itens subsequentes uma posição para a esquerda.
    // O loop for começa na posiçlão do item removido e copia cada item i+1 para posição i.
    // Deslocar os elementos posteriores para a esquerda usando strcpy.
    for (i = pos; i < lista->quantidade -1; i++) {
        strcpy(lista->dados[i], lista->dados[i + 1]);
    }

    // Atualização do Contador: Finalmente, quantidade é decrementado para refletir que a lista tem um item a menos.
    lista->quantidade--;
    printf("Texto \"%s\" removido com sucesso.\n", texto);
}

void listarListaMochila(const ListaMochila *lista) {
    if (lista->quantidade == 0) {
        printf("A mochila está vazia.\n");
        return;
    }
    printf("Itens da Mochila: [ ");
    for (int i = 0; i < lista->quantidade; i++) {
        printf("\"%s\" ", lista->dados[i]); // Usar %s para imprimir strings
    }
    printd("]\n);
}

// Incluindo a função "main"

int main


