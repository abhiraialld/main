// sliding_window.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int min(vector<int>& arr, int k)
{
    int i = 0, s_i = 0;
    int sum_yet = 0;
    int minLen = std::numeric_limits<int>::max();
    for (; i < arr.size(); i++)
    {
        sum_yet += arr[i];
        if (sum_yet < 0)
        {
            s_i = i + 1;
            sum_yet = 0;
        }
        else if (sum_yet > k)
        {
            while (sum_yet > k && s_i <= i)
            {
                minLen = (i - s_i + 1) < minLen ? (i - s_i + 1) : minLen;
                sum_yet -= arr[s_i];
                s_i++;
            }
        }
    }
    return (minLen == std::numeric_limits<int>::max()) ? -1 : minLen;
}




bool calc(vector<int>& arr, int beg, int end, vector<int>& res)
{
    //std::cout << "\nfun(" << beg << "," << end << ")";
    if (beg == end)
    {
        res.push_back(arr[beg]);
        return false;
    }
    for (int i = beg; i < end; i++)
    {
        vector<int> a, b;
        calc(arr, beg, i, a);
        calc(arr, i + 1, end, b);
        for (auto p1 : a)
        {
            for (auto p2 : b)
            {
                res.push_back(p1 + p2);
                res.push_back(p1 - p2);
                res.push_back(p1 * p2);
                if (p2 != 0)
                {
                    (res.push_back(p1 / p2));
                }
            }
        }
    }
    if (beg == 0 && (end == arr.size() - 1))
    {
        return (find(res.begin(), res.end(), 24) != res.end());
    }
    return false;
}


void allperm(vector<int>& arr, int beg)
{
    if (beg == arr.size())
    {
        vector<int> res;
        auto let = calc(arr, 0, arr.size() - 1, res);
        for (int i = 0; i < res.size(); i++)
        {
            cout << "\n" << res[i];
        }
        return;
    }
    for (int i = beg; i < arr.size(); i++)
    {
        auto temp = arr[beg];
        arr[beg] = arr[i];
        arr[i] = temp;
        allperm(arr, beg + 1);
         temp = arr[beg];
        arr[beg] = arr[i];
        arr[i] = temp;
    }
}




int minMax(vector<int>& arr, int i, int m)
{
    std::cout << "\nfun(" << i << "," << m << ")";
    if (i == arr.size())
    {
        return 0;
    }
    if (m == 1)
    {
        return arr[i] + minMax(arr, i + 1, m);
    }
    int sum = 0;
    int minSum = std::numeric_limits<int>::max();
    for (int j = i; j <= arr.size() - m; j++)
    {
        sum += arr[j];
        auto ret = minMax(arr, j + 1, m - 1);
        ret = sum > ret ? sum : ret;
        minSum = ret < minSum ? ret : minSum;
    }
    std::cout << "\nfun(" << i << "," << m << ") = " << minSum;
    return minSum;
}

int main()
{
    vector<int> arr = { 1, 1, 2 };
    vector<int> res;
    auto ret = minMax(arr, 0, 2);
    allperm(arr, 0);
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
