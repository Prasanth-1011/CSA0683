#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX_VERTICES 20
#define infinity 999

struct edge
{
    int src;
    int dest;
    int weight;
};

struct subset
{
    int parent;
    int rank;
};

int Totalcost = 0;
struct edge edges[MAX_VERTICES];
struct subset subsets[MAX_VERTICES];

int find(int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets[i].parent);
    return subsets[i].parent;
}

void Union(int x, int y)
{
    int xroot = find(x);
    int yroot = find(y);

    if(subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if(subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
}

int compare(const void* a, const void* b)
{
    struct edge* edge1 = (struct edge*)a;
    struct edge* edge2 = (struct edge*)b;
    return edge1->weight - edge2->weight;
}

int isCycle(int src, int dest)
{
    int srcRoot = find(src);
    int destRoot = find(dest);
    if (srcRoot == destRoot)
        return 1;
    return 0;
}

void Kruskal(int V, int E)
{
    int i, e;
    qsort(edges, E, sizeof(struct edge), compare);

    for (i = 1; i <= V; i++)
        subsets[i].parent = i;
        subsets[i].rank = 0;

    for (e = 0; e < E; e++)
	{
        int src = edges[e].src;
        int dest = edges[e].dest;
        int weight = edges[e].weight;

        if (!isCycle(src, dest))
        {
        	printf("Edge (%d-%d) Weight: %d\n", src, dest, weight);
            Totalcost += weight;
            Union(src, dest);
		}
    }
}

int main()
{ 
    int v,e,i;
    printf("Enter Number of Vertices : ");
    scanf("%d",&v);
    printf("Enter Number of Edges : ");
    scanf("%d",&e);

    printf("\nEnter Edges Respective Weights :\n");
    for (i=0;i<e;i++)
	{
        printf("Edge %d : ",i+1);
        scanf("%d %d %d",&edges[i].src,&edges[i].dest,&edges[i].weight);
    }

    printf("\nMinimum Spanning Tree :\n");
    Kruskal(v,e);
    printf("\nTotal Cost : %d\n", Totalcost);
    getch();
    return 0;
}