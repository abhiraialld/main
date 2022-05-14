// priority_queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<queue>


int main()
{
    // max_heap
    std::priority_queue<int> qu;
    qu.push(23);
    qu.push(231);
    qu.push(123);
    qu.push(213);
    qu.push(203);
    std::cout << "Top of heap : " << qu.top();
    qu.pop();
    std::cout << "Top of heap : " << qu.top();
    //min_heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> mh_qu;
    mh_qu.push(23);
    mh_qu.push(231);
    mh_qu.push(123);
    mh_qu.push(213);
    mh_qu.push(203);
    std::cout << "Top of min heap : " << mh_qu.top();
    mh_qu.pop();
    std::cout << "Top of min heap : " << mh_qu.top();
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
