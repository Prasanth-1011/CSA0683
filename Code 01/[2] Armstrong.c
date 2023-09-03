#include <stdio.h>
#include <math.h>

int main()
{
    int num;
    printf("Enter a Number : ");
    scanf("%d", &num);
    
    int temp, remainder, sum = 0, n = 0;

    temp = num;
    while (temp != 0)
	{
        temp = floor(temp/10);
        n += 1;
    }
    temp = num;
    while (temp != 0)
	{
        remainder = temp % 10;
        sum += pow(remainder, n);
        temp = floor(temp/10);
    }
    if(sum == num)
        printf("%d is an Armstrong Number.\n", num);
    else
        printf("%d is not an Armstrong Number.\n", num);
    return 0;
}