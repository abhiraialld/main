#include <iostream>
#include<vector>
#include<memory>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class LinkedList
{
    Node* start{nullptr};
public:
    class iterator {
        //friend class LinkedList;
        Node* ptr;
    public :
        int operator* ()
        {
            return ptr->data;
        }
        bool operator!=(const iterator& obj)
        {
            return ptr != obj.ptr;
        }
        iterator(Node* t)
        {
            ptr = t;
        }
        void operator++()
        {
            ptr = ptr->next;
        }
    };

    iterator begin()
    {
        return iterator(start);
    }

    iterator end()
    {
        return iterator(nullptr);
    }

    void insert(int data)
    {
        auto temp = new Node;
        temp->next = nullptr;
        temp->data = data;
        if (start == nullptr)
        {
            start = temp;
        }
        else
        {
            temp->next = start;
            start = temp;
        }
    }
};

int main()
{
    LinkedList list;
    list.insert(12);
    list.insert(2);




    
    auto iter = list.begin();
    while (iter != list.end())
    {
        cout << " " << *iter;
        ++iter;
    }
    return 0;
}
