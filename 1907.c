#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 1024

typedef struct {
    int r, c;
} Point;

char grid[MAX_SIZE][MAX_SIZE];
int N, M;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

Point queue[MAX_SIZE * MAX_SIZE];
int head, tail;

void enqueue(int r, int c) {
    queue[tail].r = r;
    queue[tail].c = c;
    tail = (tail + 1) % (MAX_SIZE * MAX_SIZE);
}

Point dequeue() {
    Point p = queue[head];
    head = (head + 1) % (MAX_SIZE * MAX_SIZE);
    return p;
}

bool queue_empty() {
    return head == tail;
}

void bfs(int start_r, int start_c) {
    head = 0;
    tail = 0;
    
    enqueue(start_r, start_c);
    grid[start_r][start_c] = 'o';

    while (!queue_empty()) {
        Point current = dequeue();
        int r = current.r;
        int c = current.c;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < N && nc >= 0 && nc < M && grid[nr][nc] == '.') {
                grid[nr][nc] = 'o';
                enqueue(nr, nc);
            }
        }
    }
}

void solve() {
    if (scanf("%d %d", &N, &M) != 2) return;

    for (int i = 0; i < N; i++) {
        if (scanf("%s", grid[i]) != 1) return;
    }

    int cliques = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            
            if (grid[i][j] == '.') {
                
                cliques++;
                
                bfs(i, j);
            }
        }
    }

    printf("%d\n", cliques);
}

int main() {
    solve();
    return 0;
}
