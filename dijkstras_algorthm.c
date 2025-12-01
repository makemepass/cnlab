#include <stdio.h>
#define INF 9999
#define MAX 10

void dijkstra(int g[MAX][MAX], int n, int start) {
    int dist[MAX], visited[MAX], pred[MAX];
    int i, j, next;

    // Replace 0s with INF (no edge)
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (g[i][j] == 0 && i != j)
                g[i][j] = INF;

    // Initialize
    for (i = 0; i < n; i++) {
        dist[i] = g[start][i];
        pred[i] = start;
        visited[i] = 0;
    }

    dist[start] = 0;
    visited[start] = 1;

    // Main loop
    for (int count = 1; count < n; count++) {
        int min = INF;
        for (i = 0; i < n; i++)
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                next = i;
            }

        visited[next] = 1;

        // Update neighbors
        for (i = 0; i < n; i++)
            if (!visited[i] && min + g[next][i] < dist[i]) {
                dist[i] = min + g[next][i];
                pred[i] = next;
            }
    }

    // Print all shortest paths
    for (i = 0; i < n; i++) {
        if (i != start) {
            printf("\nDistance to %d = %d\nPath: %d", i, dist[i], i);
            j = i;
            while (j != start) {
                j = pred[j];
                printf(" <- %d", j);
            }
            printf("\n");
        }
    }
}

int main() {
    int g[MAX][MAX], n, start;

    printf("Nodes: ");
    scanf("%d", &n);

    printf("Adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &g[i][j]);

    printf("Start node: ");
    scanf("%d", &start);

    dijkstra(g, n, start);
    return 0;
}
