// performLrot.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct node {
    char data;
    node* left, * right;
};

node* createNode(char data)
{
    node* ptr = new node;
    ptr->left = nullptr;
    ptr->right = nullptr;
    ptr->data = data;
    return ptr;
}


node* performLRot(node* ptr, node* parent)
{
    if (!ptr)
        return nullptr;
    node* newptr = ptr->left;
    node* displacePtr = nullptr;
    if (newptr->right)
    {
        displacePtr = newptr->right;
        ptr->left = displacePtr;
    }
    newptr->right = ptr;
    return newptr;
}

void printInorder(node* root)
{
    if (!root)
        return;
    std::cout << root->data<<"\n";
    printInorder(root->left);
    printInorder(root->right);
}

int main()
{
    node *ptr = createNode('a');
    ptr->left = createNode('b');
    ptr->right = createNode('c');
    ptr->left->left = createNode('d');
    ptr->left->right = createNode('e');
    printInorder(ptr);
    std::cout << "---------------------------------";
    ptr = performLRot(ptr, nullptr);
    printInorder(ptr);
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
