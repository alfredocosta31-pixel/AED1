#include <stdio.h>

int main(){

  int n, posicao;

  printf("tamanho do vetor: ");
  scanf("%i", &n);

  int v[n];

  for(int i=0; i<n; i++)
    scanf("%i", &v[i]);

  int menor = v[0];

  for(int i=1; i<n;i++){
    if (v[i] <= menor){
      menor = v[i];
      posicao = i;
    }
  }

  printf("O menor número é: %i, e está na posição: %i \n", menor, posicao);

  return 0;
}
