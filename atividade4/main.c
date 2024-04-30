#include <stdio.h>
#include "lista.h"

int main() {
    // Criação da lista
    No* lista = lista_criar();

    // Inserção de elementos na lista
    lista_inserir_final(lista, 'A');
    lista_inserir_final(lista, 'B');
    lista_inserir_final(lista, 'C');
    lista_inserir_final(lista, 'A');
    lista_inserir_final(lista, 'D');

    // Impressão da lista
    printf("Lista original: ");
    lista_imprimir(lista);

    // Verificação de existência de um valor na lista
    char valor_busca = 'B';
    if (lista_verificar_existencia(lista, valor_busca)) {
        printf("O valor '%c' existe na lista.\n", valor_busca);
    } else {
        printf("O valor '%c' nao existe na lista.\n", valor_busca);
    }

    // Verificação de ocorrências de um valor na lista
    int ocorrencias = lista_verificar_ocorrencias(lista, valor_busca);
    printf("O valor '%c' ocorre %d vezes na lista.\n", valor_busca, ocorrencias);

    // Impressão inversa da lista
    printf("Lista inversa: ");
    lista_imprimir_inversa(lista);
    printf("NULL\n");

    // Inserção de um nó na posição i
    int posicao = 2; // Por exemplo, inserir na posição 2
    char valor_inserir = 'E';
    lista_inserir_no_i(lista, posicao, valor_inserir);
    printf("Lista apos inserir '%c' na posicao %d: ", valor_inserir, posicao);
    lista_imprimir(lista);

    // Remoção de um nó na posição i
    posicao = 1; // Por exemplo, remover na posição 1
    lista_remover_no_i(lista, posicao);
    printf("Lista apos remover na posicao %d: ", posicao);
    lista_imprimir(lista);

    // Remoção de nós com um determinado valor
    char valor_remover = 'A';
    lista_remover_no(lista, valor_remover);
    printf("Lista apos remover todos os '%c': ", valor_remover);
    lista_imprimir(lista);

    // Liberação de memória da lista
    lista_destruir(lista);

    return 0;
}
