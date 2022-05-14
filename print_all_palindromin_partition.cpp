// print_all_palindromin_partition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;


bool chk_palin(string str, int l, int h)
{
    if (l >= h)
    {
        return true;
    }
    return((str[l] == str[h]) && chk_palin(str, l + 1, h - 1));
}

int main()
{
    string str = "madam";
    for (int i = 1; i <= str.length(); i++)
    {
        cout << "\n";
        int j = 0;
        bool foundPal = false;
        string toPrintStr = "";
        for (j = 0; (i + j) <= str.length();)
        {
            bool ret = chk_palin(str, j, i + j - 1);
            if (ret)
            {
                foundPal = true;
                for (int k = j; k < i + j; k++)
                {
                    toPrintStr.append(1,str[k]);
                }
                toPrintStr += " ";
                j += i;
            }
            else
            {
                toPrintStr.append(1, str[j]);
                toPrintStr += " ";
                j++;
            }
        }
        if (!foundPal)
            continue;
        for (; j < str.length(); j++)
        {
            toPrintStr.append(1, str[j]);
            toPrintStr += " ";
        }
        cout << toPrintStr.c_str();

    }
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
