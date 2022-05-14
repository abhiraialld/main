// splay tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct node
{
    int data;
    node* left, * right;
};

node* getNode(int data)
{
    auto temp = new node;
    temp->left = nullptr;
    temp->right = nullptr;
    temp->data = data;
    return temp;
}


node* insert(node* root, int data)
{
    if (nullptr == root)
    {
        auto temp = getNode(data);
        return temp;
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }

    return root;
}

node* leftRotate(node* root)
{
    if (nullptr == root || nullptr == root->right)
    {
        return root;
    }
    auto newRoot = root->right;
    root->right = root->right->left;
    newRoot->left = root;
    return newRoot;
}

node* rightRotate(node* root)
{
    if (nullptr == root || nullptr == root->left)
    {
        return root;
    }
    auto newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    return newRoot;
}


node* splay(node* root, int data)
{
    if (nullptr == root || root->data == data)
    {
        return root;
    }
    if (root->data > data)
    {
        if (root->left == nullptr)
        {
            return root;
        }
        if (data < root->left->data)
        {
            root->left->left = splay(root->left->left, data);
            root = rightRotate(root);
        }
        else
        {
            root->left->right = splay(root->left->right, data);
            if (nullptr != root->left->right)
            {
                root->left = leftRotate(root->left);
            }
        }
        return rightRotate(root);
    }
    else
    {
        if (nullptr == root->right)
        {
            return root;
        }
        if (data > root->right->data)
        {
            root->right->right = splay(root->right->right, data);
            root = leftRotate(root);
        }
        else
        {
            root->right->left = splay(root->right->left, data);
            if (nullptr != root->right->left)
            {
                root->right = rightRotate(root->right);
            }
        }
        return leftRotate(root);
    }
}

int main()
{
    node* root = nullptr;
    root = insert(root, 24);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 27);
    root = insert(root, 17);
    root = insert(root, 22);
    root = leftRotate(root);
    root = rightRotate(root);
    root = splay(root, 27);
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
