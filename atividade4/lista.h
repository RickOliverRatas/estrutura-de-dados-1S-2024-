#ifndef LISTA_H
#define LISTA_H

typedef struct No {
    char valor;
    struct No *prox;
} No;

No* lista_criar();
void lista_destruir(No* L);
void lista_imprimir(No* L);
void lista_inserir_final(No* L, char valor);
int lista_verificar_existencia(No* L, char valor_busca);
int lista_verificar_ocorrencias(No* L, char valor_busca);
void lista_imprimir_inversa(No* L);
void lista_inserir_no_i(No* L, int i, char valor);
void lista_remover_no_i(No* L, int i);
void lista_remover_no(No* L, char valor_busca);

#endif
