// ktrans.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<algorithm>

class buystat
{
public : 
    int sell, buy, profit;
    bool operator==(const buystat& obj) const
    {
        return (buy == obj.buy && sell == obj.sell && profit == obj.profit);
    }
};


void find_max_profit(int arr[], int n)
{
    int i = 0;
    std::vector<buystat> bst;
    while (i < n)
    {
        int tempi = i + 1;
        while (tempi < n && arr[tempi] < arr[tempi - 1])
        {
            tempi++;
        }
        if (tempi == n)
        {
            break;
        }
        int buy = tempi - 1;
        while (tempi < n && arr[tempi] > arr[tempi - 1])
        {
            tempi++;
        }
        int sel;
        if (tempi == n)
        {
            sel = n - 1;
        }
        else
        {
            sel = tempi - 1;
        }
        buystat b;
        b.sell = arr[sel];
        b.buy = arr[buy];
        b.profit = arr[sel] - arr[buy];
        bst.push_back(b);
        i = tempi;
    }
    
    for (int i = 1; i < bst.size(); i++)
    {
        auto& prev = bst[i - 1];
        auto& curr = bst[i];
        if (curr.sell - prev.buy >= curr.profit + prev.profit)
        {
            prev.sell = curr.sell;
            curr = prev;
        }
    }
    bst.erase(std::unique(bst.begin(), bst.end()), bst.end());
    bst.erase(std::unique(bst.begin(), bst.end()), bst.end());
}

int main()
{
    int arr[] = {10, 22, 5, 75, 65, 80};
    find_max_profit(arr, sizeof(arr) / sizeof(arr[0]));
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
