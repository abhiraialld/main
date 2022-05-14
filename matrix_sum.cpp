// matrix_sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>

using namespace std;


class node
{
public :
    int elem, index, arr;
    node(int a, int b, int c)
    {
        elem = a;
        index = b;
        arr = c;
    }
    bool operator>(const node& o) const
    {
        return elem > o.elem;
    }
};

class matrixSum
{
    vector<vector<int>> mat;
    unordered_map<int*, int> sumMap;
public : 
    void initialize(vector<vector<int>>& obj)
    {
        mat = obj;
        for (int i = 0; i < obj[0].size(); i++)
        {
            for (int j = 0; j < obj[0].size(); j++)
            {
                sumMap[&mat[i][j]] = GetSum(0,0, i -1, j) + GetSum(i, 0, i, j - 1) + mat[i][j];
            }
        }
    }

    void update(int x, int y, int newvalue)
    {
        auto diff = newvalue - mat[x][y];
        for (int i = x; i < 3; i++)
        {
            for (int j = y; j < 3; j++)
            {
                sumMap[&mat[i][j]] += diff;
            }
        }
    }

    int GetSum(int i, int j, int x, int y)
    {
        if ((i < 0 || i > 2) || (j < 0 || j > 2) || (x < 0 || x > 2) || (y < 0 || y > 2))
        {
            return 0;
        }
        if (i > x || j > y)
        {
            return 0;
        }
        int diff = 0;
        if (j > 0)
        {
            diff += sumMap[&mat[x][j - 1]];
        }
        if (i > 0)
        {
            diff += sumMap[&mat[i - 1][y]];
        }
        if (i > 0 && j > 0)
        {
            diff -= sumMap[&mat[i -1][j - 1]];
        }
        auto sum = sumMap[&mat[x][y]];
        return sumMap[&mat[x][y]] - diff;
    }
};

void merge(vector<vector<int>>& arr, vector<int>& result)
{
    int i = 0;
    priority_queue<node, vector<node>, greater<node>> pq;
    while (i < 3)
    {
        pq.push(node(arr[i][0], 0, i));
        i++;
    }
    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        result.push_back(top.elem);
        if (top.index < 2)
        {
            pq.push(node(arr[top.index + 1][top.arr], top.index + 1, top.arr));
        }
    }
    i = 3;
    std::cout << i;
    return;
}

int main()
{
    vector<vector<int>> mat;
    mat.assign(3, vector<int>());
    int count = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat[i].push_back(count++);
        }
    }

    vector<int> result;

    merge(mat, result);
    //matrixSum obj;
    //obj.initialize(mat);
    //obj.update(1, 1, 15);
    //int sum = obj.GetSum(0, 1, 1, 2);
    //sum = obj.GetSum(0, 1, 2, 2);
    //sum = obj.GetSum(1, 0, 1, 2);
    //sum = obj.GetSum(1,0, 3, 1);
    //sum = obj.GetSum(1, 1, 2, 2);
    //sum = obj.GetSum(2,0, 2, 2);
    //sum = obj.GetSum(0, 1, 1, 2);
    //std::cout << "Hello World!\n";
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
