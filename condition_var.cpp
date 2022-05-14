// condition_var.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include<mutex>
#include<condition_variable>
#include<queue>

std::mutex mut;
std::condition_variable cv;

class A
{
public:
    int count;
    inline static int counter{ 0 };
public:
    A() :count(counter++)
    {}
};

std::queue<A*> q;

void producer_thread()
{
    int i = 0;
    while (i < 10)
    {
        i++;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        auto ptr = new A;
        std::lock_guard<std::mutex> lg(mut);
        q.push(ptr);
        cv.notify_all();
    }
}


void consumer_thread()
{
    while (true)
    {
        std::unique_lock<std::mutex> ul(mut);
        cv.wait(ul, [] {return !q.empty(); });
        auto ptr = q.front();
        std::cout << "\n\n\n\n\n Printing object " << ptr->count << " from thread:"<< std::this_thread::get_id();
        q.pop();
    }
}

int main()
{
    std::cout << "Hello World!\n";
    std::thread producer_thr(producer_thread);
    std::thread* arr[5];
    for (auto& ptr : arr)
    {
        ptr = new std::thread(consumer_thread);
    }
    for (auto ptr : arr)
    {
        ptr->join();
    }
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
