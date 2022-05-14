// Max_heap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int a[] = { 33,21,4,65,15,31,28,92 };
int heapsize = sizeof(a) / sizeof(a[0]) - 1;


void heapify(int index)
{
    int left_child = 2 * index + 1;
    int right_index = 2 * index + 2;
    int max_index = -1, max = a[index];
    if (right_index <= heapsize && a[right_index] > a[index])
    {
        max_index = right_index;
        max = a[right_index];
    }
    if (left_child <= heapsize && a[left_child] > max)
    {
        max_index = left_child;
        max = a[left_child];
    }

    if (-1 != max_index)
    {
        auto temp = a[index];
        a[index] = a[max_index];
        a[max_index] = temp;
        heapify(max_index);
    }

}

void heap_sort()
{
    for (int i = heapsize; i >= 0 ; i--)
    {
        auto temp = a[heapsize];
        a[heapsize] = a[0];
        a[0] = temp;
        heapsize--;
        heapify(0);
    }
}


void build_max_heap()
{
    for (int i = heapsize / 2; i >= 0; i--)
    {
        heapify(i);
    }
}

int main()
{
    std::cout << "Hello World!\n";
    build_max_heap();
    heap_sort();
    std::cout << "\nabc";
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
