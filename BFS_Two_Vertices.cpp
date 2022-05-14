// BFS_Two_Vertices.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

void printPath(vector<vector<int>>& mat, int vertex, vector<int>& path, int dest, vector<int>& visited)
{
    queue<int> qu;
    qu.push(vertex);
    bool bFound = false;
    visited[vertex] = true;
    while (!qu.empty())
    {
        auto vertex = qu.front();
        qu.pop();
        for (int i = 0; i < 4; i++)
        {
            if (!visited[i] && mat[vertex][i])
            {
                path[i] = vertex;
                visited[i] = true;
                qu.push(i);
                if (i == dest)
                {
                    bFound = true;
                }
            }
        }
        if (bFound)
        {
            break;
        }
    }
    return;
}

void isCycle(vector<vector<int>>& mat, int v, vector<bool>& visited, vector<bool>& inStack, bool &bCycle)
{
    visited[v] = true;
    inStack[v] = true;
    for (int i = 0; i < 4; i++)
    {
        if (mat[v][i])
        {
            if (inStack[i])
            {
                bCycle = true;
                break;
            }
            if (!visited[i])
            {
                isCycle(mat, i, visited, inStack, bCycle);
                if (bCycle)
                {
                    break;
                }
            }
        }
    }
    inStack[v] = false;
}

int main()
{
    vector<vector<int>> mat;
    mat.assign(4, vector<int>());
    for (int i = 0; i < 4; i++)
    {
        mat[i].assign(4, 0);
    }
    mat[0][1] = 1;
    mat[0][2] = 1;
    mat[1][2] = 1;
    mat[2][0] = 1;
    mat[2][3] = 1;

    vector<bool> visited;
    visited.assign(4, false);

    vector<bool> path;
    path.assign(4, false);
    bool bCycle = false;
    isCycle(mat, 0, visited, path, bCycle);

    

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
