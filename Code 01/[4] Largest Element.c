#include <stdio.h>

int main()
{
    int array[100], size, i, max;
    printf("Enter the Size of the Array : ");
    scanf("%d",&size);

    printf("Enter %d Elements in the Array :\n", size);
    for (i=0;i<size;i++)
        scanf("%d", &array[i]);

    max = array[0];

    for (i=1;i<size;i++)
	{
        if (array[i] > max)
            max = array[i];
    }

    printf("The Largest Element in the Array : %d\n", max);
    return 0;
}