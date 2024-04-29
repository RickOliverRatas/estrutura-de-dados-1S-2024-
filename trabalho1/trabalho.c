#include <stdio.h>
#include <stdlib.h>

struct Ponto {
    int x;
    float y;
};

void regressao(struct Ponto* pontos, int n) {
    float soma_x = 0, soma_y = 0, soma_xy = 0, soma_x2 = 0;
    float inclinacao, intercepcao;

    for (int i = 0; i < n; i++) {
        soma_x += pontos[i].x;
        soma_y += pontos[i].y;
        soma_xy += pontos[i].x * pontos[i].y;
        soma_x2 += pontos[i].x * pontos[i].x;
    }

    inclinacao = (n * soma_xy - soma_x * soma_y) / (n * soma_x2 - soma_x * soma_x);

    intercepcao = (soma_y - inclinacao * soma_x) / n;

    printf("Equação da regressão linear: y = %.2fx + %.2f\n", inclinacao, intercepcao);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Uso: %s <dados.csv>\n", argv[0]);
        return 1;
    }

    FILE* arquivo = fopen(argv[1], "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int n = 0;
    while (!feof(arquivo)) {
        char linha[100];
        if (fgets(linha, sizeof(linha), arquivo)) {
            n++;
        }
    }

    struct Ponto* pontos = (struct Ponto*)malloc(n * sizeof(struct Ponto));

    fseek(arquivo, 0, SEEK_SET);

    for (int i = 0; i < n; i++) {
        fscanf(arquivo, "%d,%f", &pontos[i].x, &pontos[i].y);
    }

    regressao(pontos, n);

    free(pontos);

    fclose(arquivo);

    return 0;
}
