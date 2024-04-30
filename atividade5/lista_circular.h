#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

typedef struct No {
    char valor;
    struct No* proximo;
} No;

void inserir_no(No** H, char valor);
void imprimir_lista(No* H);
void remover_no(No** H, char valor);
void liberar_lista(No** H);

#endif
