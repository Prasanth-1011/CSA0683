#include <stdio.h>
#include<math.h>

int main()
{
    int num,reversed = 0;
    printf("Enter Number : ");
    scanf("%d",&num);
    
    while (num != 0)
	{
        reversed = reversed * 10 + num % 10;
        num = floor(num / 10);
    }
    printf("Reversed Output : %d\n", reversed);
    return 0;
}