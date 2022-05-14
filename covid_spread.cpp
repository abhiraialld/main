// covid_spread.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void spread(int arr[][5], int i, int j, int R, int C, int days, int brr[][5])
{
    if (i < 0 || i >= R || j < 0 || j >= C)
    {
        return;
    }
    if (arr[i][j] == 0 || arr[i][j] == 2)
    {
        return;
    }
    if (brr[i][j] == -1)
    {
        brr[i][j] = days;
    }
    else if (days < brr[i][j])
    {
        brr[i][j] = days;
    }
    else
    {
        return;
    }
    spread(arr, i - 1, j, R, C,days + 1, brr);
    spread(arr, i + 1, j, R, C, days + 1, brr);
    spread(arr, i, j - 1, R, C, days + 1, brr);
    spread(arr, i, j + 1, R, C, days + 1, brr);
}

int main()
{
    int arr[][5] = { {2,0,1,2,1},
        {0,0,1,2,1},
        {1,0,0,2,1} };
    int brr[][5] = { {-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1} };
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arr[i][j] == 2)
            {
                spread(arr, i - 1, j, 3, 5, 1, brr);
                spread(arr, i + 1, j, 3, 5, 1, brr);
                spread(arr, i, j - 1, 3, 5, 1, brr);
                spread(arr, i, j + 1, 3, 5, 1, brr);
            }
        }
    }
    int min_days = std::numeric_limits<int> ::min();
    bool bAllInfected = true;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arr[i][j] == 1 && brr[i][j] == -1)
            {
                bAllInfected = false;
                break;
            }
            if (brr[i][j] != -1 && arr[i][j] == 1 && brr[i][j] > min_days)
            {
                min_days = brr[i][j];
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
