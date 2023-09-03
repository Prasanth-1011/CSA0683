#include <stdio.h>

#define MAX_SIZE 100

int main()
{
    int list[MAX_SIZE];
    int size, position, newValue;

    printf("List Size : ");
    scanf("%d",&size);

    printf("\nEnter %d Elements :\n", size);
    for (int i = 0; i < size; i++)
    {
    	printf("Elements %d : ", i+1);
    	scanf("%d", &list[i]);
	}

    printf("\nIndex Starts From 0\nMention - Index Where You Want To Insert a New Value : ");
    scanf("%d", &position);

    printf("\nNew Value to Insert: ");
    scanf("%d", &newValue);

    for (int i = size - 1; i >= position; i--)
        list[i + 1] = list[i];

    list[position] = newValue;
	size++;

    printf("Updated List :\n");
    for (int i = 0; i < size; i++)
        printf("%d ", list[i]);

    return 0;
}