// increasing_path.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>

using namespace std;


int GetMaxPath(vector<vector<int>>& mat, int a, int  b, vector<vector<int>>& vis)
{
    if (vis[a][b] != -1)
    {
        return vis[a][b];
    }
    vector<pair<int, int>> adj = { pair<int, int>(0,1), pair<int, int>(-1, 0) , pair<int, int>(1,0) , pair<int, int>(0,-1) };
    int maxLength = 0;
    for (auto p : adj)
    {
        auto lx = a + p.first;
        auto ly = b + p.second;
        if (lx < 0 || ly < 0 || lx == mat.size() || ly == mat.size())
        {
            continue;
        }
        if (mat[lx][ly] < mat[a][b])
        {
            auto len = 1 + GetMaxPath(mat, lx, ly, vis);
            maxLength = (len > maxLength) ? len : maxLength;
        }
    }
    vis[a][b] = maxLength;
    return maxLength;
}


int main()
{
    vector<vector<int>> mat(3, vector<int>());
    vector<vector<int>> vis(3, vector<int>(3, -1));
    mat[0] = { 3,4,5 };
    mat[1] = { 3,2,6 };
    mat[2] = {2,2,1};
    int maxLength = std::numeric_limits<int>::min();
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat.size(); j++)
        {
            if (vis[i][j] == -1)
            {
                auto len = GetMaxPath(mat, i, j, vis);
                maxLength = (len > maxLength) ? len : maxLength;
            }
        }
    }

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
