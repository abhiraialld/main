// Rod_cutting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


int find_max_profit(int arr[], int length)
{
    if (0 == length)
    {
        return 0;
    }

    int max_profit = arr[length - 1];
    for (int i = 0; i < length - 1; i++)
    {
        auto temp_profit = arr[i] + find_max_profit(arr, length - i - 1);
        if (temp_profit > max_profit)
        {
            max_profit = temp_profit;
        }
    }
    return max_profit;
}

int main()
{
    int arr[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
    auto max_profit = find_max_profit(arr, sizeof(arr) / sizeof(arr[0]));
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
