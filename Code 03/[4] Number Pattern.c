#include<stdio.h>
#include<conio.h>

int main()
{
	int i,j,r;
	printf("Number of Rows : ");
	scanf("%d",&r);
	printf("\n");
	
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=i;j++)
			printf("%d ",j);
		printf("\n");
	}
	return 0;
}