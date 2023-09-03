#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a[10][10], b[10][10], c[10][10], i, j, k, row, col;
    printf("Give the Values Compatible For Matrix Multiplication\n");

    printf("\nEnter the Number of Rows : ");
    scanf("%d", &row);
    printf("\nEnter the Number of Columns : ");
    scanf("%d", &col);

    printf("\nEnter the Values For Elements in Matrix 1\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter the Values For Elements in Matrix 2\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < col; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("\nMatrix Multiplication :\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}