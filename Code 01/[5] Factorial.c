#include<stdio.h>
int main()
{
	int fact = 1;
	int i,n;
	printf("Enter Positive Integer : ");
	scanf("%d",&n);
	
	if(n < 0)
	   printf("Factorial is Not Defined For Negative Integers");
	else if(n == 0 || n == 1)
	   printf("Factorial of %d is 1",n);
	else
	   	for(i=1;i<=n;i++)
	{
		fact = fact * i;
	}
	printf("Factorial of %d is %d",n,fact);
}