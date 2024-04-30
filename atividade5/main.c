#include <stdio.h>
#include "lista_circular.h"

int main() {
    No* lista = NULL;

    inserir_no(&lista, 'A');
    inserir_no(&lista, 'B');
    inserir_no(&lista, 'C');
    inserir_no(&lista, 'D');

    printf("Lista circular: ");
    imprimir_lista(lista);

    remover_no(&lista, 'B');
    printf("Lista após remover 'B': ");
    imprimir_lista(lista);

    liberar_lista(&lista);

    return 0;
}
