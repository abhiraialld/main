// multithreaded_quick_sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<algorithm>
#include<chrono>
#include<future>






int partition(int arr[], int i , int j)
{
    if (j == 1) return 0;
    int left =i -1, right = j + 1;
    int pivot = arr[i], ind_pivot = i;;
    while (left < right)
    {
        do
        {
            left++;
        } while (left <= j && arr[left] < pivot);
        do
        {
            right--;

        } while (right > i-1 && arr[right] > pivot);
        if (left < right)
        {
            auto temp = arr[right];
            arr[right] = arr[left];
            arr[left] = temp;
            if (left == ind_pivot)
            {
                ind_pivot = right;
            }
        }
    }
    if (ind_pivot > right + 1)
    {
        auto temp = arr[right + 1];
        arr[right + 1] = arr[ind_pivot];
        arr[ind_pivot] = temp;
    }
    return right + 1;
}

void quick_sort(int arr[],  int i, int j)
{
    if (i < j)
    {
        auto pivot = partition(arr, i, j);
        /*auto fut = std::async(std::launch::async,*/ quick_sort( arr, i , pivot - 1);
        quick_sort(arr, pivot + 1, j);
        //fut.get();
    }

}

int main()
{
    int arr[] = { 11,32,2,43,1,7,5,46,76,23 };
    auto stime = std::chrono::system_clock::now();
    quick_sort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
    auto diff = std::chrono::system_clock::now() - stime;
    return 0;

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
