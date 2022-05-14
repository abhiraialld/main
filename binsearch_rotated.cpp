// binsearch_rotated.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int arr[] = { 6,7,8,9,10,11,12,13,14,1,2,3,4,5 };
int binary_search(int l, int r, int data)
{
    if (l <= r)
    {
        auto mid = (r - l) / 2 + l;
        if (arr[mid] == data)
        {
            return mid;
        }
        else if (l == r)
        {
            return -1;
        }
        else if (arr[l] < arr[mid])
        {
            if (arr[l] <= data && arr[mid] > data)
            {
                return binary_search(l, mid - 1, data);
            }
            else
            {
                return binary_search(mid + 1, r, data);
            }
        }
        else
        {
            if (arr[mid ] < data && arr[r] >= data)
            {
                return binary_search(mid + 1, r, data);
            }
            else
            {
                return binary_search(l, mid - 1, data);
            }
        }
    }
    return -1;
}

int main()
{
    binary_search(0, 13, 7);
    for (int i = 0; i < 14; i++)
    {
        auto index = binary_search(0, 13, arr[i]);
        std::cout << std::endl << arr[i] <<"  "<<index;
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
