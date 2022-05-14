// kthperm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<string>


int editdistance(std::string str, std::string astr, int i, int j, std::vector<std::vector<int>>& dp)
{
    if (i == str.length() && j == str.length())
    {
        return 0;
    }
    else if (j == astr.length())
    {
        return str.length() - i;
    }
    else if (i == str.length())
    {
        return astr.length() - j;
    }
    else if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (str[i] == astr[j])
    {
        return editdistance(str, astr, i + 1, j + 1, dp);
    }

    int min = std::numeric_limits<int>::max();
    auto temp = 1 + editdistance(str, astr, i, j + 1, dp);
    min = temp < min ? temp : min;

    temp = 1 + editdistance(str, astr, i + 1, j, dp);
    min = temp < min ? temp : min;

    temp = 1 + editdistance(str, astr, i + 1, j + 1, dp);
    min = temp < min ? temp : min;
    dp[i][j] = min;

    return min;
}


void printallpermutation(std::vector<int> arr, int index)
{
    if (index == arr.size())
    {
        std::cout << "\n";
        for (int i = 0; i < arr.size(); i++)
        {
            std::cout << arr[i];
        }
    }
    for (int i = index; i < arr.size(); i++)
    {
        if (i != index && arr[i] == arr[index])
            continue;
        auto temp = arr[index];
        arr[index] = arr[i];
        arr[i] = temp;
        printallpermutation(arr, index + 1);
        temp = arr[index];
        arr[index] = arr[i];
        arr[i] = temp;
    }
}


int main()
{

    std::string str = "sunday";
    std::string astr = "saturday";
    std::vector<std::vector<int>> dp(str.length(), std::vector<int>());
    for (int i = 0; i < dp.size(); i++)
    {
        dp[i].insert(std::begin(dp[i]), astr.length(), -1);
    }
    auto min = editdistance(str, astr, 0, 0, dp);
    /*int n = 5;
    std::vector<int> fac;
    std::vector<int> arr = { 1,1,2};
    printallpermutation(arr, 0);*/
    //std::vector<int> brr = arr;
    //fac.insert(fac.begin(), n + 1, 1);
    //for (int i = 1; i <= n; i++)
    //{
    //    fac[i] = fac[i - 1] * i;
    //}
    //int k = 39;
    //int i = n;
    //int num = 0;
    //while (i > 1)
    //{
    //    int no = (k - 1) / fac[i - 1];
    //    num *= 10;
    //    num += brr[no];
    //    k -= no * fac[i - 1];
    //    brr.erase(std::remove(brr.begin(), brr.end(), brr[no]));
    //    i--;
    //}
    //num *= 10;
    //num += brr[0];
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
