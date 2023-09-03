#include <stdio.h>

int Prime(int num)
{
    if (num <= 1)
        return 0;
        
    for (int i=2;i*i<=num;i++)
	{
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int limit;
    printf("Enter Limit : ");
    scanf("%d", &limit);

    printf("Prime Numbers Till %d :\n", limit);
    for (int i=2;i<=limit;i++)
	{
        if (Prime(i))
            printf("%d ", i);
    }
    printf("\n");

    return 0;
}