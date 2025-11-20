#include <stdio.h>
#include <stdlib.h>

#define INF 999

int main() {
    int n; 
    scanf("%d", &n);

    int **cost = malloc(n*sizeof(int));
    int **dist = malloc(n*sizeof(int));

    for(int i=0;i<n;i++){
        cost[i]=malloc(n*sizeof(int));
        dist[i]=malloc(n*sizeof(int));
        for(int j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
            dist[i][j]=cost[i][j];
        }
    }

    int changed;
    do {
        changed = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    if(dist[i][j] > cost[i][k] + dist[k][j]) {
                        dist[i][j] = cost[i][k] + dist[k][j];
                        changed = 1;
                    }
    } while(changed);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%d ", dist[i][j]);
        printf("\n");
    }
}
