// vdostitching.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int canStitch(vector<pair<int, int>>& arr, int time)
{
    std::sort(arr.begin(), arr.end(), compare);
    int prevHighest = 0;
    int highest = 0;
    int count = 0;
    for (int i = 0; i < arr.size();)
    {
        while (i < arr.size() && arr[i].first <= prevHighest)
        {
            if (arr[i].second > highest)
            {
                highest = arr[i].second;
            }
            i++;
        }
        count++;
        if (i < arr.size() && arr[i].first > highest)
        {
            return -1;
        }
        prevHighest = highest;
    }
    if (highest == time)
    {
        return count;
    }
    else
    {
        return -1;
    }
}

int main()
{
    pair<int, int> a = { 1,2 };
    vector<pair<int,int>> arr = { {0,1},{6,8},{0,2},{5,6},{0,4},{0,3},{6,7},{1,3},{4,7},{1,4},{2,5},{2,6},{3,4},{4,5},{5,7},{6,9} };
    auto ret = canStitch(arr, 9);
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
