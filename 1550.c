#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NUM 10000

int queue[MAX_NUM * 2];
int head, tail;

int dist[MAX_NUM];

void enqueue(int n) {
    if (tail < MAX_NUM * 2) {
        queue[tail++] = n;
    }
}

int dequeue() {
    if (head < tail) {
        return queue[head++];
    }
    return -1;
}

bool is_empty() {
    return head == tail;
}

int reverse_number(int n) {
    int reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + (n % 10);
        n /= 10;
    }
    return reversed;
}

int solve_bfs(int A, int B) {
    memset(dist, -1, sizeof(dist));

    head = 0;
    tail = 0;

    dist[A] = 0;
    enqueue(A);

    while (!is_empty()) {
        int current_num = dequeue();
        int current_dist = dist[current_num];

        if (current_num == B) {
            return current_dist;
        }

        int next_num_add = current_num + 1;
        
        if (next_num_add < MAX_NUM && dist[next_num_add] == -1) {
            dist[next_num_add] = current_dist + 1;
            enqueue(next_num_add);
        }

        int next_num_rev = reverse_number(current_num);

        if (next_num_rev < MAX_NUM && dist[next_num_rev] == -1) {
            dist[next_num_rev] = current_dist + 1;
            enqueue(next_num_rev);
        }
    }

    return -1;
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;

    while (T--) {
        int A, B;
        if (scanf("%d %d", &A, &B) != 2) return 0;
        
        int min_taps = solve_bfs(A, B);
        printf("%d\n", min_taps);
    }

    return 0;
}
