// graph_BFS_adjacency.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include<queue>
#include<stack>

void print_BFS(int adj[][4], std::vector<bool>visited)
{
    std::queue<int> bfs_queue;
    bfs_queue.push(0);
    while (!bfs_queue.empty())
    {
        auto vertex = bfs_queue.front();
        bfs_queue.pop();
        std::cout << "->"<<vertex;
        visited[vertex] = true;
        for (int i = 0; i < 4; i++)
        {
            if (adj[vertex][i] == 1 && !visited[i])
            {
                bfs_queue.push(i);
                visited[i] = true;
            }
        }
    }
}

void print_DFS(int adj[][4], std::vector<bool> visited)
{
    std::stack<int> dfs_stack;
    dfs_stack.push(1);
    visited[1] = true;
    while (!dfs_stack.empty())
    {
        auto vertex = dfs_stack.top();
        dfs_stack.pop();
        std::cout << "->" << vertex;
        for (int i = 0; i < 4; i++)
        {
            if (adj[vertex][i] == 1 && !visited[i])
            {
                dfs_stack.push(i);
                visited[i] = true;
            }
        }
    }
}

int main()
{
    int vertices = 4;
    std::vector<bool> visited(vertices, false);
    int adjacency_mat[][4] = { {0,1,1,0}, {0,0,1,0}, {1,0,0,1}, {0,0,0,1} };
    print_DFS(adjacency_mat, visited);
    std::cout << "Hello World!\n";
}
