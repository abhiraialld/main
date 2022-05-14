// Merge_BST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stack>
#include<vector>


class node
{
public:
    int data;
    node* left;
    node* right;

    /* Constructor that allocates
    a new node with the given data
    and NULL left and right pointers. */
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void merge_BST(node* pRoot1, node* pRoot2, std::vector<int>& vSortedOutput)
{
    std::stack<node*> st1;
    std::stack<node*> st2;

    st1.push(nullptr);
    st2.push(nullptr);

    if (!pRoot1 && !pRoot2)
    {
        return;
    }
    node* ptr1 = pRoot1;
    node* ptr2 = pRoot2;
    while ((!st1.empty() || ptr1) || (!st2.empty() || ptr2))
    {
        while (ptr2)
        {
            st2.push(ptr2);
            ptr2 = ptr2->left;
        }

        while (ptr1)
        {
            st1.push(ptr1);
            ptr1 = ptr1->left;
        }
        ptr1 = st1.top();
        ptr2 = st2.top();

        if (!ptr1 && !ptr2)
            break;


        if (ptr2 == nullptr || (ptr1 != nullptr && ptr1->data < ptr2->data))
        {
            vSortedOutput.push_back(ptr1->data);
            st1.pop();
            ptr2 = nullptr;
            if (ptr1->right)
            {
                ptr1 = ptr1->right;
            }
            else
            {
                ptr1 = nullptr;
            }
        }
        else
        {
            vSortedOutput.push_back(ptr2->data);
            st2.pop();
            ptr1 = nullptr;
            if (ptr2->right)
            {
                ptr2 = ptr2->right;
            }
            else
            {
                ptr2 = nullptr;
            }
        }

    }
}

int countNodes(node* pRoot, int nLow, int nHigh)
{
    if (pRoot == nullptr)
    {
        return 0;
    }
    int nLeftCount = 0;
    int nRightCount = 0;
    if (pRoot->data <= nHigh)
    {
        nRightCount = countNodes(pRoot->right, nLow, nHigh);
    }
    if (pRoot->data >= nLow)
    {
        nLeftCount = countNodes(pRoot->left, nLow, nHigh);
    }
    return (nLeftCount + nRightCount + (pRoot->data >= nLow && pRoot->data <= nHigh ? 1 : 0));
}

int main()
{
    node* root1 = new node(5);
    root1->left = new node(3);
    root1->right = new node(6);
    root1->left->right = new node(4);
    root1->left->left = new node(2);


    node* root2 = new node(2);
    root2->left = new node(1);
    root2->right = new node(3);
    root2->right->right = new node(7);
    root2->right->right->left = new node(6);

    std::vector<int> vSorteOutput;

    merge_BST(root1, root2, vSorteOutput);

    int count = countNodes(root2, 6, 7);


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
