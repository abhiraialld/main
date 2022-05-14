// word_square.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<string>
using namespace std;

bool chk_square(vector<string>& mat)
{
    for (int i = 0; i < mat[0].length(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (mat[i][j] != mat[j][i])
            {
                return false;
            }
        }
    }
    return true;
}

void getSquare(int ind, vector<string>& wl, vector<string>& buff)
{
    if (ind == buff[0].length())
    {
        bool ret = chk_square(buff);
        if (!ret)
            return;
        for (auto str : buff)
        {
            std::cout << "\n" << str;
        }
        std::cout << "\n";
        return;
    }

    for (int i = 0; i < wl.size(); i++)
    {
        if (wl[i][0] == buff[0][ind] && (wl[i].length() == buff[0].length()))
        {
            buff.push_back(wl[i]);
            getSquare(ind + 1, wl, buff);
            buff.pop_back();
        }
    }
    return;
}

void print_allsquare(vector<string> wl)
{
    for (int i = 0; i < wl.size(); i++)
    {
        vector<string> temp;
        temp.push_back(wl[i]);
        getSquare(1, wl, temp);
    }
}


int main()
{
    vector<string> wl = { "abat","baba","atan","atal" };
    print_allsquare(wl);
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
