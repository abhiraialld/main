// kruskal_dset.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#define V 9

int parent[V];
int rank[V];

class edge
{
public : 
    int u;
    int v;
    int weight;
    edge() = default;
    edge(int i, int j, int k)
    {
        u = i;
        v = j;
        weight = k;
    }
    bool operator==(const edge& oEdge)
    {
        return (u == oEdge.u) && (v == oEdge.v);
    }
};

void initalizeDisjointSet()
{
    for (int i = 0; i < V; i++)
    {
        parent[i] = -1;
        rank[i] = 0;
    }
}

int Find(int vertex)
{
    if (parent[vertex] == -1)
    {
        return vertex;
    }
    else
    {
        auto pVertex = Find(parent[vertex]);
        return pVertex;
    }
}

void Union(int vertexI, int vertexJ)
{
    auto iRep = Find(vertexI);
    auto jRep = Find(vertexJ);

    parent[jRep] = iRep;

   /* if (rank[iRep] > rank[jRep])
    {
        parent[jRep] = iRep;
    }
    else if (rank[jRep] > rank[iRep])
    {
        parent[iRep] = jRep;
    }
    else
    {
        parent[jRep] = iRep;
        rank[iRep]++;
    }*/
}

edge FindMin(std::vector<edge>& All_Edges)
{
    edge minEdge;
    minEdge.weight = std::numeric_limits<int>::max();
    for (int i = 0; i < All_Edges.size(); i++)
    {
        if (All_Edges[i].weight < minEdge.weight)
        {
            minEdge = All_Edges[i];
        }
    }
    return minEdge;
}

void Kruskal(std::vector<edge>& All_Edges)
{
    if (All_Edges.empty())
    {
        return;
    }

    for (int i = 0; i < V - 1;)
    {
        auto minEdge = FindMin(All_Edges);
        auto uRep = Find(minEdge.u);
        auto vRep = Find(minEdge.v);
        if (uRep == vRep)
        {
            All_Edges.erase(std::remove(std::begin(All_Edges), std::end(All_Edges), minEdge), All_Edges.end());
            continue;
        }
        Union(minEdge.u, minEdge.v);
        All_Edges.erase(std::remove(std::begin(All_Edges), std::end(All_Edges),minEdge), All_Edges.end());
        i++;
    }
}

int main()
{
    std::vector<edge> v_AllEdges;
    initalizeDisjointSet();
    v_AllEdges.push_back(edge(0, 1, 4));
    v_AllEdges.push_back(edge(1,2,8));
    v_AllEdges.push_back(edge(2,3,7));
    v_AllEdges.push_back(edge(3,4,9));
    v_AllEdges.push_back(edge(4,5,10));
    v_AllEdges.push_back(edge(5,6,2));
    v_AllEdges.push_back(edge(6,7,1));
    v_AllEdges.push_back(edge(7,0,8));
    v_AllEdges.push_back(edge(7,8,7));
    v_AllEdges.push_back(edge(2,8,2));
    v_AllEdges.push_back(edge(6,8,6));
    v_AllEdges.push_back(edge(2,5, 4));
    Kruskal(v_AllEdges);
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
