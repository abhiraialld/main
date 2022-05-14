// ll_sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>


struct node
{
public : 
    int data;
    node* next;
    node* random;
};

node* start1 = nullptr, *start2 = nullptr;

node* createNode(int data)
{
    auto temp = new node;
    temp->data = data;
    temp->next = nullptr;
    temp->random = nullptr;
    return temp;
}

node* reverse(node* ptr, int& count)
{
    node* prev = nullptr;
    node* tptr = ptr;
    while (tptr)
    {
        auto temp = tptr->next;
        tptr->next = prev;
        prev = tptr;
        tptr = temp;
        count++;
    }
    return prev;
}

node* addLLS()
{
    int fCount = 0, scount = 0;
    node* freverseLLs = reverse(start1, fCount);
    node* sreverseLLs = reverse(start2, scount);
    node* p = freverseLLs, *q = sreverseLLs;
    
    int carry = 0;
    while (p || q)
    {
        int p_val = 0, q_val = 0;
        if (p)
        {
            p_val = p->data;
        }
        if (q)
        {
            q_val = q->data;
        }
        auto sum = p_val + q_val + carry;
        if (fCount > scount)
        {
            p->data = sum % 10;
        }
        else
        {
            q->data = sum % 10;
        }
        carry = sum / 10;
        if (p)
        {
            p = p->next;
        }
        if (q)
        {
            q = q->next;
        }
    }
    start1 = reverse(freverseLLs, fCount);
    start2 = reverse(sreverseLLs, scount);
    auto start = (fCount > scount ? start1 : start2);
    if (carry)
    {
        auto tnode = new node;
        tnode->data = carry;
        tnode->next = start;
        start = tnode;
    }
    return start;
}


node* deleteFromEnd(node* start, int k)
{
    if (start == nullptr)
    {
        return nullptr;
    }
    int i = 0;
    auto ptr = start;
    while (i < k && ptr)
    {
        i++;
        ptr = ptr->next;
    }
    if (ptr == nullptr)
    {
        if (i == k)
        {
            auto temp = start;
            start = start->next;
            delete temp;
        }
        return start;
    }
    auto q = start;
    while (ptr->next)
    {
        ptr = ptr->next;
        q = q->next;
    }
    auto temp = q->next;
    q->next = temp->next;
    delete temp;

    return start;
}

std::string addstr(std::string str1, std::string str2)
{
    int i = str1.length() - 1, j = str2.length() - 1;
    std::string resStr = "";
    int carry = 0;
    for (; i > -1 || j > -1; i--, j--)
    {
        int fVal = (i > -1) ? (str1[i] - '0') : 0;
        int sVal = (j > -1) ? (str2[j] - '0') : 0;
        auto sum = fVal + sVal + carry;
        carry = sum / 10;
        resStr = std::to_string(sum % 10) + resStr;
    }
    if (0 != carry)
    {
        resStr = std::to_string(carry) + resStr;
    }
    return resStr;
}

std::string mulStr(std::string str1, std::string str2)
{
    int carry = 0;
    std::string resStr;
    for (int i = str1.length() - 1; i > -1; i--)
    {
        int lsum = 0;
        std::string lStr = "";
        carry = 0;
        for (int j = str2.length() - 1; j > -1; j--)
        {
            lsum = (str1[i] - '0') * (str2[j] - '0') + carry;
            carry = lsum / 10;
            lStr = std::to_string(lsum % 10) + lStr;
        }
        if (carry)
        {
            lStr = std::to_string(carry) + lStr;
        }
        for (int k = str1.length() - 1; k > i; k--)
        {
            lStr = lStr + "0";
        }
        resStr = addstr(lStr, resStr);
    }
    return resStr;
}

void rotateMat(int mat[5][5], int si, int size)
{
    if (size <= 1)
    {
        return;
    }
    for (int i = 0; i < size - 1; i++)
    {
        auto temp = mat[si][si + i];
        mat[si][si + i] = mat[si + size - i - 1][si];
        mat[si + size - i - 1][si] = mat[si + size - 1][si + size - i - 1];
        mat[si + size - 1][si + size - i - 1] = mat[si + i][si + size - 1];
        mat[si + i][si + size - 1] = temp;
    }
    rotateMat(mat, si + 1, size - 2);
}



node* cloneLLS(node* start)
{
    if (nullptr == start)
    {
        return nullptr;
    }
    auto ptr = start;
    while (ptr)
    {
        auto temp = ptr->next;
        auto newnode = createNode(ptr->data);
        newnode->next = ptr->next;
        ptr->next = newnode;
        ptr = temp;
    }

    ptr = start;
    while (ptr)
    {
        if (ptr->random)
        {
            ptr->next->random = ptr->random->next;
        }
        ptr = ptr->next->next;
    }

    node* st2 = nullptr;
    node* temps2 = nullptr;
    ptr = start;
    while (ptr)
    {
        auto temp = ptr->next->next;
        if (st2 == nullptr)
        {
            st2 = temps2 = ptr->next;
        }
        else
        {
            temps2->next = ptr->next;
            temps2 = temps2->next;
        }
        temps2->next = nullptr;
        ptr = temp;
    }
    return st2;
}


node* fmiddle(node* start)
{
    if (nullptr == start)
    {


        return nullptr;
    }
    auto p = start;
    auto q = start;
    while (q)
    {
        q = q->next;
        if (q)
        {
            p = p->next;
            q = q->next;
        }
    }
    return p;
}

int main()
{
    int mat[5][5] = { {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25} };

    rotateMat(mat, 0, 5);
    std::string str1 = "72576255";
    std::string str2 = "5879456789";
    std::string resStr = mulStr(str2, str1);
    start1 = createNode(1);
    start1->next = createNode(2);
    start1->next->next = createNode(3);
    start1->next->next->next = createNode(4);
    start1->next->next->next->next = createNode(5);
    start1->next->next->next->next->next = createNode(6);

    auto start2 = fmiddle(start1);
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
