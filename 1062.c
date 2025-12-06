#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_N 1005

typedef struct {
    int data[MAX_N];
    int top;
} Stack;

void stack_init(Stack *s) {
    s->top = -1;
}

bool stack_empty(Stack *s) {
    return s->top == -1;
}

void stack_push(Stack *s, int x) {
    if (s->top < MAX_N - 1) {
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

void check_reorganization(int n, int required_output[]) {
    Stack shunting_yard;
    stack_init(&shunting_yard);
    
    int next_input = 1; 
    int required_output_idx = 0;
    
    while (required_output_idx < n) {
        int expected_car = required_output[required_output_idx];

        if (!stack_empty(&shunting_yard) && stack_top(&shunting_yard) == expected_car) {
            stack_pop(&shunting_yard);
            required_output_idx++;
        }
        
        else if (next_input <= n) {
            stack_push(&shunting_yard, next_input);
            next_input++; 
        } 
        
        else {
            printf("No\n");
            return;
        }
    }

    printf("Yes\n");
}

int main() {
    int n;
    
    while (scanf("%d", &n) == 1 && n != 0) {
        int required_output[MAX_N];
        int first_car;

        while (1) {
            if (scanf("%d", &first_car) != 1) break; 
            
            if (first_car == 0) break; 

            required_output[0] = first_car;
            
            for (int i = 1; i < n; i++) {
                if (scanf("%d", &required_output[i]) != 1) {
                }
            }

            check_reorganization(n, required_output);
        }
        
        printf("\n");
    }

    return 0;
}
