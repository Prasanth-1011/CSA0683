#include <stdio.h>
#include <stdbool.h>

bool isSafe(int board[][100], int n, int row, int col)
{
    int i, j;

    for (i = 0; i < col; i++)
	{
        if (board[row][i])
            return false;
    }

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
	{
        if (board[i][j])
            return false;
    }

    for (i = row, j = col; j >= 0 && i < n; i++, j--)
	{
        if (board[i][j])
            return false;
    }
    return true;
}

void printSolution(int board[][100], int n)
{
    for (int i = 0; i < n; i++)
	{
        for (int j = 0; j < n; j++)
            if (board[i][j] == 1)
                printf("Q ");
            else
                printf("%d ", board[i][j]);
        printf("\n");
    }
}

int solveNQueensUtil(int board[][100], int n, int col)
{
    if (col >= n) {
        printSolution(board, n);
        printf("\n");
        return 1;
    }

    int total_solutions = 0;

    for (int i = 0; i < n; i++)
	{
        if (isSafe(board, n, i, col))
		{
            board[i][col] = 1;
            total_solutions += solveNQueensUtil(board, n, col + 1);
            board[i][col] = 0;
        }
    }
    return total_solutions;
}

bool solveNQueens(int n)
{
    int board[100][100] = {0};
    int total_solutions = solveNQueensUtil(board, n, 0);

    if (total_solutions == 0)
	{
        printf("Solution Does Not Exist For %dx%d Board\n", n, n);
        return false;
    } else
        printf("Total Solutions : %d\n", total_solutions);

    return true;
}

int main()
{
    int n;
    printf("Board Size : ");
    scanf("%d", &n);
    printf("\n");
    solveNQueens(n);
    return 0;
}