// kmp_string_match.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<string>


void prepareStr(std::string str, std::vector<int>& vec)
{
    int len = 0, i = 1;
    vec.push_back(0);
    while (i < str.length())
    {
        if (str[len] == str[i])
        {
            len++;
            vec.push_back(len);
            i++;
        }
        else
        {
            if (len == 0)
            {
                vec.push_back(0);
                i++;
            }
            else
            {
                len = vec[len - 1];
            }
        }
    }
}

bool compareStr(std::string& sourceStr, std::string& str, std::vector<int>& vec)
{
    int i = 0, j = 0;
    bool bFound = false;
    while (i < sourceStr.length() && !bFound)
    {
        if (sourceStr[i] == str[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j == 0)
            {
                i++;
            }
            else
            {
                j = vec[j - 1];
            }
        }
        if (j == str.length())
        {
            bFound = true;
            break;
        }
    }
    return bFound;
}

int main()
{
    std::string sourcestr = "ababcabcabababd";
    std::string str = "ababx";
    std::vector<int> vec;
    prepareStr(str, vec);
    auto ret = compareStr(sourcestr, str, vec);
    std::cout << str;
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
