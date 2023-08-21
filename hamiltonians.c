#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 10
int graph[MAX_VERTICES][MAX_VERTICES];
int path[MAX_VERTICES];
bool visited[MAX_VERTICES];
int numVertices;
void initialize() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        visited[i] = false;
        path[i] = -1;
        for (int j = 0; j < MAX_VERTICES; j++) {
            graph[i][j] = 0;
        }
    }
}
void readGraph() {
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}
void printPath() {
    printf("Hamiltonian Circuit: ");
    for (int i = 0; i < numVertices; i++) {
        printf("%c ", 'A' + path[i]);
    }
    printf("%c\n", 'A' + path[0]);
}
bool isSafe(int v, int pos) {
    if (!graph[path[pos - 1]][v])
        return false;
    for (int i = 0; i < pos; i++) {
        if (path[i] == v)
            return false;
    }
    return true;
}
void findAllHamiltonians(int pos) {
    if (pos == numVertices) {
        if (graph[path[pos - 1]][path[0]]) {
            printPath();
        }
        return;
    }
    for (int v = 1; v < numVertices; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;
            findAllHamiltonians(pos + 1);
            path[pos] = -1;
        }
    }
}
int main() {
    initialize();
    readGraph();
    path[0] = 0;
    findAllHamiltonians(1);

    return 0;
}

