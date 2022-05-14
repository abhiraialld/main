// movement_grammar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;
std::pair<int, int> extractToken(string str, int st, int end)
{
    std::pair<int, int> p;
    if (str[st] >= '0' && str[st] <= '9')
    {
        auto p = extractToken(str, st + 1, end);
        p.first = st;
        return p;
    }
    else if (str[st] == 'F' || str[st] == 'R')
    {
        p.first = st;
        p.second = st + 1;
        return p;
    }
    else if (str[st] == '[')
    {
        int oc = 1, cc = 0, j = st + 1;
        while (cc < oc)
        {
            if (str[j] == '[')
            {
                oc++;
            }
            else if (str[j] == ']')
            {
                cc++;
            }
            j++;
        }
        p.first = st;
        p.second = j;
    }
    else if (str[st] == '?')
    {
        auto fp = extractToken(str, st + 1, end);
        auto sp = extractToken(str, fp.second, end);
        p.second = sp.second;
    }
    return p;
}

bool getState()
{
    static bool ret = true;
    ret = !ret;
    return ret;
}

void execute(string str, int st, int end)
{
    int i = st;
    for (; i < end;)
    {
        if (str[i] == 'F' || str[i] == 'R')
        {
            str[i] == 'F' ? cout << "Move forward\n" : cout << "Move Right\n";
            i++;
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            int d = str[i] - '0';
            int j = 0;
            auto p = extractToken(str, i, end);
            while (j < d)
            {
                execute(str, i + 1, p.second);
                j++;
            }
            i = p.second;
        }
        else if (str[i] == '?')
        {
            auto fp = extractToken(str, i + 1, end);
            auto sp = extractToken(str, fp.second, end);
            bool ret = getState();
            cout << "Getting state\n";
            if (ret)
            {
                execute(str, i + 1, fp.second);
            }
            else
            {
                execute(str, fp.second, sp.second);
            }
            i = sp.second;
        }
        else if (str[i] == '[')
        {
            auto p = extractToken(str, i, end);
            execute(str, i + 1, p.second - 1);
            i = p.second;
        }
    }
}

int main()
{
    string str = "2F2?[?[FR]3[RF]][?[?FR]2R]";
    execute(str, 0, str.length());
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
