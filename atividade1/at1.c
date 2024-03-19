#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main() {
  setlocale(LC_ALL, "");
  int n, soma = 0, min, max, num;

  printf("Digite a quantidade de números: ");
  scanf("%d", &n);

  if (n <= 0) {
    printf("Erro: Número inválido!\n");
    return 1;
  }

  int *numeros = (int *)malloc(n * sizeof(int));

  printf("Digite o primeiro número: ");
  scanf("%d", &num);
  numeros[0] = min = max = soma = num;

  for (int i = 1; i < n; i++) {
    printf("Digite o %dº número: ", i + 1);
    scanf("%d", &num);
    numeros[i] = num;
    soma += num;

    if (num < min) {
      min = num;
    } 
    if (num > max) {
      max = num;
    }
  }

  float media = (float)soma / n;

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (numeros[j] > numeros[j + 1]) {
        int temp = numeros[j];
        numeros[j] = numeros[j + 1];
        numeros[j + 1] = temp;
      }
    }
  }

  printf("\nQuantidade de números recebidos: %d\n", n);
  printf("Valor médio dos números: %.2f\n", media);
  printf("Menor número: %d\n", min);
  printf("Maior número: %d\n", max);
  printf("Números em ordem crescente: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", numeros[i]);
  }
  printf("\n");

  free(numeros);

  return 0;
}
