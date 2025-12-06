```c
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 501
#define INF 1000000000

int N, E;
int dist[MAX_N][MAX_N];
bool conn[MAX_N][MAX_N];

void initialize_matrices() {
    int i, j;
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) {
            if (i == j) {
                dist[i][j] = 0;
                conn[i][j] = true;
            } else {
                dist[i][j] = INF;
                conn[i][j] = false;
            }
        }
    }
}

void read_agreements() {
    int x, y, h;
    for (int i = 0; i < E; i++) {
        if (scanf("%d %d %d", &x, &y, &h) != 3) return;
        
        if (dist[x][y] > h) {
            dist[x][y] = h;
        }
        
        conn[x][y] = true;
    }
}

void apply_warshall() {
    int k, i, j;
    for (k = 1; k <= N; k++) {
        for (i = 1; i <= N; i++) {
            for (j = 1; j <= N; j++) {
                conn[i][j] = conn[i][j] || (conn[i][k] && conn[k][j]);
            }
        }
    }
    
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) {
            if (conn[i][j] && conn[j][i]) {
                dist[i][j] = 0;
            }
        }
    }
}

void apply_floyd_warshall() {
    int k, i, j;
    for (k = 1; k <= N; k++) {
        for (i = 1; i <= N; i++) {
            for (j = 1; j <= N; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
}

void process_queries() {
    int K;
    if (scanf("%d", &K) != 1) return;
    
    for (int i = 0; i < K; i++) {
        int O, D;
        if (scanf("%d %d", &O, &D) != 2) return;
        
        int min_time = dist[O][D];
        
        if (min_time >= INF) {
            printf("Nao e possivel entregar a carta\n");
        } else {
            printf("%d\n", min_time);
        }
    }
}

void solve() {
    while (scanf("%d %d", &N, &E) == 2 && (N != 0 || E != 0)) {
        
        initialize_matrices();
        read_agreements();
        
        apply_warshall();
        apply_floyd_warshall();
        
        process_queries();
        
        printf("\n");
    }
}

int main() {
    solve();
    return 0;
}
```
