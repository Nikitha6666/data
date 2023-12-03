// 6. Create adjacency list for graph and find its connected components using dfs.


#include <stdio.h>
#include <stdlib.h>
 
// Structure to represent a node in the adjacency list
struct Node {
    int data;
    struct Node* next;
};
 
// Structure to represent the adjacency list for a graph
struct Graph {
    int vertices;
    struct Node** adjList;
};
 
// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
 
// Create a new graph with 'V' vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = V;
    graph->adjList = (struct Node**)malloc(V * sizeof(struct Node*));
    for (int i = 0; i < V; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}
 
// Add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
 
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}
 
// Depth-First Search to find connected components
void DFS(struct Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);
 
    struct Node* temp = graph->adjList[vertex];
    while (temp) {
        int adjVertex = temp->data;
        if (!visited[adjVertex]) {
            DFS(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}
 
// Find connected components in the graph
void findConnectedComponents(struct Graph* graph) {
    int V = graph->vertices;
    int* visited = (int*)malloc(V * sizeof(int));
 
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }
 
    int component = 0;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            printf("Connected Component %d: ", component + 1);
            DFS(graph, i, visited);
            printf("\n");
            component++;
        }
    }
}
 
int main() {
    int V = 7; // Number of vertices in the graph
    struct Graph* graph = createGraph(V);
 
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 3, 4);
    addEdge(graph, 5, 6);
 
    printf("Connected Components:\n");
    findConnectedComponents(graph);
 
    return 0;
}
