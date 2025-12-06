#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 1005

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void stack_init(Stack *s) {
    s->top = -1;
}

bool stack_empty(Stack *s) {
    return s->top == -1;
}

void stack_push(Stack *s, int x) {
    if (s->top < MAX_SIZE - 1) {
        s->data[++s->top] = x;
    }
}

int stack_top(Stack *s) {
    if (!stack_empty(s)) {
        return s->data[s->top];
    }
    return -1;
}

void stack_pop(Stack *s) {
    if (!stack_empty(s)) {
        s->top--;
    }
}

typedef struct {
    int data[MAX_SIZE];
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
    if (q->size < MAX_SIZE) {
        q->rear = (q->rear + 1) % MAX_SIZE;
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
        q->front = (q->front + 1) % MAX_SIZE;
        q->size--;
    }
}

typedef struct {
    int data[MAX_SIZE];
    int size;
} PriorityQueue;

void pq_init(PriorityQueue *pq) {
    pq->size = 0;
}

bool pq_empty(PriorityQueue *pq) {
    return pq->size == 0;
}

void pq_push(PriorityQueue *pq, int x) {
    if (pq->size < MAX_SIZE) {
        int i;
        for (i = pq->size - 1; i >= 0 && pq->data[i] < x; i--) {
            pq->data[i + 1] = pq->data[i];
        }
        pq->data[i + 1] = x;
        pq->size++;
    }
}

int pq_top(PriorityQueue *pq) {
    if (!pq_empty(pq)) {
        return pq->data[0];
    }
    return -1;
}

void pq_pop(PriorityQueue *pq) {
    if (!pq_empty(pq)) {
        for (int i = 0; i < pq->size - 1; i++) {
            pq->data[i] = pq->data[i + 1];
        }
        pq->size--;
    }
}

void solve() {
    int n;
    
    while (scanf("%d", &n) != EOF) {
        Stack s;
        stack_init(&s);
        
        Queue q;
        queue_init(&q);
        
        PriorityQueue pq;
        pq_init(&pq);

        bool is_stack = true;
        bool is_queue = true;
        bool is_priority_queue = true;

        for (int i = 0; i < n; i++) {
            int command, x;
            if (scanf("%d %d", &command, &x) != 2) {
                break;
            }

            if (command == 1) {
                if (is_stack) stack_push(&s, x);
                if (is_queue) queue_push(&q, x);
                if (is_priority_queue) pq_push(&pq, x);
            } else {
                
                if (is_stack) {
                    if (stack_empty(&s) || stack_top(&s) != x) {
                        is_stack = false; 
                    } else {
                        stack_pop(&s); 
                    }
                }

                if (is_queue) {
                    if (queue_empty(&q) || queue_front(&q) != x) {
                        is_queue = false; 
                    } else {
                        queue_pop(&q); 
                    }
                }

                if (is_priority_queue) {
                    if (pq_empty(&pq) || pq_top(&pq) != x) {
                        is_priority_queue = false; 
                    } else {
                        pq_pop(&pq); 
                    }
                }
            
                if (!is_stack && !is_queue && !is_priority_queue) {
                    for (int j = i + 1; j < n; j++) {
                        int dump_command, dump_x;
                        scanf("%d %d", &dump_command, &dump_x);
                    }
                    break;
                }
            }
        }

        int possible_count = is_stack + is_queue + is_priority_queue;

        if (possible_count == 0) {
            printf("impossible\n");
        } else if (possible_count > 1) {
            printf("not sure\n");
        } else {
            if (is_stack) {
                printf("stack\n");
            } else if (is_queue) {
                printf("queue\n");
            } else if (is_priority_queue) {
                printf("priority queue\n");
            }
        }
    }
}

int main() {
    solve();
    return 0;
}
