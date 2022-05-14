// search_sqpped_sorted.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>

int binary_search(std::vector<int>& a, int n)
{
    int nSize = a.size();
    int i = 0, j = nSize - 1;
    while (i <= j)
    {
        int mid = i + (j - i) / 2;
        if (a[mid] == n)
        {
            return mid;
        }
        else if (a[mid] < n)
        {
            if (mid - 1 > -1 && a[mid - 1] == n)
                return mid - 1;
            else if (mid + 1 < nSize && a[mid + 1] == n)
                return mid + 1;
            else
                i = mid + 1;
                
        }
        else
        {
            if (mid + 1 < nSize && a[mid + 1] == n)
                return mid + 1;
            else if (mid - 1 > -1 && a[mid - 1] == n)
                return mid - 1;
            else
                j = mid - 1;
        }
    }
    return -1;
}

int main()
{
    std::vector<int> a = {10,2,40,20,50,80,70};
    int index = binary_search(a, 70);
    index = binary_search(a, 70);
    index = binary_search(a, 2);
    index = binary_search(a, 50);
    index = binary_search(a, 10);
    index = binary_search(a, 80);
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
