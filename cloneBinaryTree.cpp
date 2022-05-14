// cloneBinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<map>


struct node
{
    char data;
    node* left, * right, * random;
};

node* giveNode(char data)
{
    auto temp = new node;
    temp->data = data;
    temp->left = temp->right = temp->random = nullptr;
    return temp;
}


node* cloneTree(node* root, std::map<node*, node*>& uMap)
{
    if (root == nullptr)
    {
        return root;
    }
    node* ptr;
    if (uMap.find(root) == uMap.end())
    {
        ptr = giveNode(root->data);
        uMap.insert(std::pair<node*, node*>(root, ptr));
    }
    else
    {
        return uMap[root];
    }
    ptr->left = cloneTree(root->left, uMap);
    ptr->right = cloneTree(root->right, uMap);
    ptr->random = cloneTree(root->random, uMap);
    //if (root->random)
    //{
    //    if (uMap.find(root->random) == uMap.end())
    //    {
    //        auto tmp_ptr = giveNode(root->random->data);
    //        uMap.insert(std::pair<node*, node*>(root->random, tmp_ptr));
    //        ptr->random = tmp_ptr;
    //    }
    //    else
    //    {
    //        ptr->random = uMap[root->random];
    //    }
    //}
    return ptr;
}

int main()
{
    auto a = giveNode('a');
    auto b = giveNode('b');
    auto c = giveNode('c');
    auto d = giveNode('d');
    auto e = giveNode('e');
    auto f = giveNode('f');
    auto g = giveNode('g');
    auto h = giveNode('h');
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    d->random = b;
    e->random = c;
    c->random = g;

    std::map<node*, node*> uMap;
    auto newTree = cloneTree(a, uMap);
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
