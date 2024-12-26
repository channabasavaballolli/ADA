#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Queue structure for BFS
struct Queue {
    int items[MAX];
    int front, rear;
};

// Graph structure
struct Graph {
    int adjMatrix[MAX][MAX];
    int vertices;
};

// Function to initialize the queue
void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
bool isEmpty(struct Queue* q) {
    return q->front == -1;
}

// Function to add an element to the queue
void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1)
        printf("Queue is full\n");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Function to remove an element from the queue
int dequeue(struct Queue* q) {
    if (isEmpty(q))
        printf("Queue is empty\n");
    else {
        int value = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
        return value;
    }
    return -1;
}

// Function to create a graph
void createGraph(struct Graph* g, int vertices) {
    g->vertices = vertices;
    
    // Initialize the adjacency matrix with 0 (no edges)
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

// Function to add an edge to the graph
void addEdge(struct Graph* g, int start, int end) {
    g->adjMatrix[start][end] = 1;
    g->adjMatrix[end][start] = 1; // For undirected graph
}

// BFS traversal function
void BFS(struct Graph* g, int start) {
    bool visited[MAX] = {false};
    struct Queue q;
    initQueue(&q);
    
    // Start by marking the source node as visited and enqueue it
    visited[start] = true;
    enqueue(&q, start);
    
    printf("Breadth First Search (BFS) starting from vertex %d:\n", start + 1);  // +1 to adjust for 1-based input
    
    while (!isEmpty(&q)) {
        int node = dequeue(&q);
        printf("%d ", node + 1);  // +1 to adjust for 1-based output
        
        // Explore all the adjacent nodes of the current node
        for (int i = 0; i < g->vertices; i++) {
            if (g->adjMatrix[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
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
    
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &start);
    
    BFS(&g, start - 1);  // Adjusting to 0-based indexing
    
    return 0;
}
