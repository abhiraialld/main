// list_chk.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
using namespace std;

void print_list(std::list<int>& l)
{
    cout << "\nPrinting list : "  << l.size() << "\n";
    for (auto& it : l)
    {
        cout << it << "\n";
    }
}

int main()
{
    std::cout << "Hello World!\n";
    std::list<int> l = { 11,43,23,21,56,74,46,22 };
    print_list(l);
    cout << "Printing front : " << l.front();
    l.push_front(33);
    cout << "Printing front : " << l.front();
    auto iter = std::find(l.begin(), l.end(), 21);
    l.insert(iter, 99);
    l.reverse();
    print_list(l);
    l.remove(56);
    print_list(l);
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
