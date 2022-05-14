// ll_operations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct node
{
    int data;
    node* next;
};


node* returnMid(node* start)
{
    if (nullptr == start)
    {
        return nullptr;
    }
    node* slow = start;
    node* fast = start;
    while (fast)
    {
        fast = fast->next;
        if (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow->next;
}


node* deleteFromEnd(node *start, int count)
{
    auto newStart = start;
    if (start == nullptr)
    {
        return nullptr;
    }
    int i = 0;
    node* fwd_ptr = start;
    node* prev = start;
    node* ptr = start;
    while (nullptr != fwd_ptr && i < count - 1)
    {
        prev = fwd_ptr;
        fwd_ptr = fwd_ptr->next;
        i++;
    }
    if (nullptr == fwd_ptr)
    {
        return start;
    }
    else if (fwd_ptr->next == nullptr)
    {
        newStart = start->next;
        delete start;
    }
    else
    {
        while (fwd_ptr->next != nullptr)
        {
            fwd_ptr = fwd_ptr->next;
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = ptr->next;
        delete ptr;
    }
    return newStart;
}

void removeLoop(node* start)
{
    if (nullptr == start)
    {
        return;
    }
    auto fptr = start;
    auto sptr = start;
    do
    {
        fptr = fptr->next;
        if (fptr)
        {
            fptr = fptr->next;
            sptr = sptr->next;
        }
    } while (fptr && sptr != fptr);

    if (nullptr == fptr)
    {
        std::cout << "\nLoop not present";
        return;
    }
    int nLoopLength = 0;

    do {
        nLoopLength++;
        fptr = fptr->next;
    } while (fptr != sptr);

    fptr = start;
    int i = 0;
    while (i < nLoopLength)
    {
        i++;
        fptr = fptr->next;
    }

    sptr = start;
    node* prev = nullptr;
    while (sptr != fptr)
    {
        sptr = sptr->next;
        prev = fptr;
        fptr = fptr->next;
    }
    if (nullptr == prev)
    {
        start->next = nullptr;
    }
    else
    {
        prev->next = nullptr;
    }

}

node* reverseLL(node* start)
{
    if (nullptr == start)
    {
        return nullptr;
    }
    node* newNext = nullptr;
    node* ptr = start;
    while (ptr)
    {
        auto temp = ptr->next;
        ptr->next = newNext;
        newNext = ptr;
        ptr = temp;
    }
    return newNext;
}


int main()
{
    node* start = new node;
    start->data = 3;
    start->next = new node;
    start->next->data = 7;
    auto lnode = start->next->next = new node;
    start->next->next->data = 8;
    start->next->next->next = new node;
    start->next->next->next->data = 9;
    start->next->next->next->next = new node;
    start->next->next->next->next->data = 11;
    start->next->next->next->next->next = lnode;

    //auto ptr = returnMid(start);

    //start = deleteFromEnd(start, 2);

    //start = reverseLL(start);

    removeLoop(start);

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
