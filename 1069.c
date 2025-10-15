#include <stdio.h>
#include <string.h>

#define MAX_TAMANHO 1002

void resolver_caso_de_teste() {
    char linha[MAX_TAMANHO];
    
    if (fgets(linha, MAX_TAMANHO, stdin) == NULL) {
        return;
    }

    int diamantes_abertos = 0;
    int diamantes_extraidos = 0;
    int i;
    int tamanho = strlen(linha);

    for (i = 0; i < tamanho; i++) {
        char caractere = linha[i];

        if (caractere == '<') {
            diamantes_abertos++;
        } else if (caractere == '>') {
            if (diamantes_abertos > 0) {
                diamantes_abertos--;
                diamantes_extraidos++;
            }
        }
    }

    printf("%d\n", diamantes_extraidos);
}

int main() {
    int N;
    
    if (scanf("%d", &N) != 1) {
        return 0;
    }
    
    getchar();

    while (N > 0) {
        resolver_caso_de_teste();
        N--;
    }

    return 0;
}
