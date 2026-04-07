/*Problem: Detect cycle in directed graph using DFS and recursion stack.

Output:
- YES if cycle exists 
*/
#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int recStack[MAX];
int n;

/* DFS function to detect cycle */
int dfs(int node) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[node][i]) {
            if (!visited[i] && dfs(i))
                return 1;
            else if (recStack[i])
                return 1;
        }
    }

    recStack[node] = 0; // remove from recursion stack
    return 0;
}

int main() {
    int e, u, v;

    scanf("%d %d", &n, &e);

    // initialize
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
    }

    // input edges
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    // check cycle
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i)) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}