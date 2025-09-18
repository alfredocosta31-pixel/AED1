#include <stdio.h>
 
int main() {

  int n, posicao;
  
  scanf("%i", &n);

  int v[n];

  for(int i=0; i<n; i++)
    scanf("%i", &v[i]);

  int menor = v[0];
  
  for(int i=0; i<n;i++)
    if (v[i] <= menor){
      menor = v[i];
      posicao = i;
    }
    
  printf("Menor valor: %i\n", menor);
  printf("Posicao: %i", posicao);
  
  return 0;
}
