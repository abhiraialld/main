// tree_rotations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// tree_conditional_sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<cstdlib>

using namespace std;

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

struct imBalancedNode
{
    node* pParent;
    node* pImBalancedNode;
    string szDirection;
};


node* perform_RR_Rotation(node* root)
{
    if (!root)
    {
        return nullptr;
    }
    auto oldRoot = root;
    root = root->right;
    auto leftRSubTree = root->left;
    root->left = oldRoot;
    oldRoot->right = leftRSubTree;
    return root;
}

node* performLL_Rotation(node* root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    auto pOldRootBackup = root;
    root = root->left;
    auto pRightSubTreeBkup = root->right;
    root->right = pOldRootBackup;
    pOldRootBackup->left = pRightSubTreeBkup;
    return root;

}

node* performRLRotation(node* root)
{
    if (root == nullptr)
    {
        return root;
    }
    auto pOldRootBackUp = root;
    root = root->left->right;
    pOldRootBackUp->left->right = root->left;
    root->left = pOldRootBackUp->left;
    pOldRootBackUp->left = root->right;
    root->right = pOldRootBackUp;

    return root;

}


node* SearchInBST(node* root, int data)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->data == data)
    {
        return root;
    }
    else if (root->data < data)
    {
        return SearchInBST(root->right, data);
    }
    else
    {
        return SearchInBST(root->left, data);
    }
}

node* InsertInBST(node* root, int data)
{
    if (root == nullptr)
    {
        node* pNewNode = new node(data);
        return pNewNode;
    }
    else if (root->data < data)
    {
        root->right = InsertInBST(root->right, data);
    }
    else
    {
        root->left = InsertInBST(root->left, data);
    }
    return root;
}


string FindImBalancedNode(node* pNode, node* pParent, imBalancedNode& nodeDetails)
{
    if (pNode == nullptr)
    {
        return "";
    }
    string lstr = FindImBalancedNode(pNode->left, pNode, nodeDetails);
    if (nodeDetails.pImBalancedNode != nullptr)
    {
        return lstr;
    }

    string rstr = FindImBalancedNode(pNode->right, pNode, nodeDetails);
    if (nodeDetails.pImBalancedNode != nullptr)
    {
        return rstr;
    }

    int nHeightDifference = abs((static_cast<int>(lstr.length() - rstr.length())));
    if (nHeightDifference > 1)
    {
        nodeDetails.pImBalancedNode = pNode;
        nodeDetails.pParent = pParent;
        nodeDetails.szDirection = (lstr.length() > rstr.length()) ? lstr : rstr;
        return ((lstr.length() > rstr.length()) ? lstr : rstr);
    }
    bool bIsLeftSubTreeLarger = (lstr.length() > rstr.length());
    if (!pParent)
    {
        return ((lstr.length() > rstr.length()) ? lstr : rstr);
    }
    else
    {
        if (bIsLeftSubTreeLarger)
        {
            return lstr.append(1, (pParent->left == pNode) ? 'L' : 'R');
        }
        else
        {
            return rstr.append(1, (pParent->left == pNode) ? 'L' : 'R');
        }
    }
}


int main()
{
    node* pRoot = nullptr;
    pRoot = InsertInBST(pRoot, 82);
    pRoot = InsertInBST(pRoot, 70);
    pRoot = InsertInBST(pRoot, 90);
    pRoot = InsertInBST(pRoot, 40);
    pRoot = InsertInBST(pRoot, 75);
    pRoot = InsertInBST(pRoot, 72);

    imBalancedNode imBalNode;
    imBalNode.pParent = nullptr;
    imBalNode.pImBalancedNode = nullptr;
    imBalNode.szDirection = "";

    FindImBalancedNode(pRoot, nullptr, imBalNode);


    string str = "LLLR";
    string substr = str.substr(str.length() - 2, 2);

    std::cout << "Hello World!\n";
}


