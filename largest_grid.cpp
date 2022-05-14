// largest_grid.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int traverse(int mat[][4], int nRow, int nCol, int dp[][4])
{
    if (nRow < 0 || nRow >= 3 || nCol < 0 || nCol > 3)
    {
        return 0;
    }
    if (mat[nRow][nCol] == 0)
    {
        return 0;
    }
    if (dp[nRow][nCol] != -1)
    {
        return dp[nRow][nCol];
    }
    dp[nRow][nCol] = 0;
    int nOneCount = 1;
    nOneCount += traverse(mat, nRow + 1, nCol, dp);
    nOneCount += traverse(mat, nRow - 1, nCol, dp);
    nOneCount += traverse(mat, nRow, nCol - 1, dp);
    nOneCount += traverse(mat, nRow, nCol + 1, dp);
    nOneCount += traverse(mat, nRow + 1, nCol + 1, dp);
    nOneCount += traverse(mat, nRow -1 , nCol + 1, dp);
    nOneCount += traverse(mat, nRow - 1, nCol - 1, dp);
    nOneCount += traverse(mat, nRow + 1, nCol - 1, dp);
    return nOneCount;
}

int main()
{
    int mat[][4] = { {1,1,1,0},
        {0,0,1,1},
        {0,0,1,1}};
    int dp[][4] = { {-1,-1,-1,-1},
        {-1,-1,-1,-1},
        {-1,-1,-1,-1} };

    int nMaxGridLength = 0;;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (0 == mat[i][j])
            {
                dp[i][j] = 0;
                continue;
            }
            if (dp[i][j] == -1)
            {
                auto nTempGridLength = traverse(mat, i, j, dp);
                if (nTempGridLength > nMaxGridLength)
                {
                    nMaxGridLength = nTempGridLength;
                }
            }
        }
    }
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
