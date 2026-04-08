/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
*/
#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n;

// Push into stack
void push(int x) {
    stack[++top] = x;
}

// DFS function
void dfs(int v) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }

    // Push after visiting all adjacent nodes
    push(v);
}

// Topological Sort function
void topologicalSort() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // Print stack (reverse order)
    printf("Topological Order: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

// Main function
int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    topologicalSort();

    return 0;
}