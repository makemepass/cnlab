#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100
#define INF 9999

int minDistance(int dist[], bool visited[], int n) {
    int min = INF, min_index;
    for (int v = 0; v < n; v++)
        if (!visited[v] && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    printf(" %c", j + 'a');
}

void dijkstra(int graph[MAX][MAX], int n, int src, int dest) {
    int dist[MAX];
    bool visited[MAX];
    int parent[MAX];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("\nshortest path \nfrom %c to %c is : %c", src + 'a', dest + 'a', src + 'a');
    printPath(parent, dest);
    printf("\nlength=%d\n", dist[dest]);
}

int main() {
    int n, graph[MAX][MAX];
    char srcChar, destChar;

    printf("shortest path dijkstras algorithm\n");
    printf("***********************************\n");
    printf("enter no of nodes: ");
    scanf("%d", &n);

    printf("enter the adjacency matrix\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == -1)
                graph[i][j] = INF;  // Replace -1 with INF
        }
    }

    printf("enter source node: ");
    scanf(" %c", &srcChar);
    printf("enter destination node: ");
    scanf(" %c", &destChar);

    int src = srcChar - 'a';
    int dest = destChar - 'a';

    dijkstra(graph, n, src, dest);
    return 0;
}
