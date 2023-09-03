#include <stdio.h>

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            return i;
    return -1;
}
    
int main()
{
	int size, key, result;
    printf("Array Size : ");
    scanf("%d", &size);

    int arr[size], count = 0;
    printf("\nEnter Elements :\n");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    printf("\nSearch Element : ");
    scanf("%d", &key);
    
    for (int i = 0; i < size; i++)
    {
    	if (arr[i] < key)
    		printf("\nElement %d < Element %d\n", arr[i], key);
            count += 1;
    	if (arr[i] > key)
    		printf("\nElement %d > Element %d\n", arr[i], key);
            count += 1;
    	if (arr[i] == key)
    	{
    		printf("\nElement %d = Element %d\n", arr[i], key);
            count += 1;
    		break;
		}
	}

    printf("\nKey Comparisons Made : %d", count);
	
	result = linearSearch(arr, size, key);
	if (result != -1)
        printf("\nElement Found | Key Element Position : %d\n", result + 1);
	else
        printf("\nElement Not Found\n");
			
    return 0;
}