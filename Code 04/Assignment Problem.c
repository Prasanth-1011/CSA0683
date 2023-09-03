#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define N 5

int minCost = INT_MAX;
bool assigned[N] = {false};
int assignment[N] = {0};
int costMatrix[N][N];

void calculateCost(int row, int costSoFar)
{
    if (row == N)
	{
        if (costSoFar < minCost)
		{
            minCost = costSoFar;
            for (int i = 0; i < N; i++)
                assignment[i] = costMatrix[i][i];
        }
        return;
    }

    for (int col = 0; col < N; col++)
	{
        if (!assigned[col]) {
            assigned[col] = true;
            calculateCost(row + 1, costSoFar + costMatrix[row][col]);
            assigned[col] = false;
        }
    }
}

int main() {
    printf("Enter Cost Matrix :\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &costMatrix[i][j]);
        }
    }

    calculateCost(0, 0);

    printf("\nMinimum Assignment Cost : %d\n", minCost);
    printf("Assignment Array : ");
    for (int i = 0; i < N; i++) {
        printf("(%d, %d) ", i + 1, assignment[i] + 1);
    }

    return 0;
}
