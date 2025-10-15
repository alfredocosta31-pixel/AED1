#include <stdio.h>

#define N 9
#define VERDADEIRO 1
#define FALSO 0

int verifica_conjunto(int arr[], int tamanho) {
    
    int presente[N + 1];
    int i;

    for (i = 0; i <= N; i++) {
        presente[i] = 0;
    }

    for (i = 0; i < tamanho; i++) {
        int num = arr[i];
        if (num < 1 || num > N) {
            return FALSO;
        }

        if (presente[num] == 1) {
            return FALSO;
        }

        presente[num] = 1;
    }

    for (i = 1; i <= N; i++) {
        if (presente[i] == 0) {
            return FALSO; 
        }
    }

    return VERDADEIRO;
}

int verifica_sudoku(int matriz[N][N]) {
    int i, j, k;
    int temp_arr[N]; 

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            temp_arr[j] = matriz[i][j];
        }
        if (verifica_conjunto(temp_arr, N) == FALSO) {
            return FALSO;
        }
    }

    for (j = 0; j < N; j++) {
        for (i = 0; i < N; i++) {
            temp_arr[i] = matriz[i][j];
        }
        if (verifica_conjunto(temp_arr, N) == FALSO) {
            return FALSO;
        }
    }

    for (int reg_linha = 0; reg_linha < 3; reg_linha++) {
        for (int reg_coluna = 0; reg_coluna < 3; reg_coluna++) {
            k = 0; 
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    int linha = 3 * reg_linha + i;
                    int coluna = 3 * reg_coluna + j;
                    temp_arr[k++] = matriz[linha][coluna];
                }
            }

            if (verifica_conjunto(temp_arr, N) == FALSO) {
                return FALSO;
            }
        }
    }

    return VERDADEIRO;
}

int main() {
    int n_instancias;
    int k;

    if (scanf("%d", &n_instancias) != 1 || n_instancias <= 0) {
        return 0; 
    }

    for (k = 1; k <= n_instancias; k++) {
        int matriz[N][N];
        int leitura_ok = VERDADEIRO;
        int i, j;

        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (scanf("%d", &matriz[i][j]) != 1) {
                    leitura_ok = FALSO;
                    break;
                }
            }
            if (leitura_ok == FALSO) break;
        }

        if (leitura_ok == FALSO) break; 

        int resultado = verifica_sudoku(matriz);

        printf("Instancia %d\n", k);
        if (resultado == VERDADEIRO) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }

        printf("\n"); 
    }

    return 0;
}
