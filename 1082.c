#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NODES 26

typedef struct Node {
    int v;
    struct Node *next;
} Node;

Node *adj[MAX_NODES];
bool visited[MAX_NODES];
char component_vertices[MAX_NODES + 1];
int comp_count;
int V_total;

void add_edge(int u, int v) {
    Node *new_node_u = (Node *)malloc(sizeof(Node));
    new_node_u->v = v;
    new_node_u->next = adj[u];
    adj[u] = new_node_u;

    Node *new_node_v = (Node *)malloc(sizeof(Node));
    new_node_v->v = u;
    new_node_v->next = adj[v];
    adj[v] = new_node_v;
}

void free_graph() {
    for (int i = 0; i < V_total; i++) {
        Node *current = adj[i];
        while (current != NULL) {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
        adj[i] = NULL;
    }
}

void dfs(int u) {
    visited[u] = true;
    component_vertices[comp_count++] = 'a' + u;

    Node *current = adj[u];
    while (current != NULL) {
        int v = current->v;
        if (!visited[v]) {
            dfs(v);
        }
        current = current->next;
    }
}

int compare_chars(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

void solve_case(int case_num) {
    int E;
    
    if (scanf("%d %d", &V_total, &E) != 2) return;

    memset(adj, 0, sizeof(adj));
    memset(visited, 0, sizeof(visited));
    
    for (int i = 0; i < E; i++) {
        char u_char, v_char;
        if (scanf(" %c %c", &u_char, &v_char) != 2) return;
        
        int u = u_char - 'a';
        int v = v_char - 'a';
        add_edge(u, v);
    }
    
    printf("Case #%d:\n", case_num);
    
    int connected_components_count = 0;
    
    for (int i = 0; i < V_total; i++) {
        if (!visited[i]) {
            connected_components_count++;
            comp_count = 0;
            
            dfs(i);
            
            component_vertices[comp_count] = '\0';
            
            qsort(component_vertices, comp_count, sizeof(char), compare_chars);
            
            for (int j = 0; j < comp_count; j++) {
                printf("%c,", component_vertices[j]);
            }
            printf("\n");
        }
    }
    
    printf("%d connected components\n", connected_components_count);
    
    printf("\n");
    free_graph();
}

int main() {
    int N_cases;
    if (scanf("%d", &N_cases) != 1) return 0;
    
    for (int i = 1; i <= N_cases; i++) {
        solve_case(i);
    }
    
    return 0;
}
