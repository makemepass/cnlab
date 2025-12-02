#include<stdio.h>
#include<limits.h>
#define MAX 100
#define INF INT_MAX

int main()
{
 int n,i,j,r;
 int cost[MAX][MAX];
 int distance[MAX];
 int parent[MAX];
 int visited[MAX];
 
 printf("enter no of routers: ");
 scanf("%d",&n);
 printf("enter cost(-1 for no direct link): ");
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
   printf("%d->%d:",i,j);
   scanf("%d",&cost[i][j]);
   if(cost[i][j]<0) cost[i][j]=INF;
  }
 }
 int src;
 printf("enter source router: ");
 scanf("%d",&src);
 for(i=0;i<n;i++)
 {
  distance[i]=cost[src][i];
  parent[i]=src;
  visited[i]=0;
 }
 visited[src]=1;
 for(int step=0;step<n-1;step++)
 {
  int mindist=INF,nextrouter=-1;
  for(r=0;r<n;r++)
  {
   if(!visited[r]&&distance[r]<mindist)
   {
    mindist=distance[r];
    nextrouter=r;
   }
  }
  if(nextrouter==-1) break;
  visited[nextrouter]=1;
  for(int r=0;r<n;r++)
  {
   if(!visited[r]&&
      cost[nextrouter][r]!=INF&&
      distance[nextrouter]+cost[nextrouter][r]<distance[r])
   {
    distance[r]=distance[nextrouter]+cost[nextrouter][r];
    parent[r]=nextrouter;
   }
  }
 }
 printf("shortest path from route %d: ",src);
 for(int dest=0;dest<n;dest++)
 {
  if(dest==src) continue;
  printf("%d==>%d: Path: %d",src,dest,dest);
  int p=dest;
  while(p!=src)
  {
   printf("<--%d",parent[p]);
   p=parent[p];
  }
  printf("\nCost: %d\n",distance[dest]);
 }
 return 0;
}
