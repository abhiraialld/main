// no_of_twos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


int count_twos(int n)
{
    if (n < 2)
    {
        return 0;
    }
    int n_factor = 10;
    int no_of_twos_full = 0;
    int no_of_twos_yet = 0;
    while ((n_factor/10) <= n)
    {
        
        auto digit = n % n_factor;
        auto highest_digit = digit / (n_factor / 10);
        if (digit < 2 || 0 == highest_digit)
        {
            /*do nothing*/
        }
        else if(digit < 9)
        {
            no_of_twos_yet += 1;
        }
        else
        {
            if (highest_digit == 2)
            {
                no_of_twos_yet += 2 * no_of_twos_full + (digit - (2 * n_factor / 10) + 1);
            }
            else if (highest_digit > 2)
            {
                no_of_twos_yet += highest_digit * no_of_twos_full + (n_factor / 10);
            }
            else
            {
                no_of_twos_yet += highest_digit * no_of_twos_full;
            }
        }
        no_of_twos_full = (no_of_twos_full * 10) + n_factor / 10;
        n_factor *= 10;
    }

    return no_of_twos_yet;
}

int main()
{
    int no_of_twos = count_twos(2223);
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
