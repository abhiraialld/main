// dijkstra.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define V 9 


int find_minimum(int dist[], bool visited[])
{
    auto min = std::numeric_limits<int>::max();
    int min_index = -1;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && dist[i] < min)
        {
            min_index = i;
            min = dist[i];
        }
    }
    return min_index;
}

int a[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };


void find_shortest_path()
{
    bool visited[V];
    int dist[V];
    memset(visited, false, sizeof(visited));
    for (int i = 1; i < V; i++)
    {
        dist[i] = std::numeric_limits<int>::max();
    }
    dist[0] = 0;

    for (int i = 0; i < V; i++)
    {
        auto index = find_minimum(dist, visited);
        visited[index] = true;

        for (int j = 0; j < V; j++)
        {
            if (j != index && a[index][j]!= 0 && a[index][j] + dist[index] < dist[j])
            {
                dist[j] = dist[index] + a[index][j];
            }
        }
    }

    auto b = 5;
    b;
    visited[0] = false;
    return;
}

int main()
{

    

    find_shortest_path();
    

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
