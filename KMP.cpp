// KMP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<vector>
using namespace std;
void process(string str, vector<int>& di)
{
    di[0] = 0;
    int m = 0;
    for (int i = 1; i < str.length(); i++)
    {
        while (true)
        {
            if (str[i] == str[m])
            {
                m++;
                di[i] = m;
                break;
            }
            else if (m == 0)
            {
                di[i] = 0;
                break;
            }
            else
            {
                m = di[m - 1];
            }
        }
    }
}

int find(string te, string pat, vector<int>& di)
{
    int i = 0; int j = 0;
    bool found = true;
    while (i < te.length())
    {
        if (te[i] == pat[j])
        {
            i++;
            j++;
        }
        else if (j == 0)
        {
            i++;
        }
        else
        {
            j = di[j - 1];
        }
        if (j == pat.length())
        {
            found == true;
            break;
        }
    }
    if (found)
    {
        return i - pat.length();
    }
    return -1;
}


//void reverse(string& str)
//{
//    int n = str.length() / 2;
//    for (int i = 0; i < n; i++)
//    {
//        auto temp 
//    }
//}

void validateP(string& str)
{
    int count = 0, oc = 0, cc = 0;
    int i = 0;
    for (i = 0; i < str.length(); i++)
    {
        if ('(' == str[i])
        {
            oc++;
        }
        else if (')' == str[i])
        {
            cc++;
        }
        if (cc > oc)
        {
            count++; cc--;
        }
        else
        {
            str[i - count] = str[i];
        }
    }
    str[i - count] = 0;
    if (oc > cc)
    {
        oc = 0;
        cc = 0;
        count = 0;
        str.shrink_to_fit();
        std::reverse(std::begin(str), std::end(str));
        for (i = 0; i < str.length(); i++)
        {
            if ('(' == str[i])
            {
                oc++;
            }
            else if (')' == str[i])
            {
                cc++;
            }
            if (oc > cc)
            {
                count++; oc--;
            }
            else
            {
                str[i - count] = str[i];
            }
        }
        //str[i - count] = 0;
        str = str.substr(0, i - count);
        std::reverse(std::begin(str), std::end(str));
    }
    
}

int main()
{
    string str = "a((bc)d";
    validateP(str);
    /*string te = "ABABDABACDABABCABAB";
    vector<int> di(str.length(), 0);
    process(str, di);
    auto ind = find(te, str, di);*/
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
