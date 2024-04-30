#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* lista_criar() {
    No* cabeca = (No*)malloc(sizeof(No));
    cabeca->prox = NULL;
    return cabeca;
}

void lista_destruir(No* L) {
    No* atual = L;
    while (atual != NULL) {
        No* proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
}

void lista_imprimir(No* L) {
    No* atual = L->prox;
    while (atual != NULL) {
        printf("%c -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

void lista_inserir_final(No* L, char valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->prox = NULL;

    No* atual = L;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    atual->prox = novo_no;
}

// Implemente as outras funções aqui
int lista_verificar_existencia(No* L, char valor_busca) {
    No* atual = L->prox;
    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            return 1;
        }
        atual = atual->prox;
    }
    return 0;
}

int lista_verificar_ocorrencias(No* L, char valor_busca) {
    int contagem = 0;
    No* atual = L->prox;
    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            contagem++;
        }
        atual = atual->prox;
    }
    return contagem;
}

void lista_imprimir_inversa(No* L) {
    if (L->prox == NULL) {
        return;
    }
    lista_imprimir_inversa(L->prox);
    printf("%c -> ", L->valor);
}

void lista_inserir_no_i(No* L, int i, char valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    
    No* atual = L;
    for (int j = 0; j < i && atual->prox != NULL; j++) {
        atual = atual->prox;
    }

    novo_no->prox = atual->prox;
    atual->prox = novo_no;
}

void lista_remover_no_i(No* L, int i) {
    No* atual = L;
    for (int j = 0; j < i && atual->prox != NULL; j++) {
        atual = atual->prox;
    }

    if (atual->prox == NULL) {
        return;
    }

    No* temp = atual->prox;
    atual->prox = temp->prox;
    free(temp);
}

void lista_remover_no(No* L, char valor_busca) {
    No* atual = L;
    while (atual->prox != NULL) {
        if (atual->prox->valor == valor_busca) {
            No* temp = atual->prox;
            atual->prox = temp->prox;
            free(temp);
        } else {
            atual = atual->prox;
        }
    }
}
