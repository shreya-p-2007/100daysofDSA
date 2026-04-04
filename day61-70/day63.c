/*Problem: Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node structure
struct Node {
    int vertex;
    struct Node* next;
};

// Adjacency list
struct Node* adj[MAX];
int visited[MAX];

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected)
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// DFS function (recursive)
void DFS(int v) {
    printf("%d ", v);
    visited[v] = 1;

    struct Node* temp = adj[v];

    while (temp != NULL) {
        int adjVertex = temp->vertex;

        if (!visited[adjVertex]) {
            DFS(adjVertex);
        }

        temp = temp->next;
    }
}

int main() {
    int n, m, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Initialize adjacency list and visited array
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    DFS(start);

    return 0;
}