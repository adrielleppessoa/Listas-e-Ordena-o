//Módulo1 - nível novato - hora de codar

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Biblioteca necessária para a função string (srtcpy, strcmp)

// Define uma constante para o comprimento máximo que cada texto pode ter
#define MAX_STR_LEN 50 //tamanho máximo de cada string/texto

//----------------------------------------------
// PARTE 1: LISTA ESTÁTICA (VETOR DE STRINGS)
// Uma lista estática é uma estrutura de dados de tamanho fixo,
// implementada usando um vetor (ou array).
// Toda a memória necessária é alocada de uma só vez, quando a variável é declarada.
// -----------------------

// Define uma constante para o número máximo d eitens que nossa lista pode conter.
#define TAM_MAX 10 // Define o número máximo de itens na lista estática

// Estrutura que representa a lista estática
typedef struct {
    char dados[TAM_MAX][MAX_STR_LEN]; // Matriz: 10 linhas (itens), 50 colunas (caracteres por item)
    int quantidade; // Este é nosso contador de controle. Ele informa quantos itens estão realmente armazenados na lista.
} ListaEstatica;

// Funções da Lista Estática

// Esta função prepara a lista para ser usada.
// Ela simplesmente define o contador quantidade como 0, indicado que a lista está vazia.
// Recebemos um ponteiro (*lista) para modificar a variável original passada para a função.
void inicializarListaEstatica(ListaEstatica *lista);

void inserirListaEstatica(ListaEstatica *lista, const char* texte);
void removerListEstatica(const ListaEstatica *lista);

//--------------
// PARTE 2: LISTA ENCADEADA (DE STRINGS)
// Uma lista encadeada é uma estrutura de dados de tamanho dinâmico.
// Ela é composta por "nós" separados na memória,
// onde cada nó contém um dado e um ponteiro que "aponta" para o próximo nó da sequência.
//-------------------

// Estrutura de nó (cada elemento da lista)
// - char* dado: Este é um ponteiro. Ele 