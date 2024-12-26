#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

struct Graph {
    int adjMatrix[MAX][MAX];
    int vertices;
};

// Function to create the graph
void createGraph(struct Graph* g, int vertices) {
    g->vertices = vertices;
    
    // Initialize the adjacency matrix with 0 (no edges)
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

// Function to add an edge
void addEdge(struct Graph* g, int start, int end) {
    g->adjMatrix[start][end] = 1;
    g->adjMatrix[end][start] = 1; // For undirected graph
}

// DFS function
void DFS(struct Graph* g, int vertex, bool visited[]) {
    // Mark the current node as visited and print it (convert to 1-based indexing)
    visited[vertex] = true;
    printf("%d ", vertex + 1);  // Output in 1-based indexing
    
    // Recur for all the adjacent vertices
    for (int i = 0; i < g->vertices; i++) {
        if (g->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(g, i, visited);
        }
    }
}

int main() {
    struct Graph g;
    int vertices, edges, start, u, v;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    
    createGraph(&g, vertices);
    
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    
    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        addEdge(&g, u - 1, v - 1);  // Adjusting to 0-based indexing
    }
    
    bool visited[MAX] = {false};
    
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &start);
    
    printf("Depth First Search (DFS) starting from vertex %d:\n", start);
    
    DFS(&g, start - 1, visited);  // Adjusting to 0-based indexing
    
    printf("\n");
    
    return 0;
}
