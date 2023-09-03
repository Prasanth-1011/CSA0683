#include <stdio.h>

int binomialCoefficient(int n, int k)
{
    int dp[n+1][k+1];

    for (int i = 0; i <= n; i++)
	{
        for (int j = 0; j <= k && j <= i; j++)
		{
            if (j == 0 || j == i)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    return dp[n][k];
}

int main()
{
    int n,k;
    printf("Enter the Value of n : ");
    scanf("%d", &n);
    printf("Enter the Value of k : ");
    scanf("%d", &k);

    if (n<k || k<0 || n<0 )
	{
        printf("Invalid Input");
        return 0;
    }

    int result = binomialCoefficient(n,k);
    printf("\nBinomial Coefficient of C(%d, %d) is %d.\n",n,k,result);
    return 0;
}