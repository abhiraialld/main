// transform.cpp : This file contains the 'main' function. Program execution begins and ends there.
// https://www.geeksforgeeks.org/transform-one-string-to-another-using-minimum-number-of-given-operation/
//

#include <iostream>
#include<string>

using namespace std;

bool canTransform(int index, string str, string dstr)
{
    for (int i = 0; i < index; i++)
    {
        cout << "    ";

    }
    cout << str.c_str()<<endl;
    if (str == dstr)
    {
        return true;
    }
    if (index == str.length())
    {
        return false;
    }
    
    for (int i = index; i < str.length(); i++)
    {
        string tstr(1, str[i]);
        if (i != 0)
        {
            tstr += str.substr(0, i);
        }
        if (i != str.length() - 1)
        {
            tstr += str.substr(i + 1, str.length() - i - 1);
        }
        auto ret = canTransform(index + 1, tstr, dstr);
        if (ret == true)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string str = "eacbd";
    string str1 = "eabcd";
    auto ret = canTransform(0, str, str1);
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
