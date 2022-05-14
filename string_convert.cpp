// string_convert.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int ret_no_of_step(char* str1, char* str2, int str1Index, int str2Index, int **dp)
{
    if (str1[str1Index] == 0 && str2[str2Index] == 0)
    {
        return 0;
    }
    if (dp[str1Index][str2Index] != -1)
    {
        return dp[str1Index][str2Index];
    }
    while (str1[str1Index] == str2[str2Index])
    {
        str1Index++;
        str2Index++;
        if (!str1[str1Index] || !str2[str2Index])
            break;
    }

    if (str1[str1Index] == 0 || str2[str2Index] == 0)
    {
        int steps = strlen(str1 + str1Index) - strlen(str2 + str2Index);
        (steps < 0) ? (steps *= -1) : (steps *= 1);
        return steps;
    }


    // Check with replacement
    int min_no_step = 1 + ret_no_of_step(str1, str2, str1Index + 1, str2Index + 1, dp);

    //Check with insertion
    int local_min_Steps = 1 + ret_no_of_step(str1, str2, str1Index, str2Index + 1, dp);
    if (local_min_Steps < min_no_step)
    {
        min_no_step = local_min_Steps;
    }

    //check with deletion
    local_min_Steps = 1 + ret_no_of_step(str1, str2, str1Index + 1, str2Index, dp);
    if (local_min_Steps < min_no_step)
    {
        min_no_step = local_min_Steps;
    }

    dp[str1Index][str2Index] = min_no_step;
    return min_no_step;
}

int longest_palindromic_subsequence(char* str, int strIndex, int endIndex, int** dp)
{
    if (strIndex == endIndex)
    {
        return 1;
    }
    else if (strIndex > endIndex)
    {
        return 0;
    }

    if (dp[strIndex][endIndex] != -1)
    {
        return dp[strIndex][endIndex];
    }

    int index = 0;
    while ((strIndex + index < endIndex - index) && (str[strIndex + index] == str[endIndex - index]))
    {
        index++;
    }
    int longest_len_palindrome = 0;
    if (index == 0)
    {
        longest_len_palindrome = (index * 2) + longest_palindromic_subsequence(str, strIndex + 1, endIndex - 1, dp);
    }
    else
    {
        longest_len_palindrome = (index * 2) + longest_palindromic_subsequence(str, strIndex + index, endIndex - index, dp);
    }

    int temp_palin = (index * 2) + longest_palindromic_subsequence(str, strIndex + index + 1, endIndex - index, dp);
    if (temp_palin > longest_len_palindrome)
    {
        longest_len_palindrome = temp_palin;
    }

    temp_palin = (index * 2) + longest_palindromic_subsequence(str, strIndex + index, endIndex - index - 1, dp);
    if (temp_palin > longest_len_palindrome)
    {
        longest_len_palindrome = temp_palin;
    }
    dp[strIndex][endIndex] = longest_len_palindrome;
    return longest_len_palindrome;
}

int main()
{
    char str1[100] = { "BBABCBCAB" };
    char str2[100] = { "saturday" };
    int** dp = nullptr;
    dp = new int* [strlen(str1 + 1)];
    for (int i = 0; i < strlen(str1) + 1; i++)
    {
        dp[i] = new int[strlen(str1) + 1];
        for (int j = 0; j < strlen(str1) + 1; j++)
        {
            dp[i][j] = -1;
        }
    }
   // int steps = ret_no_of_step(str1, str2, 0, 0, dp);
    int length_palin = longest_palindromic_subsequence(str1, 0, strlen(str1) - 1, dp);
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
