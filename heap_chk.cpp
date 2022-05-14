// heap_chk.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>



int arr[20] = { 12,13,7,15,3,21,4,23 };


void merge(int low, int mid, int high)
{
    int* buff = new int[high - low + 1];
    int i = low;
    int j = mid + 1;
    int k = 0;
    while (i <= mid || j <= high)
    {
        if (j > high)
        {
            buff[k] = arr[i];
            i++;
        }
        else if (i > mid)
        {
            buff[k] = arr[j];
            j++;
        }
        else
        {
            if (arr[i] < arr[j])
            {
                buff[k] = arr[i];
                i++;
            }
            else
            {
                buff[k] = arr[j];
                j++;
            }
        }
        k++;
    }

    for (int i = 0; i < k; i++)
    {
        arr[low + i] = buff[i];
    }
    delete[] buff;
    return;
}

void mergeSort(int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
    }
}



void heapify(int index, int heapsize)
{
    if (index >= heapsize)
    {
        return;
    }
    int max_index = index;
    int lChild = 2 * index + 1;
    int rchild = 2 * index + 2;
    if (lChild < heapsize && arr[lChild] > arr[index])
    {
        max_index = lChild;
    }
    if (rchild < heapsize && arr[rchild] > arr[max_index])
    {
        max_index = rchild;
    }
    if (max_index != index)
    {
        auto temp = arr[index];
        arr[index] = arr[max_index];
        arr[max_index] = temp;
        heapify(max_index, heapsize);
    }
}


void buildHeap(int heapsize)
{
    if (0 == heapsize)
    {
        return;
    }
    for (int i = (heapsize - 1) / 2; i > -1; i--)
    {
        heapify(i, heapsize);
    }
    return;
}

void heapSort(int heapSize)
{
    if (0 == heapSize)
    {
        return;
    }
    for (int i = (heapSize - 1); i > 0; i--)
    {
        auto temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(0, i);
    }
    return;
}


void maintainHeap(int index)
{
    if (index == 0)
    {
        return;
    }
    int parent = (index - 1) / 2;
    if (arr[parent] < arr[index])
    {
        auto temp = arr[parent];
        arr[parent] = arr[index];
        arr[index] = temp;
        maintainHeap(parent);
    }
    return;
}

void heap_insert(int element, int &heapsize)
{
    arr[heapsize] = element;
    maintainHeap(heapsize);
    heapsize++;
}


int main()
{
    /*int heapSize = 8;
    buildHeap(heapSize);
    heap_insert(25, heapSize);
    heapSort(heapSize);*/
    mergeSort(0, sizeof(arr) / sizeof(arr[0]) - 1);
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
