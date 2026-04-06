/*Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

Output:
- YES or NO 
*/
#include <stdio.h>

#define MAX 100

int visited[MAX];
int adj[MAX][MAX];
int V;

// DFS function
int dfs(int node, int parent) {
    visited[node] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                if (dfs(i, node))
                    return 1;
            }
            // visited and not parent → cycle
            else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int E;
    scanf("%d %d", &V, &E);

    // Initialize adjacency matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    // Input edges
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // Initialize visited
    for (int i = 0; i < V; i++)
        visited[i] = 0;

    // Check for cycle in each component
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}