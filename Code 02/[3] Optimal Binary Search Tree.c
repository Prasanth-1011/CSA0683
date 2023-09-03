#include <stdio.h>
#include <limits.h>

#define MAX_KEYS 10

void optimalBST(int keys[], int freq[], int n) {
    int cost[MAX_KEYS + 1][MAX_KEYS + 1];
    int root[MAX_KEYS + 1][MAX_KEYS + 1];

    for (int i = 1; i <= n; i++)
	{
        cost[i][i] = freq[i];
        root[i][i] = i;
    }

    for (int L = 2; L <= n; L++)
	{
        for (int i = 1; i <= n - L + 1; i++)
		{
            int j = i + L - 1;
            cost[i][j] = INT_MAX;

            int sum = 0;
            for (int k = i; k <= j; k++)
                sum += freq[k];

            for (int r = i; r <= j; r++)
			{
                int c = ((r > i) ? cost[i][r - 1] : 0) + ((r < j) ? cost[r + 1][j] : 0) + sum;
                if (c < cost[i][j])
				{
                    cost[i][j] = c;
                    root[i][j] = r;
                }
            }
        }
    }
    printf("\nOptimal Cost : %d\n", cost[1][n]);
}

int main()
{
    int keys[MAX_KEYS], freq[MAX_KEYS], n;

    printf("Enter Number of Keys (Limits : %d): ", MAX_KEYS);
    scanf("%d", &n);

    printf("Enter Keys :\n");
    for (int i = 1; i <= n; i++)
        scanf("%d", &keys[i]);

    printf("Enter Frequencies :\n");
    for (int i = 1; i <= n; i++)
        scanf("%d", &freq[i]);

    optimalBST(keys, freq, n);
    return 0;
}