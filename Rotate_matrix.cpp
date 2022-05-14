// Rotate_matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int arr[][4] = { {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,16} };

void rotate_layer(int l, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        auto temp = arr[l + i][l];
        arr[l + i][l] = arr[l][l + size - i - 1];
        arr[l][l + size - i - 1] = arr[l + size - i - 1][l + size - 1];
        arr[l + size - i - 1][l + size - 1] = arr[l + size - 1][l + i];
        arr[l + size - 1][l + i] = temp;
    }
}

void rotate_matrix()
{
    for (int i = 0, mSize = 4; mSize > 1; mSize -= 2, i++)
    {
        rotate_layer(i, mSize);
    }
}

int main()
{
    rotate_matrix();
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
