// in_to_post.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stack>
#include<string>

# define OPERATOR 0
# define OPERAND 1
# define NONE -1
using namespace std;

int check_char(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        return OPERAND;
    }
    else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return OPERATOR;
    }
    else return NONE;
}

int prec(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

string convert(string str)
{
    string lstr = "(";
    lstr += str + ")";
    int i = 0;
    string convstr = "";
    stack<char> uStack;
    bool prevOperand = false;
    int cOperator = 0;
    int cOperand = 0;
    while (i < lstr.length())
    {
        int ctype = check_char(lstr[i]);
        if (ctype == OPERAND)
        {
            convstr.append(1, lstr[i]);
            prevOperand = true;
            cOperand++;
            i++;
            continue;
        }
        else if (ctype == OPERATOR)
        {
            cOperator++;
            if (uStack.empty() || !prevOperand || cOperator > cOperand)
            {
                break;
            }
            char top = uStack.top();
            if(check_char(top) == OPERATOR && prec(lstr[i]) <= prec(top))
            { 
                while (!uStack.empty() && check_char(uStack.top()) == OPERATOR && prec(uStack.top()) >= prec(lstr[i]) )
                {
                    top = uStack.top();
                    uStack.pop();
                    convstr.append(1, top);
                }
            }
            uStack.push(lstr[i]);
            prevOperand = false;
        }
        else if (lstr[i] == '(')
        {
            prevOperand = true;
            uStack.push(lstr[i]);
        }
        else if (lstr[i] == ')')
        {
            if (uStack.empty())
            {
                break;
            }
            else
            {
                char top = uStack.top();
                while (!uStack.empty() && uStack.top() != '(')
                {
                    top = uStack.top();
                    uStack.pop();
                    convstr.append(1, top);
                }
                if (uStack.empty())
                {
                    break;
                }
                uStack.pop();
            }
            prevOperand = true;
        }
        else
        {
            break;
        }
        
        i++;
    }
    return convstr;
}

int main()
{
    string str = "a+b*(c-d)+e-f/g";
    auto ret = convert(str);
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
