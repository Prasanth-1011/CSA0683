#include <stdio.h>
#include <stdlib.h>

struct Item
{
    int weight;
    int value;
};

int compareItems(const void* a, const void* b)
{
    struct Item* item1 = (struct Item*)a;
    struct Item* item2 = (struct Item*)b;
    double valuePerWeight1 = (double)item1->value / item1->weight;
    double valuePerWeight2 = (double)item2->value / item2->weight;

    if (valuePerWeight1 > valuePerWeight2)
        return -1;
    else if (valuePerWeight1 < valuePerWeight2)
        return 1;
    return 0;
}

double knapsackGreedy(int capacity, struct Item items[], int n)
{
    qsort(items, n, sizeof(struct Item), compareItems);
    int currentWeight = 0;
    double finalValue = 0.0;

    for (int i = 0; i < n; i++)
	{
        if (currentWeight + items[i].weight <= capacity)
		{
            currentWeight += items[i].weight;
            finalValue += items[i].value;
        }
		else
		{
            int remainingCapacity = capacity - currentWeight;
            finalValue += items[i].value * ((double)remainingCapacity / items[i].weight);
            break;
        }
    }
    return finalValue;
}

int main()
{
    int capacity;
    printf("Capacity of Knapsack : ");
    scanf("%d",&capacity);

    int n;
    printf("Number of Items : ");
    scanf("%d",&n);

    struct Item *items = (struct Item*)malloc(n * sizeof(struct Item));

    printf("\nEnter Weight And Value For Each Item :\n");
    for (int i = 0; i < n; i++)
	{
        printf("Item %d: ",i+1);
        scanf("%d %d",&items[i].weight,&items[i].value);
    }

    double result = knapsackGreedy(capacity,items,n);
    printf("\nMaximum Value Obtained : %.2f\n", result);
    free(items);
    return 0;
}