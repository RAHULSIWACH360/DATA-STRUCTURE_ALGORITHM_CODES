#include <stdio.h>

#define N 4

void printSolution(int solution, int queens[])
{
    printf("%d\n", solution);
    for (int i = 0; i < N; i++)
    {
        printf("%d ", queens[i]);
    }
    printf("\n");
}

int isSafe(int queens[], int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        if (queens[i] == row ||
            queens[i] - i == row - col ||
            queens[i] + i == row + col)
        {
            return 0;
        }
    }
    return 1;
}

void solveNQueens(int queens[], int col, int *solution)
{
    if (col == N)
    {
        printSolution(*solution, queens);
        (*solution)++;
        return;
    }
    for (int row = 1; row <= N; row++)
    {
        if (isSafe(queens, row, col))
        {
            queens[col] = row;
            solveNQueens(queens, col + 1, solution);
        }
    }
}

int main()
{
    int queens[N] = {0};
    int solution = 1;
    solveNQueens(queens, 0, &solution);
    printf("COUNT=%d\n", solution - 1);
    return 0;
}