#include <stdio.h>

#define V 4
#define INF 99999

void printSolution(int dist[][V]);

void floydWarshall(int dist[][V])
{
    int i, j, k;

    for (k = 0; k < V; k++)
	{
        for (i = 0; i < V; i++)
		{
            for (j = 0; j < V; j++)
			{
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printSolution(dist);
}

void printSolution(int dist[][V])
{
    printf("The Matrix Shows Shortest Distances Between Every Pair of Vertices\n");
    for (int i = 0; i < V; i++)
	{
        for (int j = 0; j < V; j++)
		{
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int graph[V][V] = {{000, 005, INF, 010},
                       {INF, 000, 003, INF},
                       {INF, INF, 000, 001},
                       {INF, INF, INF, 000}};

    floydWarshall(graph);
    return 0;
}