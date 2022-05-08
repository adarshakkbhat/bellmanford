#include<stdio.h>
#include<stdlib.h>
struct Edge
{
    int src;
    int dest;
    int w;
};
int main()
{
    int v,e,i,j,src,dest,w,sum=9999,dist[20],start;
    struct Edge* edge=(struct Edge*)malloc(sizeof(struct Edge));
    printf("Enter the number of vertices\n");
    scanf("%d",&v);
    printf("Enter the number of edges\n");
    scanf("%d",&e);
    printf("src dest weight\n");
    for ( i = 0; i < e; i++)
    {
        scanf("%d %d %d",&src,&dest,&w);
        edge[i].src=src;
        edge[i].dest=dest;
        edge[i].w=w;
    }
    for ( i = 0; i < v; i++)
    {
        dist[i]=9999;
    }
    printf("Enter source vertex\n");
    scanf("%d",&start);
    dist[start]=0;
    
    for(i=0;i<v-1;i++)
    {
        for(j=0;j<e;j++)
        {
            src=edge[j].src;
            dest=edge[j].dest;
            w=edge[j].w;
            sum=w+dist[src];
            if(dist[dest]>sum)
            {
                dist[dest]=sum;
            }
        }
    }
    for(i=0;i<e;i++)
    {
        src=edge[i].src;
        dest=edge[i].dest;
        w=edge[i].w;
        sum=dist[src]+w;
        if(sum<dist[dest])
        {
            printf("Negetive edge cycle detected\n");
            return -1;
        }
    }
    for(i=0;i<v;i++)
    {
        printf("%d-->%d : %d\n",start,i,dist[i]);
    }

    realloc(edge,0);
}