// practheap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<queue>
using namespace std;

int largestSet(std::vector<int>& arr, int limit)
{
    priority_queue<int, vector<int>, greater<int>> primary, set;
    for (auto item : arr)
    {
        primary.push(item);
    }
    int maxSize = 0;
    while (!primary.empty())
    {
        if (set.empty())
        {
            set.push(primary.top());
        }
        else
        {
            while (!set.empty() && primary.top() - set.top() > limit)
            {
                set.pop();
            }
            set.push(primary.top());
        }
        if (set.size() > maxSize)
        {
            maxSize = set.size();
        }
        primary.pop();
    }
    return maxSize;
}

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second)
    {
        return a.second > b.second;
    }
    return a.first > b.first;
}

bool divisionPossible(vector<int>& arr)
{
    std::priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&compare)> pq(compare);
    pair<int, int> a;
    a.first = 1;
    a.second = arr[0];
    pq.push(a);
    int set_count = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        auto p = pq.top();
        while (!pq.empty() && pq.top().second + 1 < arr[i])
        {
            p = pq.top();
            pq.pop();
            if (p.first < 3)
            {
                return false;
            }
            set_count++;
        }
        if (!pq.empty() && pq.top().second + 1 == arr[i])
        {
            p = pq.top();
            p.first++;
            pq.pop();
        }
        else
        {
            p.first = 1;
        }
        p.second = arr[i];
        pq.push(p);
    }
    if (set_count == 0 && pq.size() == 1)
    {
        auto p = pq.top();
        if (p.first >= 6)
        {
            return true;
        }
        return false;
    }
    else
    {
        while (!pq.empty())
        {
            auto p = pq.top();
            pq.pop();
            if (p.first < 3)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    vector<int> arr = { 1,2,3,3,4,4,5,5 };
    auto len = divisionPossible(arr);
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
