#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_CARDS 55

typedef struct {
    int data[MAX_CARDS];
    int front;
    int rear;
    int size;
} Queue;

void queue_init(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

bool queue_empty(Queue *q) {
    return q->size == 0;
}

void queue_push(Queue *q, int x) {
    if (q->size < MAX_CARDS) {
        q->rear = (q->rear + 1) % MAX_CARDS;
        q->data[q->rear] = x;
        q->size++;
    }
}

int queue_front(Queue *q) {
    if (!queue_empty(q)) {
        return q->data[q->front];
    }
    return -1;
}

void queue_pop(Queue *q) {
    if (!queue_empty(q)) {
        q->front = (q->front + 1) % MAX_CARDS;
        q->size--;
    }
}

void solve_card_game(int n) {
    if (n == 0) return;

    Queue deck;
    queue_init(&deck);
    for (int i = 1; i <= n; i++) {
        queue_push(&deck, i);
    }

    int discarded[MAX_CARDS];
    int discarded_count = 0;

    while (deck.size >= 2) {
        int discarded_card = queue_front(&deck);
        queue_pop(&deck);
        
        discarded[discarded_count++] = discarded_card;

        int moved_card = queue_front(&deck);
        queue_pop(&deck);
        queue_push(&deck, moved_card);
    }
    
    printf("Discarded cards: ");
    for (int i = 0; i < discarded_count; i++) {
        printf("%d", discarded[i]);
        if (i < discarded_count - 1) {
            printf(", ");
        }
    }
    printf("\n");

    if (deck.size == 1) {
        printf("Remaining card: %d\n", queue_front(&deck));
    } else {
        printf("Remaining card: %d\n", 1); 
    }
}

int main() {
    int n;
    
    while (scanf("%d", &n) == 1 && n != 0) {
        solve_card_game(n);
    }

    return 0;
}
