// K_CLOSEST_NUMBERS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>


int abs_difference(int a, int b)
{
    int sum = a - b;
    sum *= (sum < 0) ? -1 : 1;
    return sum;
}

void print_k(std::vector<int>& vt, int x, int k)
{
    int i = 0;
    int j = 0;
    int* a = new int[k];
    int abs_diff_x = 0;;
    for (i = 0; i < vt.size() && j < k; i++)
    {
        if (vt[i] == x)
            continue;
        int abs_diff = vt[i] - x;
        abs_diff *= (abs_diff < 0) ? -1 : 1;
        abs_diff_x += abs_diff;
        a[j++] = i;
    }
    if (j < k)
    {
        std::cout << "\n k element not present";
        return;
    }
    int start_pos = 0; j = 0;
    int min_abs_difference = abs_diff_x;
    for (; i < vt.size(); i++)
    {
        if (vt[i] == x)
        {
            continue;
        }
        abs_diff_x -= abs_difference(vt[a[j]], x);
        abs_diff_x += abs_difference(vt[i], x);
        if (abs_diff_x < min_abs_difference)
        {
            min_abs_difference = abs_diff_x;
            start_pos = a[(j + 1) % k];
        }
        a[j] = i;
        j = (j + 1) % k;
    }

    for (i = start_pos, j = 0; j < k; i++)
    {
        if (vt[i] == x)
            continue;
        std::cout << "\n" << vt[i];
        j++;
    }
}

int main()
{
    std::vector<int> vt = { 12,16,22,30,35,39,42,45,48,50,53,55,56 };
    print_k(vt, 48, 4);
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
