// vector_chk.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

void print_vector(std::vector<int>& vtr)
{
    cout << "\n"<<vtr.size()<<"\n";
    for (auto iter = vtr.begin(); iter < vtr.end(); iter++)
    {
        cout << "," << *iter;
    }
}

int main()
{
    std::vector<int> vtr{11,12,13,14,15,16,17};
    print_vector(vtr);
    auto iter = std::remove(vtr.begin(), vtr.end(), 13);
    print_vector(vtr);
    vtr.erase(iter, vtr.end());
    print_vector(vtr);
    vtr.push_back(93);
    print_vector(vtr);
    vtr.insert(vtr.begin(), 43);
    print_vector(vtr);
    std::sort(vtr.begin(), vtr.end(), [](auto a, auto b)
        {
            return a > b;
        });
    print_vector(vtr);
    cout << "\n" << vtr.front() << "\n" << vtr.back();
    std::cout << "\nHello World!\n";
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
