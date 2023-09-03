#include <stdio.h>

void findSubsetSum(int set[], int n, int targetSum, int subset[], int subsetSize, int currentIndex, int currentSum)
{
    if (currentSum > targetSum || currentIndex >= n)
	{
        return;
    }

    if (currentSum == targetSum) {
        printf("Subset With Sum 40 : ");
        for (int i = 0; i < subsetSize; i++)
		{
            printf("%d ", subset[i]);
        }
        printf("\n");
        return;
    }

    subset[subsetSize] = set[currentIndex];
    findSubsetSum(set, n, targetSum, subset, subsetSize + 1, currentIndex + 1, currentSum + set[currentIndex]);
    findSubsetSum(set, n, targetSum, subset, subsetSize, currentIndex + 1, currentSum);
}

int main()
{
    int n;
    printf("Enter Number of Elements : ");
    scanf("%d", &n);

    int set[n];
    printf("Enter Elements :\n");
    for (int i=0;i<n;i++)
	{
		printf("Element %d : ",i+1);
        scanf("%d",&set[i]);
    }

    int subset[n];
    printf("Subsets With Sum 40 :\n");
    findSubsetSum(set,n,11,subset,0,0,0);

    return 0;
}