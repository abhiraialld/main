// string.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> findStr(string a, string b)
{
    unordered_map<char, int> hm;
    int uCount = 0;
    for (int i = 0; i <b.length(); i++)
    {
        if (hm[b[i]] == 0)
        {
            uCount++;
        }
        hm[b[i]]++;
    }
    unordered_map<char, int> lhm;
    vector<int> result;
    int s_i = -1;
    int matchCount = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (hm[a[i]])
        {
            if (s_i == -1)
            {
                s_i = i;
            }
            lhm[a[i]]++;
            if (lhm[a[i]] == hm[a[i]])
            {
                matchCount++;
                if (matchCount == uCount && (i - s_i == b.length() - 1))
                {
                    result.push_back(s_i);
                    lhm[a[s_i]]--;
                    matchCount--;
                    s_i++;
                    while (hm[a[s_i]] == 0)
                    {
                        s_i++;
                    }
                }
            }
            else if (lhm[a[i]] > hm[a[i]])
            {
                lhm[a[i]]--;
                while (a[s_i] != a[i])
                {
                    if (lhm[a[s_i]] == hm[a[s_i]])
                    {
                        matchCount--;
                    }
                    lhm[a[s_i]]--;
                    s_i++;
                }
                s_i++;
                while (hm[a[s_i]] == 0)
                {
                    s_i++;
                }
            }

        }
    }
    return result;
}

bool compare(std::string a, std::string b)
{
    return a.length() < b.length();
}

bool isPathPossible(string &a, string &b, int i, int j, int availEdit)
{
    if (i == a.length() && j == b.length())
    {
        return availEdit == 0;
    }
    if (i == a.length())
    {
        return (j + 1 == b.length() && availEdit != 0);
    }
    if (a[i] == b[j])
    {
        return isPathPossible(a, b, i + 1, j + 1, availEdit);
    }
    else
    {
        if (availEdit == 0)
        {
            return false;
        }
        return isPathPossible(a, b, i, j + 1, availEdit - 1);
    }
}


int maxPath(vector<vector<int>>& mat, vector<int>& length, int vertex)
{
    if (length[vertex] != -1)
    {
        return length[vertex];
    }
    int maxLength = 0;
    for (int i = vertex; i < mat.size(); i++)
    {
        if (mat[vertex][i] != 0)
        {
            auto len = 1 + maxPath(mat, length, i);
            maxLength = (len > maxLength) ? len : maxLength;
        }
    }
    length[vertex] = maxLength;
    return maxLength;
}

int main()
{
    vector<string> vstr= { "abcd","dbqca" };
    std::sort(vstr.begin(), vstr.end(), compare);
    unordered_map<int, string> map;
    unordered_map<string, int> rmap;
    int n = -1;
    for (int i = 0; i < vstr.size(); i++)
    {        
        if (rmap.find(vstr[i]) == rmap.end())
        {
            n++;
            rmap[vstr[i]] = n;
            map[n] = vstr[i];
        }
    }
    vector<vector<int>> mat(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < vstr.size(); i++)
    {
        for (int j = i + 1; j < vstr.size(); j++)
        {
            if (vstr[i].length() == vstr[j].length() || (vstr[i].length() + 1 != vstr[j].length()))
            {
                continue;
            }
            auto ret = isPathPossible(vstr[i], vstr[j], 0, 0, 1);
            if (ret)
            {
                mat[rmap[vstr[i]]][rmap[vstr[j]]] = 1;
            }
        }
    }
    int maxLength = -1;
    std::vector<int> length(n + 1, -1);
    for (int i = 0; i <= n; i++)
    {
        if (length[i] == -1)
        {
            auto len = 1 + maxPath(mat, length, i);
            maxLength = (len > maxLength) ? len : maxLength;
        }
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
