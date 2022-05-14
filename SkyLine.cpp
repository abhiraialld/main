// SkyLine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_map>
using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b)
{
    if (a.first == b.first)
    {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int dedup(vector<int>& arr)
{
    int count = 0;
    int i = 1;
    for (; i < arr.size(); i++)
    {
        if (arr[i] == arr[i - 1])
        {
            count++;
        }
        else
        {
            arr[i - count] = arr[i];
        }
    }
    return arr.size() - count;
}

vector<pair<int, int>> getSkyLine(vector<vector<int>>& mat)
{
    std::vector<int> is;
    vector<pair<int, int>> result;
    for (int i = 0; i < mat.size(); i++)
    {
        is.push_back(mat[i][0]);
        is.push_back(mat[i][1]);
    }
    std::sort(is.begin(), is.end());
    int size = dedup(is);
    std::priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&compare)> pq(compare);
    int i = 0, cub = 0;
    bool check = false;
    int prev = -1;
    while (i < size || cub < mat.size())
    {
        check = false;
        while (!pq.empty() && pq.top().second <= is[i])
        {
            pq.pop();
            check = true;
        }
        while (cub < mat.size() && mat[cub][0] == is[i])
        {
            pq.push(pair<int, int>(mat[cub][2], mat[cub][1]));
            check = true;
            cub++;
        }
        if (check)
        {
            if (pq.empty())
            {
                result.push_back(pair<int, int>(is[i], 0));
                prev = 0;
            }
            else
            {
                if (prev != pq.top().first)
                {
                    prev = pq.top().first;
                    result.push_back(pair<int, int>(is[i], prev));
                }
            }
        }
        i++;
    }
    return result;
}
int gCount = 0;
bool checkSum(vector<int>& arr, int index, int sum, vector<vector<int>>& mat)
{
    gCount++;
    if (index == arr.size() || sum < 0)
    {
        return false;
    }
    if (0 == sum)
    {
        return true;
    }
    auto ret = checkSum(arr, index + 1, sum, mat);
    ret = ret || checkSum(arr, index + 1, sum - arr[index], mat);
    return ret;
}

bool canPartition(vector<int>& arr)
{
    auto sum = 0;
    for (auto i : arr)
    {
        sum += i;
    }
    if (sum % 2 == 1)
    {
        return false;
    }
    sum /= 2;
    vector<vector<int>> mat(arr.size(), vector<int>(sum + 1, -1));
    auto ret = checkSum(arr, 0, sum, mat);
    return ret;
}

int main()
{
    vector<vector<int>> mat(2, vector<int>());

    vector<int> arr = { 1,5,11,5 };
    auto ret = canPartition(arr);
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
