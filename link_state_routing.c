#include <stdio.h>
#define INF 9999
#define MAX 10

void dijkstra(int graph[MAX][MAX], int n, int start) {
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, minDist, nextNode, i, j;

    // Step 1: Initialize cost matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (graph[i][j] == 0)
                cost[i][j] = INF;
            else
                cost[i][j] = graph[i][j];

    // Step 2: Initialize distance and predecessor arrays
    for (i = 0; i < n; i++) {
        distance[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }

    distance[start] = 0;
    visited[start] = 1;
    count = 1;

    // Step 3: Find shortest path for each node
    while (count < n - 1) {
        minDist = INF;

        // Choose the next node with the smallest tentative distance
        for (i = 0; i < n; i++)
            if (distance[i] < minDist && !visited[i]) {
                minDist = distance[i];
                nextNode = i;
            }

        // Mark the chosen node as visited
        visited[nextNode] = 1;

        // Update the distance of neighboring nodes
        for (i = 0; i < n; i++)
            if (!visited[i])
                if (minDist + cost[nextNode][i] < distance[i]) {
                    distance[i] = minDist + cost[nextNode][i];
                    pred[i] = nextNode;
                }

        count++;
    }

    // Step 4: Print the results
    for (i = 0; i < n; i++) {
        if (i != start) {
            printf("\nDistance from node %d to node %d = %d", start, i, distance[i]);
            printf("\nPath = %d", i);
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
    int graph[MAX][MAX], n, start, i, j;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 for no direct link):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting node: ");
    scanf("%d", &start);

    dijkstra(graph, n, start);
    return 0;
}
