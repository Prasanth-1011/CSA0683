#include <stdio.h>

int main()
{
    int num,sum = 0;
    printf("Enter Number : ");
    scanf("%d",&num);
    printf("\n");
    
    printf("Factors : ");
    for (int i=1; i <= num / 2; i++)
        if (num % i == 0)
        {
        	printf("%d ",i);
            sum = sum + i;
		}
	
    if(sum == num)
        printf("\nTherefore %d is a Perfect Number\n",num);
    else
        printf("\nThus %d is Not a Perfect Number\n",num);
    return 0;
}