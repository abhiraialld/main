// tree_conditional_sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

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


bool selectNode(node* root, int& sum)
{
    if (root == NULL)
    {
        return false;
    }
    bool bRetVal = false;
    bool bLeftSelected = selectNode(root->left, sum);
    bool bRightSelected = selectNode(root->right, sum);

    if (bLeftSelected && bRightSelected)
    {
        if (root->data > root->left->data + root->right->data)
        {
            sum -= (root->left->data + root->right->data);
            sum += root->data;
            bRetVal = true;
        }
    }
    else if (bLeftSelected)
    {
        if (root->data > root->left->data)
        {
            sum -= (root->left->data);
            sum += root->data;
            bRetVal = true;
        }
    }
    else if (bRightSelected)
    {
        if (root->data > root->right->data)
        {
            sum -= (root->right->data);
            sum += root->data;
            bRetVal = true;
        }
    }
    else
    {
        sum += root->data;
        bRetVal = true;
    }
    return bRetVal;
}



int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(1);
    root->right = new node(3);
    root->right->left = new node(4);
    root->right->right = new node(5);
    root->right->right->left = new node(10);
    root->right->right->right = new node(11);
    root->right->left->left = new node(6);
    root->right->left->right = new node(7);
    int sum = 0;
    selectNode(root, sum);
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
