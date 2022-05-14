// 2charlen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>

using namespace std;
int find_max_length(string str)
{
    int lat[26];
    memset(lat, 0, sizeof(lat));

    int max_length = 0, length = 0;
    string lstr = "";
    for (int i = 0; i < str.length(); i++)
    {
        lat[str[i] - 'a'] = i;
        if (lstr.find(str[i]) != string::npos)
        {
            length++;
        }
        else if (lstr.length() < 2)
        {
            length++;
            lstr.push_back(str[i]);
        }
        else
        {
            char removeChar = (lat[lstr[0] - 'a'] < lat[lstr[1] - 'a']) ? lstr[0] : lstr[1];
            lstr.erase(std::remove(lstr.begin(), lstr.end(), removeChar), lstr.end());
            lstr.push_back(str[i]);
            if (length > max_length)
            {
                max_length = length;
            }
            length = i - lat[removeChar - 'a'];
        }
    }
    if (length > max_length)
    {
        max_length = length;
    }
    return max_length;
}

int main()
{
    std::cout << "Hello World!\n";
    string str = "eceba";
    auto length = find_max_length(str);
    std::cout << std::endl;
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
