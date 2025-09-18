#include <stdio.h>
 
int main() {

  int n, posicao;
  int *p;
  
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
      posicao = i;
    }
    p++;
  }
    
  printf("Menor valor: %i\n", menor);
  printf("Posicao: %i", posicao);
  
  return 0;
}
