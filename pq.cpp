// pq.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<queue>
#include<vector>

class node
{
    int i;
    int j;
public :
    node(int a, int b)
    {
        i = a;
        j = b;
    }
    bool operator<(const node& obj) const
    {
        return i < obj.i;
    }

    bool operator>(const node& obj) const
    {
        return i > obj.i;
    }
};

int main()
{
    std::priority_queue<node, std::vector<node>, std::greater<node>> pq;
    pq.push(node(11, 3));
    pq.push(node(1, 5));
    pq.push(node(211, 6));
    pq.push(node(112, 1));
    pq.push(node(121, 8));


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
