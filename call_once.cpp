// call_once.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<thread>
#include<mutex>

std::once_flag res_flag;
class A {
public:
    int a;
    A()
    {
        a = 111;
    }
};


A* ptr;

void create_object()
{
    ptr = new A;
}

void print_thread()
{
    std::call_once(res_flag, create_object);
    std::cout << "\n\n Printing from thread : " << std::this_thread::get_id() << " A.a: " << ptr->a;
}

int main()
{
    std::thread *thr[10];
    for (int i = 0; i < 10; i++)
    {
        thr[i] = new std::thread(print_thread);
    }

    for (int i = 0; i < 10; i++)
    {
        if (thr[i]->joinable())
        {
            thr[i]->join();
        }
    }
    
    return 0;
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
