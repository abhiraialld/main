// topo_sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<list>
#include<vector>
#include<stack>
#define V 6

void topoUtil(std::list<int> adj[], int vertex, std::stack<int>& orderedVertex, bool visited[])
{
    if (visited[vertex])
    {
        return;
    }
    visited[vertex] = true;
    for (auto edge : adj[vertex])
    {
        if (!visited[edge])
        {
            topoUtil(adj, edge, orderedVertex, visited);
        }
    }
    orderedVertex.push(vertex);
}

void topologicalSort(std::list<int> adj[])
{
    bool visited[V];
    memset(visited, false, sizeof(visited));
    std::stack<int> ordered_vertex;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            topoUtil(adj, i, ordered_vertex, visited);
        }
    }

    std::cout << "\n";
    while (!ordered_vertex.empty())
    {
        std::cout << ordered_vertex.top() << "\n";
        ordered_vertex.pop();
    }
}

int main()
{
    std::list<int> adj[V];
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);
    topologicalSort(adj);
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
