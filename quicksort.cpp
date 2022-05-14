// quicksort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int a[] = { 5,2,3,43,11,67,87,12,14,3,1,0,65,13 };

int partition(int beg, int end)
{
    int i = beg;
    int j = end + 1;
    int pivot_ind = beg;
    while (i < j)
    {
        do
        {
            i++;
        } while (i <= end && a[i] < a[pivot_ind]);

        do
        {
            j--;
        } while (j > -1 && a[j] > a[pivot_ind]);

        if (i < j)
        {
            auto temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    auto temp = a[pivot_ind];
    a[pivot_ind] = a[j];
    a[j] = temp;
    return j;
}

void quicksort(int beg, int end)
{
    if (beg < end)
    {
        auto pivot = partition(beg, end);
        quicksort(beg, pivot - 1);
        quicksort(pivot + 1, end);
    }
}

int main()
{
    std::cout << "Hello World!\n";
    quicksort(0, sizeof(a) / sizeof(a[0]) - 1);
    int ch;
    std::cin >> ch;
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
