// Unorderd_map.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<unordered_map>

class akey {
public :
    int key;
    int value;
    bool operator==(const akey& obj) const
    {
        return key == obj.key;
    }
};

//template<>
//class std::hash<akey>
//{
//public :
//    std::size_t operator()(const akey& obj) const
//    {
//        return hash<int>()(obj.key);
//    }
//};



int arr[][3] = {
    {1,2,3},
{4,5,6}, 
{7,8,9}, };

int main()
{
    std::unordered_map<int*, int> umap;
    umap.insert(std::pair<int*, int>(&arr[0][0], 12));
    umap.insert(std::pair<int*, int>(&arr[0][1], 13));
    std::cout << "Hello World!\n";

    auto iter = umap.find(&arr[0][0]);
    if (umap.end() != iter)
    {
        std::cout << "\nElement found : " << iter->second;
    }

    for (auto it = umap.begin(); it != umap.end(); )
    {
        if (it->second == 12)
        {
            it = umap.erase(it);
        }
        else
        {
            it++;
        }
    }
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
