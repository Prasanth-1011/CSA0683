#include <stdio.h>

void findMinMax(int arr[], int low, int high, int* min, int* max)
{
    if (low == high)
	{
        *min = *max = arr[low];
        return;
    }

    if (high - low == 1) {
        if (arr[low] < arr[high])
		{
            *min = arr[low];
            *max = arr[high];
        } else {
            *min = arr[high];
            *max = arr[low];
        }
        return;
    }

    int mid = (low + high) / 2;
    int left_min, left_max, right_min, right_max;

    findMinMax(arr, low, mid, &left_min, &left_max);
    findMinMax(arr, mid + 1, high, &right_min, &right_max);

    *min = (left_min < right_min) ? left_min : right_min;
    *max = (left_max > right_max) ? left_max : right_max;
}

int main()
{
    int i,n;
    printf("Enter Number of Elements : ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter Elements :\n");
    for (i=0;i<n;i++)
        scanf("%d", &arr[i]);

    int min, max;
    findMinMax(arr,0,n-1,&min,&max);

    printf("\nMinimum Element : %d\n", min);
    printf("Maximum Element : %d\n", max);
    return 0;
}