#include <stdio.h>
#include <stdbool.h>

#define MAX 100
#define INF 9999

int minNode(int dist[], bool visited[], int n) {
    int min = INF, index = -1;
    for (int i = 0; i < n; i++)
        if (!visited[i] && dist[i] < min)
            min = dist[i], index = i;
    return index;
}

void printPath(int parent[], int v) {
    if (parent[v] == -1) return;
    printPath(parent, parent[v]);
    printf(" %c", v + 'a');
}

void dijkstraLSR(int g[MAX][MAX], int n, int src, int dest) {
    int dist[MAX], parent[MAX];
    bool visited[MAX];

    for (int i = 0; i < n; i++)
        dist[i] = INF, visited[i] = false, parent[i] = -1;

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minNode(dist, visited, n);
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && g[u][v] != INF &&
                dist[u] + g[u][v] < dist[v]) {

                dist[v] = dist[u] + g[u][v];
                parent[v] = u;
            }
        }
    }

    printf("\nShortest path from %c to %c:\n", src + 'a', dest + 'a');
    printf("%c", src + 'a');
    printPath(parent, dest);
    printf("\nCost = %d\n", dist[dest]);
}

int main() {
    int n, g[MAX][MAX];
    char s, d;

    printf("Number of nodes: ");
    scanf("%d", &n);

    printf("Adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &g[i][j]);
            if (g[i][j] == -1) g[i][j] = INF;
        }

    printf("Source (a,b,c...): ");
    scanf(" %c", &s);
    printf("Destination: ");
    scanf(" %c", &d);

    dijkstraLSR(g, n, s - 'a', d - 'a');
    return 0;
}
