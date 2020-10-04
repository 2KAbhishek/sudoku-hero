#include <iostream>
#define N 9
using namespace std;

int grid[N][N];

// Check whether num is present in col or not
bool isPresentInCol(int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}

// Check whether num is present in row or not
bool isPresentInRow(int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}

// Check whether num is present in 3x3 box or not
bool isPresentInBox(int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + boxStartRow][col + boxStartCol] == num)
                return true;
    return false;
}

// Get the sudoku grid from user input
void inputGrid()
{
    cout << "Enter the sudoku puzzle, 0 for empty space" << endl;
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            cin >> grid[row][col];
        }
    }
}

