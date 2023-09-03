#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10
#define INF 99999

int graph[MAX_VERTICES][MAX_VERTICES];
int path[MAX_VERTICES];
bool visited[MAX_VERTICES];
int n;

bool is_valid_vertex(int v) {
    return (v >= 0 && v < n);
}

bool is_hamiltonian(int v, int pos, int weight, bool is_directed) {
    if (pos == n) {
        if ((!is_directed && graph[v][0] != INF) || (is_directed && graph[v][0] != INF && weight + graph[v][0] != INF)) {
            path[pos] = 0;
            return true;
        } else {
            return false;
        }
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[v][i] != INF) {
            visited[i] = true;
            path[pos] = i;
            if (is_hamiltonian(i, pos + 1, weight + graph[v][i], is_directed))
                return true;
            visited[i] = false;
        }
    }

    return false;
}

void print_hamiltonian_circuit(int weight) {
    printf("Hamiltonian Circuit exists:\n");
    for (int i = 0; i < n; i++)
        printf("%d -> ", path[i]);
    printf("%d\n", path[0]);
    printf("Total weight of the circuit: %d\n", weight);
}

int main() {
    int i, j;
    bool is_directed;
    bool is_weighted;

    printf("Enter the number of vertices (maximum %d): ", MAX_VERTICES);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_VERTICES) {
        printf("Invalid number of vertices.\n");
        return 1;
    }

    printf("Is the graph directed? (0 for undirected, 1 for directed): ");
    scanf("%d", &is_directed);

    printf("Is the graph weighted? (0 for unweighted, 1 for weighted): ");
    scanf("%d", &is_weighted);

    printf("Enter the adjacency matrix (use INF for non-adjacent vertices):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for (i = 0; i < n; i++)
        visited[i] = false;

    visited[0] = true;
    path[0] = 0;

    if (is_hamiltonian(0, 1, 0, is_directed)) {
        if (!is_directed)
            print_hamiltonian_circuit(graph[path[n - 1]][0]);
        else
            print_hamiltonian_circuit(graph[path[n - 1]][path[0]]);
    } else {
        printf("Hamiltonian Circuit does not exist.\n");
    }

    return 0;
}