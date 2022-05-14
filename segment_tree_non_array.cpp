// segment_tree_non_array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


struct node
{
    int data;
    node* left, * right;
};

node* root = nullptr;



void Update(node* root, int l, int r, int index, int val)
{
    if (l == r && l == index)
    {
        root->data = val;
        return;
    }
    if (l > index || r < index)
    {
        return;
    }
    auto mid = l + (r - l) / 2;
    if (index <= mid)
    {
        if (root->left == nullptr)
        {
            auto vnode = new node;
            vnode->left = nullptr;
            vnode->right = nullptr;
            root->left = vnode;
        }
        Update(root->left, l, mid, index, val);
    }
    else
    {
        if (root->right == nullptr)
        {
            auto vnode = new node;
            vnode->left = nullptr;
            vnode->right = nullptr;
            root->right = vnode;
        }
        Update(root->right, mid + 1, r, index, val);
    }
    int sum = 0;
    sum += (root->left) ? root->left->data : 0;
    sum += (root->right) ? root->right->data : 0;
    root->data = sum;
    return;
}

int sum(node* root, int l, int r, int sl, int sr)
{
    if (sr < l || sl > r)
    {
        return 0;
    }
    if (sl <= l && sr >= r)
    {
        return root->data;
    }
    int asum = 0;
    auto mid = l + (r - l) / 2;
    if (root->left != nullptr)
    {
        asum += sum(root->left, l, mid, sl, sr);
    }
    if (root->right != nullptr)
    {
        asum += sum(root->right, mid + 1, r, sl, sr);
    }
    return asum;
}

int main()
{
    root = new node;
    root->left = nullptr;
    root->right = nullptr;
    Update(root, 0, 7, 3, 4);
    Update(root, 0, 7, 6, 7);
    Update(root, 0, 7, 2, 3);
    Update(root, 0, 7, 1, 2);
    Update(root, 0, 7, 5, 6);
    auto req_Sum = sum(root, 0, 7, 2,6);
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
