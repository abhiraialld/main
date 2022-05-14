// chk_map.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<map>


void merge(int arr[], int l, int m, int r)
{
    if (l >= r)
    {
        return;
    }
    int* ptr = new int[r - l + 1];
    int i = l, j = m + 1;
    int k = 0;
    while (i <= m || j <= r)
    {
        if (j > r || (i <= m && arr[i] < arr[j]))
        {
            ptr[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            ptr[k] = arr[j];
            j++;
            k++;
        }
    }
    for (int i = 0; i < k; i++)
    {
        arr[i + l] = ptr[i];
    }
    delete ptr;
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        auto mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}


int partition(int arr[], int l, int r)
{
    int i = l - 1, j = r + 1;
    int pivot = l;
    int pivotV = arr[l];
    while (i < j)
    {
        do
        {
            i++;
        } while (i <= r && arr[i] < pivotV);
        do
        {
            j--;
        } while (j > -1 && arr[j] > pivotV);
        if (i < j)
        {
            if (i == pivot || j == pivot)
            {
                pivot = (i == pivot ? j : i);
            }
            auto temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    if (pivot <= j)
    {
        auto temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;
        pivot = j;
    } 
    else if (pivot >= i)
    {
        auto temp = arr[pivot];
        arr[pivot] = arr[i];
        arr[i] = temp;
        pivot = i;
    }
    return pivot;
}

void quickSort(int arr[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    auto pivot = partition(arr, l, r);
    quickSort(arr, l, pivot - 1);
    quickSort(arr, pivot + 1, r);
}

int main()
{
    std::map<int, int> mmap;
    mmap[1] = 11;
    mmap[2] = 121;
    mmap[13] = 131;
    mmap[5] = 141;
    mmap.insert(std::pair<int, int>(123, 324));

    mmap.erase(13);

    std::cout << "\n Printing map : \n";
    for (auto key : mmap)
    {
        std::cout << " " << key.first << " " << key.second << "\n";
    }

    int arr[] = {9,8,7,6,5,4,3,2 };
    quickSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
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
