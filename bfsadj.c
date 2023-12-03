//4.Create an adjacency list for graph and implement BFS.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a node in the adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Structure to represent the adjacency list
struct Graph {
    int V;              // Number of vertices
    struct Node** array; // Array of linked lists
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct Node**)malloc(V * sizeof(struct Node*));

    for (int i = 0; i < V; i++) {
        graph->array[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src];
    graph->array[src] = newNode;

    newNode = createNode(src); // For undirected graph, add the reverse edge
    newNode->next = graph->array[dest];
    graph->array[dest] = newNode;
}

// Function to perform Breadth-First Search (BFS)
void BFS(struct Graph* graph, int start) {
    bool* visited = (bool*)malloc(graph->V * sizeof(bool));
    for (int i = 0; i < graph->V; i++) {
        visited[i] = false;
    }

    struct Node* queue[graph->V];
    int front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = graph->array[start];

    printf("BFS starting from vertex %d: ", start);

    while (front != rear) {
        struct Node* current = queue[front++];
        printf("%d ", current->data);

        while (current != NULL) {
            int vertex = current->data;
            if (!visited[vertex]) {
                visited[vertex] = true;
                queue[rear++] = graph->array[vertex];
            }
            current = current->next;
        }
    }

    printf("\n");
}

int main() {
    int V = 4;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    int startVertex = 2;
    BFS(graph, startVertex);

    return 0;
}

