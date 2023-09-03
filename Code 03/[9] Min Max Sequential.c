#include <stdio.h>

void findMinMaxSequence(int arr[], int size)
{
    int start = 0, end = 0;    
    while (end < size)
	{
        while (end < size - 1 && arr[end] <= arr[end + 1])
            end++;

        int min = arr[start];
        int max = arr[end];
        printf("Sequence [%d,%d]: Minimum = %d, Maximum = %d\n", start + 1, end + 1, min, max);

        end++;
        start = end;
    }
}

int main()
{
    int i,arr[50],size,max,min;
    printf("Total Number of Elements : ");
    scanf("%d",&size);
    printf("\nEnter Elements : \n");
	for(i=0;i<size;i++)
	{
		printf("Elements %d : ",i+1);
		scanf("%d",&arr[i]);
	}
	
	min = max = arr[0];
	for(i=1;i<size;i++)
	{        
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    printf("\nMinimum Value : %d", min);
    printf("\nMaximum Value : %d\n", max);
	printf("\n");
    findMinMaxSequence(arr,size);

    return 0;
}