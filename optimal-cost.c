#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 20
struct Edge {
    int source, destination, weight;
};
void swap(struct Edge *a, struct Edge *b) {
    struct Edge temp = *a;
    *a = *b;
    *b = temp;
}
int compareEdges(const void *a, const void *b) {
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}
int findParent(int parent[], int node) {
    if (parent[node] == -1)
        return node;
    return findParent(parent, parent[node]);
}
void kruskal(int graph[MAX_NODES][MAX_NODES], int numNodes) {
    struct Edge edges[MAX_NODES * MAX_NODES];
    int edgeCount = 0;
    for (int i = 0; i < numNodes; i++) {
        for (int j = i + 1; j < numNodes; j++) {
            if (graph[i][j] != 0) {
                edges[edgeCount].source = i;
                edges[edgeCount].destination = j;
                edges[edgeCount].weight = graph[i][j];
                edgeCount++;
            }
        }
    }
    qsort(edges, edgeCount, sizeof(struct Edge), compareEdges);
    int parent[MAX_NODES];
    for (int i = 0; i < numNodes; i++)
        parent[i] = -1;
    printf("Minimum Spanning Tree:\n");
    int mstWeight = 0;
    for (int i = 0; i < edgeCount; i++) {
        int sourceParent = findParent(parent, edges[i].source);
        int destParent = findParent(parent, edges[i].destination);
        if (sourceParent != destParent) {
            printf("%d -- %d : %d\n", edges[i].source, edges[i].destination, edges[i].weight);
            mstWeight += edges[i].weight;
            parent[sourceParent] = destParent;
        }
    }
    printf("Minimum Spanning Tree Weight: %d\n", mstWeight);
}
int main() {
    int numNodes;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &numNodes);
    int graph[MAX_NODES][MAX_NODES];
    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    kruskal(graph, numNodes);
}

