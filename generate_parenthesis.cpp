// generate_parenthesis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>

void print_parenthesis(int leftCount, int rightCount, int N, std::string& str)
{
    if (leftCount + rightCount == 2*N)
    {
        std::cout << "\n" << str;
        return;
    }
    if (leftCount < N)
    {
        std::string tmpStr = str;
        tmpStr.append(1, '(');
        print_parenthesis(leftCount + 1, rightCount, N, tmpStr);
    }
    if (rightCount < leftCount)
    {
        std::string tmpStr = str;
        tmpStr.append(1, ')');
        print_parenthesis(leftCount, rightCount + 1, N, tmpStr);
    }
}

int main()
{
    std::string str("(");
    print_parenthesis(1, 0, 3, str);
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
