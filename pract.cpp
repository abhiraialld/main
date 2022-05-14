// pract.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<map>
#include<vector>
#include<stack>
#include<unordered_set>

void tsort(int index, std::vector<std::vector<int>>& g, std::stack<int>& st, std::vector<bool>& visited, std::vector<int>& inStack)
{

    visited[index] = true;
    inStack[index] = 1;
    for (int i = 0; i < 6; i++)
    {
        if (g[index][i] == 1)
        {
            if (!visited[i])
            {
                tsort(i, g, st, visited, inStack);
            }
            else if (visited[i] && inStack[i])
            {
                std::cout << "Cycle exists";
            }
        }
    }
    st.push(index);
    inStack[index] = 0;
}

int calc_max_profit(std::vector<int>& arr, int i, int k, std::vector<std::vector<int>>& dp)
{
    if (k == 0)
    {
        return 0;
    }
    if (i >= arr.size() - 1)
    {
        return 0;
    }
    if (dp[i][k - 1] != -1)
    {
        return dp[i][k - 1];
    }
    auto max_profit = calc_max_profit(arr, i + 1, k, dp);
    for (int j = i + 1; j < arr.size(); j++)
    {
        if (arr[j] <= arr[i])
        {
            continue;
        }
        auto l_p = arr[j] - arr[i];
        l_p += calc_max_profit(arr, j + 1, k - 1, dp);
        max_profit = l_p > max_profit ? l_p : max_profit;
    }
    dp[i][k - 1] = max_profit;
    return max_profit;
}


int main()
{
    int k = 3;
    std::vector<int> arr = { 12,24,32,21,54,30,52 };
    std::vector<std::vector<int>> dp(arr.size(), std::vector<int>());
    for (int i = 0; i < dp.size(); i++)
    {
        dp[i].insert(dp[i].begin(), k, -1);
    }
    auto max_profit = calc_max_profit(arr, 0, k, dp);
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
