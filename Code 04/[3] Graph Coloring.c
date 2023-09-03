#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

bool isSafe(int node, int color, int graph[MAX_NODES][MAX_NODES], int n, int colors[])
{
    for (int i = 0; i < n; i++)
	{
        if (graph[node][i] && color == colors[i])
            return false;
    }
    return true;
}

void printColors(int colors[], int n)
{
    static int count = 0;
    printf("Coloring Combination %d :\n", ++count);
    for (int i = 0; i < n; i++)
        printf("Node %d : Color %d\n", i + 1, colors[i]);
    printf("\n");
}

void graphColoringUtil(int graph[MAX_NODES][MAX_NODES], int n, int m, int colors[], int node)
{
    if (node == n)
	{
        printColors(colors, n);
        return;
    }

    for (int color = 1; color <= m; color++)
	{
        if (isSafe(node, color, graph, n, colors))
		{
            colors[node] = color;

            graphColoringUtil(graph, n, m, colors, node + 1);
            colors[node] = 0;
        }
    }
}

void graphColoring(int graph[MAX_NODES][MAX_NODES], int n, int m) {
    int colors[MAX_NODES];
    for (int i = 0; i < n; i++)
	{
        colors[i] = 0;
    }

    for (int startColor = 1; startColor <= m; startColor++)
	{
        colors[0] = startColor;
        graphColoringUtil(graph, n, m, colors, 1);
    }
}

int main()
{
    int n, m;

    printf("Number of Vertices in Graph : ");
    scanf("%d", &n);
    printf("\nNumber of Colors : ");
    scanf("%d", &m);
    int graph[MAX_NODES][MAX_NODES];

    printf("\nEnter Adjacency Matrix (0 or 1) :\n");
    for (int i = 0; i < n; i++)
	{
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    }
    printf("\n");
    graphColoring(graph, n, m);
    return 0;
}