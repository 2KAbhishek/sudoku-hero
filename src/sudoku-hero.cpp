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

// Display the sudoku grid
void showGrid()
{
    cout << "-------------------------" << endl;
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            if (col == 0 || col == 3 || col == 6)
                cout << "| ";
            cout << grid[row][col] << " ";
        }
        cout << "| ";

        if (row == 2 || row == 5)
        {
            cout << endl;
            cout << "-------------------------";
        }
        cout << endl;
    }
    cout << "-------------------------" << endl;
}

// Find empty location and update row and column
bool findEmptyCell(int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == 0) //marked with 0 is empty
                return true;
    return false;
}

// True if item not found in col, row and current 3x3 box
bool isValidCell(int row, int col, int num)
{
    return !isPresentInRow(row, num) && !isPresentInCol(col, num) && !isPresentInBox(row - row % 3, col - col % 3, num);
}

// Solves puzzle recursively
bool solveSudoku()
{
    int row, col;
    // True when all cells are filled
    if (!findEmptyCell(row, col))
        return true;
    for (int num = 1; num < 10; num++)
    {
        if (isValidCell(row, col, num))
        {
            grid[row][col] = num;
            // Recursively check other cells in grid
            if (solveSudoku())
                return true;
            // Backtrack if invalid solution
            grid[row][col] = 0;
        }
    }
    return false;
}

int main()
{
    inputGrid();
    cout << "Entered puzzle :" << endl;
    showGrid();
    if (solveSudoku() == true)
    {
        cout << "Solved puzzle :" << endl;
        showGrid();
    }
    else
        cout << "No solution exists";
}

