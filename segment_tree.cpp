// segment_tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>

using namespace std;


vector<int> st;

int construct_st(vector<int>& arr, int i, int j, int pos)
{
    if (i == j)
    {
        st[pos] = arr[i];
        return st[pos];
    }
    auto mid = i + (j - i) / 2;
    st[pos] = construct_st(arr, i, mid, 2 * pos + 1) +
        construct_st(arr, mid + 1, j, 2 * pos + 2);
    return st[pos];
}

void update(vector<int>& arr, int i, int j, int spos, int pos, int diff)
{
    if (i == j && i == pos)
    {
        st[spos] += diff;
        return;
    }
    if (pos < i || pos > j)
        return;
    st[spos] += diff;
    auto mid = i + (j - i) / 2;
    if (i != j)
    {
        update(arr, i, mid, 2 * spos + 1, pos, diff);
        update(arr, mid + 1, j, 2 * spos + 2, pos, diff);
    }
    else
    {
        cout << "\nPossible";
    }

}


int range_query(vector<int>& arr, int si, int sj, int i, int j, int pos)
{
    if (i <= si && j >= sj)
    {
        return st[pos];
    }
    if ((si < i && sj < i) || (si > j && sj > j))
    {
        return 0;
    }
    auto mid = si + (sj - si) / 2;
    auto sum = range_query(arr, si, mid, i, j, 2 * pos + 1) + 
        range_query(arr, mid + 1, sj, i, j, 2 * pos + 2);
    
    return sum;
}


int main()
{
    vector<int> arr = {1,5,6,5,2,-3,4,-7};
    st.assign(15, 0);
    construct_st(arr, 0, 7, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        update(arr, 0, 7, 0, i, 1);
    }

    auto sum = range_query(arr, 0, 7, 1, 4, 0);
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
