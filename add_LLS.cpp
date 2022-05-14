// add_LLS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct node
{
    int data;
    node* next;
};

//int GetNodeCount(node* pStart)
//{
//    if (pStart == nullptr)
//    {
//        return 0;
//    }
//    node* pTempPtr = pStart;
//    int count = 0;
//    while (pTempPtr != nullptr)
//    {
//        count++;
//        pTempPtr = pTempPtr->next;
//    }
//    return count;
//}
//
//
//int AddRemaining(node* pStart1, int nCarry, int diff)
//{
//    if (diff == 0 || pStart1 == nullptr)
//    {
//        return nCarry;
//    }
//    int nCarriedCarry = AddRemaining(pStart1->next, nCarry, diff - 1);
//    pStart1->data += nCarriedCarry;
//    int nRetVal = 0;
//    if (pStart1->data > 10)
//    {
//        nRetVal = pStart1->data / 10;
//    }
//    pStart1->data %= 10;
//    return nRetVal;
//}
//
//int AddEqualLLs(node* pStart1, node* pStart2)
//{
//    if (pStart1 == nullptr)
//    {
//        return 0;
//    }
//    int nCarry = AddEqualLLs(pStart1->next, pStart2->next);
//    pStart1->data += pStart2->data + nCarry;
//
//    int nRetVal = 0;
//
//    if (pStart1->data > 10)
//    {
//        nRetVal = pStart1->data / 10;
//    }
//    pStart1->data %= 10;
//    return nRetVal;
//}
//
//node* AddLLS(node* pStart1, node* pStart2)
//{
//    if (pStart1 == nullptr || pStart2 == nullptr)
//    {
//        return (pStart1 == nullptr ? pStart2 : pStart1);
//    }
//    int nLenLL1 = GetNodeCount(pStart1);
//    int nLenLL2 = GetNodeCount(pStart2);
//    int nLengthDiff = 0;
//    node* ptr1 = pStart1, * ptr2 = pStart2;
//
//    if (nLenLL1 > nLenLL2)
//    {
//        nLengthDiff = nLenLL1 - nLenLL2;
//        int nCounter = nLenLL1;
//        ptr1 = pStart1;
//        while (nCounter > nLenLL2)
//        {
//            nCounter--;
//            ptr1 = ptr1->next;
//        }
//    }
//    else if (nLenLL1 < nLenLL2)
//    {
//        nLengthDiff = nLenLL2 - nLenLL1;
//        int nCounter = nLenLL2;
//        ptr1 = pStart1;
//        while (nCounter > nLenLL1)
//        {
//            nCounter--;
//            ptr1 = ptr1->next;
//        }
//    }
//
//    int nCarry = AddEqualLLs(ptr1, ptr2);
//
//    if (nLenLL1 != nLenLL2 && nCarry != 0)
//    {
//        nCarry = AddRemaining((nLenLL1 > nLenLL2 ? pStart1 : pStart2), nCarry);
//    }
//    if (nCarry != 0)
//    {
//        auto pNewNode = new node;
//        pNewNode->data = nCarry;
//        pNewNode->next = 
//    }
//
//}


node* reorg(node* start, int data)
{
    node* prev = start;
    node* ptr = start->next;
    while (ptr != nullptr)
    {
        if (ptr->data < data)
        {
            auto temp = ptr->next;
            ptr->next = start;
            start = ptr;
            ptr = temp;
        }
        else
        {
            if (prev != nullptr)
            {
                prev->next = ptr;
                prev = ptr;
                ptr = ptr->next;
            }
        }
    }
    if (prev)
    {
        prev->next = nullptr;
    }
    return start;
}

node* createnode(int data)
{
    auto ptr = new node;
    ptr->data = data;
    ptr->next = nullptr;
    return ptr;
}

int main()
{
    node* start = createnode(15);
    start->next = createnode(6);
    start->next->next = createnode(2);
    start->next->next->next = createnode(3);
    start->next->next->next->next = createnode(4);
    start->next->next->next->next->next = createnode(11);
    start->next->next->next->next->next->next = createnode(13);
    start = reorg(start, 14);
    //start->next->next->next->next->next->next->next = createnode(6);
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
