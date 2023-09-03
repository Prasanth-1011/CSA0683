#include<stdio.h>
int Greatest_Common_Divisor(int a,int b)
{
	while(b!=0)
	{
		int temp = b;
		b = a%b;
		a = temp;
	}
	return a;
}
int main()
{
	int a,b;
	printf("Enter Two Numbers : ");
	scanf("%d %d",&a,&b);
	int result = Greatest_Common_Divisor(a,b);
	printf("Greatest Common Divisor For %d and %d is %d",a,b,result);
	return 0;
}