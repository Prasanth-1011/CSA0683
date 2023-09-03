#include <stdio.h>
#define INF 999999

int minDistance(int dist[], int visited[], int n)
{
    int min = INF, minIndex;

    for (int i=0;i<n;i++)
	{
        if (visited[i] == 0 && dist[i] <= min)
		{
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(int graph[][10],int start,int n)
{
    int dist[10], visited[10];

    for (int i=0;i<n;i++)
	{
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (int count = 0; count < n - 1; count++)
	{
        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        for (int v=0;v<n;v++)
		{
            if (!visited[v] && graph[u][v] && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v])
				{
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Optimal Cost From Node %d To All Other Nodes :\n",start);
    
    for (int i=0;i<n;i++)
        printf("Node %d : Cost = %d\n",i,dist[i]);
}

int main()
{
    int n, graph[10][10], start;

    printf("Number of Nodes : ");
    scanf("%d",&n);

    printf("Enter Adjacency Matrix :\n");
    for (int i=0;i<n;i++)
	{
        for (int j=0;j<n;j++)
            scanf("%d", &graph[i][j]);
    }

    printf("\nEnter Starting Node : ");
    scanf("%d", &start);
    printf("\n");
    dijkstra(graph, start, n);
    return 0;
}