#include<stdio.h>

int main()
{
	int num;
    printf("Enter Number : ");
    scanf("%d", &num);
    
    printf("\nFactors :\n");
    for (int i=1; i <= num; i++)
        if (num % i == 0)
        {
        	printf("%d\n",i);
		}
}