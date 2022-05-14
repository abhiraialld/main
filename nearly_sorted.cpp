// nearly_sorted.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<queue>

int arr[] = { 10, 9, 8, 7, 4, 70, 60, 50 };

void sortArray(int k, int n)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
    int i = 0;
    for (i = 0; i <= k && i < n; i++)
    {
        heap.push(arr[i]);
    }

    while (!heap.empty())
    {
        auto temp = heap.top();
        arr[i - k - 1] = heap.top();
        heap.pop();
        if (i < n)
        {
            heap.push(arr[i]);
        }
        i++;
    }
}

int mat[][4] = { {1, 2, 3, 4},
{5, 6, 10, 12},
{6, 7, 9, 11},
{13, 14, 15, 16} };

class number
{
public : 
    int value;
    int nBuffer;
    number(int val, int buff)
    {
        value = val;
        nBuffer = buff;
    }
    bool operator>(const number& obj) const
    {
        return value > obj.value;
    }
};
void mergekSortedArray(int k, std::vector<int>& vec)
{
    std::priority_queue<number, std::vector<number>, std::greater<number>> heap;
    int* ptr = new int[k];
    for (int i = 0; i < k; i++)
    {
        ptr[i] = 0;
        heap.push(number(mat[i][0], i));
    }
    while (!heap.empty())
    {
        auto min = heap.top();
        heap.pop();
        vec.push_back(min.value);
        if (ptr[min.nBuffer] < k - 1)
        {
            ptr[min.nBuffer]++;
            heap.push(number(mat[min.nBuffer][ptr[min.nBuffer]], min.nBuffer));
        }
    }
}

int main()
{
    sortArray(4, sizeof(arr) / sizeof(arr[0]));
    std::vector<int> mergedVector;
    mergekSortedArray(4, mergedVector);
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
