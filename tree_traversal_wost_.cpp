// tree_traversal_wost_.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<queue>
#include<stack>

#include <stdio.h>
#include <stdlib.h>

/* A binary tree tNode has data, a pointer to left child
   and a pointer to right child */
struct tNode {
    int data;
    struct tNode* left;
    struct tNode* right;
};


void inorder_trav_wst(tNode* root)
{
    if (nullptr == root)
    {
        return;
    }
    std::stack<tNode*> st;
    auto p = root;
    while (nullptr != p || !st.empty())
    {
        while (p)
        {
            st.push(p);
            p = p->left;
        }
        p = st.top();
        st.pop();
        std::cout << " " << p->data;
        p = p->right;
    }
}

void preorder_trav_wst(tNode* root)
{
    if (nullptr == root)
    {
        return;
    }
    std::stack<tNode*> st;
    auto p = root;
    while (nullptr != p || !st.empty())
    {
        while (p)
        {
            std::cout << " " << p->data;
            st.push(p);
            p = p->left;
        }
        p = st.top();
        st.pop();
        p = p->right;
    }
}


bool check_BST(tNode* root, int min, int max)
{
    if (nullptr == root)
    {
        return true;
    }
    return ((root->data > min && root->data < max) && (root->left == nullptr || check_BST(root->left, min, root->data)) &&
        (root->right == nullptr || check_BST(root->right, root->data, max)));
}



void postorder_w_st(tNode* root)
{
    if (nullptr == root)
    {
        return;
    }
    std::stack<tNode*> st;
    auto p = root;
    while (nullptr != p || !st.empty())
    {
        if (p)
        {
            tNode* temp = nullptr;
            while (p)
            {
                st.push(p);
                temp = p;
                p = p->left;
            }
            p = temp->right;
            continue;
        }

        p = st.top();
        st.pop();
        std::cout << " " << p->data;
        if (st.empty())
        {
            break;
        }
        if (st.top()->right == p)
        {
            p = nullptr;
        }
        else
        {
            p = st.top()->right;
        }
    }
}


void preorder_traversal(tNode* root)
{
    if (nullptr == root)
    {
        return;
    }
    auto current = root;
    while (nullptr != current)
    {
        
        if (nullptr == current->left)
        {
            std::cout << "  " << current->data;
            current = current->right;
        }
        else
        {
            auto pre = current->left;
            while (pre->right != nullptr &&
                pre->right != current)
            {
                pre = pre->right;
            }
            if (pre->right == nullptr)
            {
                pre->right = current;
                std::cout << " " << current->data;
                current = current->left;
            }
            else
            {
                current = pre->right->right;
                pre->right = nullptr;
            }
        }
    }
}

/* Function to traverse the binary tree without recursion
   and without stack */
void MorrisTraversal(struct tNode* root)
{
    struct tNode* current, * pre;

    if (root == NULL)
        return;

    current = root;
    while (current != NULL) {

        if (current->left == NULL) {
            printf("%d ", current->data);
            current = current->right;
        }
        else {

            /* Find the inorder predecessor of current */
            pre = current->left;
            while (pre->right != NULL
                && pre->right != current)
                pre = pre->right;

            /* Make current as the right child of its
               inorder predecessor */
            if (pre->right == NULL) {
                pre->right = current;
                current = current->left;
            }

            /* Revert the changes made in the 'if' part to
               restore the original tree i.e., fix the right
               child of predecessor */
            else {
                pre->right = NULL;
                printf("%d ", current->data);
                current = current->right;
            } /* End of if condition pre->right == NULL */
        } /* End of if condition current->left == NULL*/
    } /* End of while */
}

/* UTILITY FUNCTIONS */
/* Helper function that allocates a new tNode with the
   given data and NULL left and right pointers. */
struct tNode* newtNode(int data)
{
    struct tNode* node = new tNode;
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}


void traverseBFS(tNode* root)
{
    if (root == nullptr)
    {
        return;
    }
    auto pPtr = root;
    std::queue<tNode*> qu;
    qu.push(root);
    while (!qu.empty())
    {
        auto pPtr = qu.front();
        qu.pop();
        std::cout << " " << pPtr->data;
        if (pPtr->left)
        {
            qu.push(pPtr->left);
        }
        if (pPtr->right)
        {
            qu.push(pPtr->right);
        }
    }
}


void printRightView(tNode* root, int level, int& max_level)
{
    if (root == nullptr)
    {
        return;
    }
    if (level > max_level)
    {
        max_level = level;
        std::cout << root->data;
    }
    printRightView(root->right, level + 1, max_level);
    printRightView(root->left, level + 1, max_level);
}

tNode* createTree(int* pre, int* in, int size)
{
    if (size <= 0)
    {
        return nullptr;
    }
    tNode* node = new tNode;
    node->data = pre[0];
    node->left = nullptr;
    node->right = nullptr;
    if (size == 1)
    {
        return node;
    }
    int nIndexRoot = -1;
    for (int i = 0; i < size; i++)
    {
        if (in[i] == pre[0])
        {
            nIndexRoot = i;
            break;
        }
    }
    node->left = createTree(pre + 1, in, nIndexRoot);
    node->right = createTree(pre + nIndexRoot + 1, in + nIndexRoot + 1, size - nIndexRoot - 1);
    return node;
}


tNode* flattenTree(tNode* root)
{
    if (nullptr == root)
    {
        return nullptr;
    }
    auto left = flattenTree(root->left);
    auto right = flattenTree(root->right);
    root->left = root;
    root->right = nullptr;
    tNode* start = root;
    if (left)
    {
        start->right = left;
        start->left = left->left;
        left->left = nullptr;
    }
    if (right)
    {
        start->left->right = right;
        start->left = right->left;
        right->left = nullptr;
    }
    return start;
}

int find_max_sum(tNode* root, int &maxsum)
{
    if (nullptr == root)
    {
        return 0;
    }
    int left = find_max_sum(root->left, maxsum);
    int right = find_max_sum(root->right, maxsum);
    auto max = root->data;
    max = (left + root->data > max) ? left + root->data : max;
    max = (right + root->data > max) ? right + root->data : max;

    auto maxpathVal = (right + root->data + left > max) ? right + root->data + left : max;
    maxsum = (maxpathVal > maxsum) ? maxpathVal : maxsum;

    return max;
}

int coumt_no_of_nodes(tNode* root)
{
    if (nullptr == root)
    {
        return 0;
    }
    auto p = root;
    int llevCount = 0, rlevcount = 0;
    while (p)
    {
        p = p->left;
        llevCount++;
    }
    p = root;
    while (p)
    {
        p = p->right;
        rlevcount++;
    }
    int nNodeCount = 0;
    if (llevCount == rlevcount)
    {
        return (pow(2, llevCount) - 1);
    }
    else
    {
        nNodeCount += pow(2, llevCount - 1) - 1;
    }
    int maxLevel = llevCount;
    p = root;
    int levTraversed = 0;
    while (p)
    {
        if (p->left == nullptr && p->right == nullptr)
        {
            nNodeCount += 1;
            break;
        }
        auto q = p->left;
        levTraversed += 1;
        llevCount = 0;
        while (q && q->right)
        {
            q = q->right;
            llevCount++;
        }
        q = p->right;
        rlevcount = 0;
        while (q && q->left)
        {
            q = q->left;
            rlevcount++;
        }
        if (rlevcount == llevCount && (levTraversed + llevCount == maxLevel - 1))
        {
            nNodeCount += pow(2, llevCount);
            p = p->right;
        }
        else
        {
            p = p->left;
        }
    }
    return nNodeCount;
}



void travstinTHREADED(tNode* root)
{
    if (nullptr == root)
    {
        return;
    }
    auto p = root;
    while (p != nullptr)
    {
        if (p->left == nullptr)
        {
            std::cout << " " << p->data;
            p = p->right;
            continue;
        }
        auto q = p->left;
        while (q->right != p && q->right != nullptr)
        {
            q = q->right;
        }
        if (q->right == nullptr)
        {
            q->right = p;
            
            p = p->left;
        }
        else
        {
            q->right = nullptr;
            std::cout << " " << p->data;
            p = p->right;
        }
    }
}

void print(tNode* start, tNode* end)
{
    if (start == end)
        return;
    print(start->right, end);
    std::cout << " " << start->data;
}

void travstpostTHREADED(tNode* root)
{
    if (nullptr == root)
    {
        return;
    }
    auto p = root;
    while (p != nullptr)
    {
        if (p->left == nullptr)
        {
            p = p->right;
            continue;
        }
        auto q = p->left;
        while (q->right != p && q->right != nullptr)
        {
            q = q->right;
        }
        if (q->right == nullptr)
        {
            q->right = p;
            p = p->left;
        }
        else
        {
            print(p->left, p);
            q->right = nullptr;
            p = p->right;
        }
    }
}

void travstpreTHREADED(tNode* root)
{
    if (nullptr == root)
    {
        return;
    }
    auto p = root;
    while (p != nullptr)
    {
        if (p->left == nullptr)
        {
            std::cout << " " << p->data;
            p = p->right;
            continue;
        }
        auto q = p->left;
        while (q->right != p && q->right != nullptr)
        {
            q = q->right;
        }
        if (q->right == nullptr)
        {
            q->right = p;
            std::cout << " " << p->data;
            p = p->left;
        }
        else
        {
            q->right = nullptr;
            p = p->right;
        }
    }
 }

void travstpre(tNode* root)
{
    if (nullptr == root)
    {
        return;
    }
    std::stack<tNode*> st;
    auto p = root;
    while (!st.empty() || nullptr != p)
    {
        while (p != nullptr)
        {
            std::cout << " " << p->data;
            st.push(p);
            p = p->left;
        }
        p = st.top();
        st.pop();
        p = p->right;
    }
}

void travstin(tNode* root)
{
    if (nullptr == root)
    {
        return;
    }
    std::stack<tNode*> st;
    auto p = root;
    while (!st.empty() || nullptr != p)
    {
        while (p != nullptr)
        {
            st.push(p);
            p = p->left;
        }
        p = st.top();
        st.pop();
        std::cout << " " << p->data;
        p = p->right;
    }
}






void travstpost(tNode* root)
{
    if (nullptr == root)
    {
        return;
    }
    std::stack<tNode*> st;
    auto p = root;
    while (!st.empty() || nullptr != p)
    {
        if (nullptr != p)
        {
            while (p != nullptr)
            {
                st.push(p);
                p = p->left;
            }
            p = st.top()->right;
            continue;
        }
        p = st.top();
        st.pop();
        std::cout << " " << p->data;
        if (st.empty())
        {
            break;
        }
        if (p == st.top()->right)
        {
            p = nullptr;
        }
        else
        {
            p = st.top()->right;
        }
    }
}


/* Driver program to test above functions*/
int main()
{
    int prearr[] = { 1,2,4,5,3 };
    int inarr[] = {4,2,5,1,3};
    //auto troot = createTree(prearr, inarr, sizeof(prearr) / sizeof(prearr[0]));

    int max_level = -1;
    //printRightView(troot, 0, max_level);

   // traverseBFS(troot);

    /* Constructed binary tree is
            1
          /   \
         2     3
       /   \
      4     5
  */
    struct tNode* root = newtNode(1);
    root->left = newtNode(2);
    root->right = newtNode(3);
    root->left->left = newtNode(4);
    root->left->left->right = newtNode(14);
    root->left->right = newtNode(5);
    //root->right->left = newtNode(6);
    root->right->right = newtNode(6);

    tNode* dummy = newtNode(-1);
    dummy->left = root;

    travstpostTHREADED(dummy);
    auto limit = std::numeric_limits<int>::min();
    auto ret = coumt_no_of_nodes(root);

    //postorder_w_st(root);

    //preorder_traversal(root);
    auto retVal = check_BST(root, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    auto start = flattenTree(root);
    postorder_w_st(root);

    return 0;
}