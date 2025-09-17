#include <stdio.h>

int main(){

  int n, posicao;
  int *p;
  
  printf("tamanho do vetor: ");
  scanf("%i", &n);

  int v[n];
  p = v;

  for(int i=0; i<n; i++){
    scanf("%i", p);
    p++;
  }

  p = v;
  int menor = *p;
  
  for(int i=0; i<n;i++){
    if (*p <= menor){
      menor = *p;
      posicao = i+1;
    }
    p++;
  }
    
  printf("O menor número é: %i, e está na posição: %i \n", menor, posicao);
  
  return 0;
}
