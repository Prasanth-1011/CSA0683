#include <stdio.h>

#define MAX_ELEMENTS 100

int set[MAX_ELEMENTS];
int subset[MAX_ELEMENTS];
int n, sum, total_sum = 0;

void backtrack(int current_index, int current_sum)
{
    if (current_sum == sum)
	{
        printf("Subset With Sum %d : ", sum);
        for (int i = 0; i < current_index; i++)
            printf("%d ", subset[i]);
        printf("\n");
    }

    for (int i = current_index; i < n; i++)
	{
        if (current_sum + set[i] <= sum)
		{
            subset[current_index] = set[i];
            backtrack(current_index + 1, current_sum + set[i]);
        }
    }
}

int main()
{
    printf("Number of Elements : ");
    scanf("%d", &n);

    printf("\nEnter Elements :\n");
    for (int i = 0; i < n; i++)
	{
        scanf("%d", &set[i]);
        total_sum += set[i];
    }

    printf("\nEnter Desired Sum of Subsets : ");
    scanf("%d", &sum);

    if (total_sum < sum)
	{
        printf("\nThe Sum of Subsets Cannot Be Achieved.\n");
        return 0;
    }

    backtrack(0, 0);
    return 0;
}