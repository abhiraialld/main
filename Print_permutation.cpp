// Print_permutation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include<map>
#include<set>
int count = 0;
void permute_string(char* ptr, int index, int len)
{
    if (index == len)
    {
        std::cout << "\n" << ptr << ++count;
    }
    for (int i = index; i < len; i++)
    {
        auto temp = ptr[index];
        ptr[index] = ptr[i];
        ptr[i] = temp;

        permute_string(ptr, index + 1, len);

        temp = ptr[index];
        ptr[index] = ptr[i];
        ptr[i] = temp;

    }
}

void print_comb(char* ptr, std::string& str, int index, int k, int len)
{
    if (ptr == nullptr)
    {
        return;
    }
    if (str.length() == k)
    {
        std::cout << str << "\n";
        return;
    }
    for (int i = index; i < len - (k - str.length() - 1); i++)
    {
        str.append(1, ptr[i]);
        print_comb(ptr, str, i + 1, k, len);
        str.pop_back();
    }

}

int main()
{
    char ptr[] = "abcde";
    std::map<std::set<int>, int> myMap;
    std::string str = "";
    std::cout << "Hello World!\n";
    print_comb(ptr, str, 0, 3, static_cast<int>(strlen(ptr)));
    return 0;
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
