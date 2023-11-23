#include <iostream>
#include <cmath>

using namespace std;

#define MAX_N 32

void printSolution(int board[MAX_N][MAX_N], int N)
{
    static int solutionCount = 1;

    cout << "Solution " << solutionCount++ << ":\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << (board[i][j] ? "Q " : ". ");
        cout << endl;
    }

    cout << endl;
}

bool isSafe(int board[MAX_N][MAX_N], int row, int col, int N)
{
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(int board[MAX_N][MAX_N], int col, int N)
{
    if (col == N)
    {
        printSolution(board, N);
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col, N))
        {
            board[i][col] = 1;
            res = solveNQUtil(board, col + 1, N) || res;
            board[i][col] = 0;
        }
    }
    return res;
}

bool solveNQueens(int N)
{
    int board[MAX_N][MAX_N] = {0};
    if (!solveNQUtil(board, 0, N))
    {
        cout << "Solution does not exist" << endl;
        return false;
    }
    return true;
}

int main()
{
    int N;

    cout << "Enter the number of queens (N): ";
    cin >> N;

    solveNQueens(N);

    return 0;
}
