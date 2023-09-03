#include <stdio.h>

int main()
{
    int numContainers;
    printf("Number of Containers : ");
    scanf("%d", &numContainers);

    int containerWeights[numContainers];
    int totalWeight = 0;
	printf("\n");
    for (int i = 0; i < numContainers; i++)
	{
        printf("Weight of Container %d: ", i + 1);
        scanf("%d", &containerWeights[i]);
        totalWeight += containerWeights[i];
    }

    int maxCapacity;
    printf("\nMaximum Capacity of the Ship : ");
    scanf("%d", &maxCapacity);

    int trips = 0;
    int currentWeight = 0;

    for (int i = 0; i < numContainers; i++)
	{
        if (currentWeight + containerWeights[i] <= maxCapacity)
            currentWeight += containerWeights[i];
        else
        {
            trips++;
            currentWeight = containerWeights[i];
        }
    }

    if (currentWeight > 0)
        trips++;

    printf("\nNumber of Trips Needed : %d\n", trips);
    return 0;
}