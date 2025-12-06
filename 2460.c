#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_ID 100001
#define MAX_N 50000

bool saiu_da_fila[MAX_ID];
int fila_inicial[MAX_N];

void solve() {
    int N;
    if (scanf("%d", &N) != 1) return;

    for (int i = 0; i < N; i++) {
        if (scanf("%d", &fila_inicial[i]) != 1) return;
    }

    int M;
    if (scanf("%d", &M) != 1) return;
    
    for (int i = 0; i < M; i++) {
        int id_que_saiu;
        if (scanf("%d", &id_que_saiu) != 1) return;
        
        if (id_que_saiu >= 1 && id_que_saiu < MAX_ID) {
            saiu_da_fila[id_que_saiu] = true;
        }
    }

    bool primeira_saida = true;
    
    for (int i = 0; i < N; i++) {
        int id_atual = fila_inicial[i];
        
        if (!saiu_da_fila[id_atual]) {
            if (!primeira_saida) {
                printf(" ");
            }
            printf("%d", id_atual);
            primeira_saida = false;
        }
    }
    
    printf("\n");
}

int main() {
    solve();
    return 0;
}
