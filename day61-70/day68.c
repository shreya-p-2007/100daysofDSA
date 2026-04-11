/*Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int n;

// Function to perform Kahn's Algorithm
void topologicalSort() {
    int front = 0, rear = -1;
    int topo[MAX], k = 0;

    // Step 1: Calculate indegree of each node
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    // Step 2: Add nodes with indegree 0 to queue
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[++rear] = i;
        }
    }

    // Step 3: Process queue
    while (front <= rear) {
        int u = queue[front++];
        topo[k++] = u;

        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    queue[++rear] = v;
                }
            }
        }
    }

    // Step 4: Check for cycle
    if (k != n) {
        printf("Cycle detected! Topological sort not possible.\n");
        return;
    }

    // Step 5: Print result
    printf("Topological Order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", topo[i]);
    }
    printf("\n");
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    topologicalSort();

    return 0;
}