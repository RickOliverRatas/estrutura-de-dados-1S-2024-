#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

void inserir_no(No** H, char valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    
    if (*H == NULL) {
        novoNo->proximo = novoNo;
        *H = novoNo;
    } else {
        No* ultimo = *H;
        while (ultimo->proximo != *H) {
            ultimo = ultimo->proximo;
        }
        novoNo->proximo = *H;
        ultimo->proximo = novoNo; 
    }
}

void imprimir_lista(No* H) {
    if (H == NULL) {
        printf("Lista vazia\n");
        return;
    }
    No* atual = H;
    do {
        printf("%c ", atual->valor);
        atual = atual->proximo;
    } while (atual != H);
    printf("\n");
}

void remover_no(No** H, char valor) {
    if (*H == NULL) {
        printf("Lista vazia\n");
        return;
    }

    No* atual = *H;
    No* anterior = NULL;

    do {
        if (atual->valor == valor) {
            if (anterior == NULL) { 
                No* ultimo = *H;
                while (ultimo->proximo != *H) {
                    ultimo = ultimo->proximo;
                }
                *H = (*H)->proximo;
                ultimo->proximo = *H;
                free(atual);
                return;
            } else {
                anterior->proximo = atual->proximo;
                free(atual);
                return;
            }
        }
        anterior = atual;
        atual = atual->proximo;
    } while (atual != *H);

    printf("Elemento %c não encontrado na lista\n", valor);
}

void liberar_lista(No** H) {
    if (*H == NULL) {
        return;
    }

    No* atual = *H;
    No* proximo = NULL;

    do {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    } while (atual != *H);

    *H = NULL;
}
