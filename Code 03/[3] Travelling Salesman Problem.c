#include <stdio.h>
#include <limits.h>

#define MAX_States 10

int numStates;
int distance[MAX_States][MAX_States];
int dp[MAX_States][1 << MAX_States];

int tsp(int currentState, int visited)
{
    if (visited == (1 << numStates) - 1)
        return distance[currentState][0];

    if (dp[currentState][visited] != -1)
        return dp[currentState][visited];

    int minDistance = INT_MAX;

    for (int nextState = 0; nextState < numStates; nextState++)
	{
        if (nextState != currentState && !(visited & (1 << nextState)))
		{
            int newVisited = visited | (1 << nextState);
            int newDistance = distance[currentState][nextState] + tsp(nextState, newVisited);
            minDistance = (newDistance < minDistance) ? newDistance : minDistance;
        }
    }
    dp[currentState][visited] = minDistance;
    return minDistance;
}

int main()
{
    printf("Enter Number of States : ");
    scanf("%d",&numStates);

    printf("Enter Distance Matrix (%d x %d) :\n",numStates,numStates);
    
    for (int i=0;i < numStates;i++)
        for (int j=0;j < numStates;j++)
            scanf("%d", &distance[i][j]);

    for (int i=0;i < numStates;i++)
        for (int j=0;j < (1 << numStates);j++)
            dp[i][j] = -1;

    int shortestPath = tsp(0,1);
    printf("\nShortest Path Length : %d\n", shortestPath);
    return 0;
}