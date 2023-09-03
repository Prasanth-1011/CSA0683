#include <stdio.h>
#define MAX 10

int n, path[MAX];
int graph[MAX][MAX];

void displayHamiltonianCircuit()
{
    printf("\nHamiltonian Circuit : ");
    for (int i = 0; i < n; i++)
        printf("%d ", path[i]);
    
    printf("%d\n", path[0]);
}

int isValidVertex(int v, int pos)
{
    if (graph[path[pos - 1]][v] == 0)
        return 0;

    for (int i = 0; i < pos; i++)
	{
        if (path[i] == v)
            return 0;
    }
    return 1;
}

int hamiltonianCircuitUtil(int pos)
{
    if (pos == n)
	{
        if (graph[path[pos - 1]][path[0]] == 1)
		{
            displayHamiltonianCircuit();
            return 1;
        }
        return 0;
    }

    for (int v = 1; v < n; v++)
	{
        if (isValidVertex(v, pos))
		{
            path[pos] = v;
            if (hamiltonianCircuitUtil(pos + 1))
                return 1;

            path[pos] = -1;
        }
    }
    return 0;
}

int findHamiltonianCircuit()
{
    path[0] = 0;
    if (hamiltonianCircuitUtil(1) == 0)
	{
        printf("\nHamiltonian Circuit Does Not Exist.\n");
        return 0;
    }
    return 1;
}

int main()
{
    printf("Number of Vertices : ");
    scanf("%d", &n);

    printf("\nEnter Adjacency Matrix (1/0) :\n");
    for (int i = 0; i < n; i++)
	{
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    }

    if (findHamiltonianCircuit())
        printf("Hamiltonian Circuit Found.\n");

    return 0;
}