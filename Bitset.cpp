// Bitset.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<bitset>
#include <vector>
#include<numeric>
#include<algorithm>
#include<functional>


struct  A
{
    int a;
    inline static int counter{ 1 };
    A()
    {
        a = counter++;
    }
    A(int o) : a(o) {}
    A& operator+(const A& obj)
    {
        a += obj.a;
        return *this;
    }
};

void fun(int &a, int b)
{
    a += b;
}

int main()
{
    auto lamb = [](const auto& obj1, const auto& obj2)
    {
        return obj1 > obj2;
    };

    int re = 12;

    auto binder = std::bind(fun, re, std::placeholders::_1);
    binder(11);
    std::vector<int> vc{1, 23, 4, 12, 4, 35, 65, 4, 21, 24, 35,23,23,23,35,43,65};
    std::sort(vc.begin(), vc.end(), lamb);
    auto iter = std::unique(vc.begin(), vc.end());
    vc.erase(iter, vc.end());

    auto ret = std::binary_search(vc.begin(), vc.end(), 35, lamb);
    
    return 0;




    /*std::bitset<33> bs, nbs;
    auto size = sizeof(bs);
    auto cnt = bs.count();
    bs.set(2);
    bs.set(3);
    bs.flip();
    cnt = bs.count();
    nbs = bs ^ (~bs);
    std::cout << "\nBitfield of used colors! : "<< bs;
    std::cout << "\nBitfield of used colors! : " << ~bs;*/
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
