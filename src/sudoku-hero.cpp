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

