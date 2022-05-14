// max_profit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int a[] = {43,2,5,37,1,23,0};
    int maxima = -1, max_profit = -1;
    for (int i = sizeof(a)/sizeof(a[0]) - 1; i > -1; i--)
    {
        if (a[i] > maxima)
        {
            maxima = a[i];
        }
        else
        {
            if (maxima - a[i] > max_profit)
            {
                max_profit = maxima - a[i];
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
