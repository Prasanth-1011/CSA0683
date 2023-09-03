#include <stdio.h>

int binarySearch(int arr[],int size,int target)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
	{
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main()
{
    int a[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72};
    int size = sizeof(a) / sizeof(a[0]);
    int target = 23;

    int result = binarySearch(a,size,target);
    printf("Target Element : %d\n",target);
    
    if (result != -1)
        printf("Element Found at Index %d\n", result);
    else
        printf("Element Not Found\n");

    return 0;
}
