// rvo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class A
{
public:
    A()
    {
        std::cout << "\nDefault constructor called";
    }
    A(const A& a)
    {
        std::cout << "\nCopy constructor called";
    }
    A(A&& o)
    {
        std::cout << "\n Move constructor called";
    }
    A& operator=(const A& o)
    {
        std::cout << "\nlvalue assignment called";
        return *this;
    }
    A& operator=(A&& o)
    {
        std::cout << "\nrvalue assignment called";
        return *this;
    }
};

class B: public A
{

};

A fun(A& obj)
{
    //A obj1;
    return obj;
}

template
<typename T,
typename = std::false_type>
T fun( T& o)
{
    return o;
}

int main()
{
    //A&& bj = std::move(*(new B));
     A obj;
    auto o  = fun(obj);
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
