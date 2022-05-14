// kruskal_MST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<queue>
#include<vector>
#define V 9

using namespace std;

int parent[V] = { -1, -1, -1, -1, -1, -1, -1, -1, -1 };

class edge
{

public:

    int source;
    int dest;
    int weight;

    edge(int s, int d, int w)
    {
        source = s;
        dest = d;
        weight = w;
    }

    bool operator>(const edge& obj) const
    {
        return weight > obj.weight;
    }
};

std::priority_queue<edge, vector<edge>, std::greater<edge>> qEdge;

void prepareGraph()
{
    qEdge.push(edge(0, 1, 4));
    qEdge.push(edge(1, 2, 8));
    qEdge.push(edge(2, 3, 7));
    qEdge.push(edge(3,4, 9));
    qEdge.push(edge(4, 5, 10));
    qEdge.push(edge(5,6,2));
    qEdge.push(edge(6,7,1));
    qEdge.push(edge(6,8,6));
    qEdge.push(edge(8,2,2));
    qEdge.push(edge(7,8,7));
    qEdge.push(edge(2, 5, 4));
}


int find(int parent[], int index)
{
    if (parent[index] < 0)
    {
        return index;
    }
    return find(parent, parent[index]);
}


bool unionDisjoint(int parent[], int u, int v)
{
    int parentu = find(parent, u);
    int parentv = find(parent, v);

    if (parentu > 0 && parentu == parentv)
    {
        return false;
    }

    if (parent[parentu] < parent[parentv])
    {
        parent[parentu] += parent[parentv];
        parent[parentv] = parentu;
    }
    else
    {
        parent[parentv] += parent[parentu];
        parent[parentu] = parentv;
    }
    return true;
}

void printMST()
{
    int nVertexCount = 0;
    while (nVertexCount < V - 1 && !qEdge.empty())
    {
        auto currentEdge = qEdge.top();
        qEdge.pop();
        auto retVal = unionDisjoint(parent, currentEdge.source, currentEdge.dest);
        if (!retVal)
        {
            continue;
        }
        cout << "\n" << currentEdge.source <<" -> "<< currentEdge.dest << " : " <<currentEdge.weight;
        nVertexCount++;
    }
}

int main()
{
    prepareGraph();
    printMST();
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
