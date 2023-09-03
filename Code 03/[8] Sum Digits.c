#include<stdio.h>
#include<math.h>

int main()
{
	int i,n,num,rem,sum = 0;
	printf("Enter Number : ");
	scanf("%d",&n);
	num = n;
	
	while(n!=0)
	{
		rem = n % 10;
		sum = sum + rem;
		n = floor(n/10);
	}
	printf("Sum of Digits For %d is %d",num,sum);
	return 0;
}