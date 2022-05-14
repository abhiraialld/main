// longest_unique_string.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<algorithm>


int find_max_len(const char* ptr)
{
    char buf[26];
    memset(buf, -1, sizeof(buf));
    int i = 0, begin = -1, max_length = 0;
    while (i < strlen(ptr))
    {
        if (begin == -1)
        {
            begin = i;
        }
        else if (buf[ptr[i] - 'a'] != -1)
        {
            begin = buf[ptr[i] - 'a'] + 1;
        }
        if (i - begin + 1 > max_length)
        {
            max_length = i - begin + 1;
        }
        buf[ptr[i] - 'a'] = i;
        i++;
    }
    return max_length;
}

int maxArea(std::vector<int>& height) {
    int i = 0, j = height.size() - 1;
    int max_area = 0;
    while (i < j)
    {
        int min = height[i] < height[j] ? height[i] : height[j];
        if (min * (j - i) > max_area)
        {
            max_area = min * (j - i);
        }
        if (height[i] < height[j])
        {
            int k = i + 1;
            while (k < j && height[k] <= height[i])
            {
                k++;
            }
            i = k;
        }
        else if (height[i] > height[j])
        {
            int k = j - 1;
            while (k > i && height[k] <= height[j])
            {
                k--;
            }
            j = k;
        }
        else
        {
            i++;
            j--;
        }
    }
    return max_area;
}

void nextPermutation(std::vector<int>& nums) {
    int j = nums.size() - 1;
    int least = nums[j];
    j--;
    while (j > -1 && nums[j] > nums[j + 1])
    {
        if (nums[j] < least)
        {
            least = j;
        }
        j--;
    }
    if (-1 == j)
    {
        std::reverse(nums.begin(), nums.end());
    }
    else
    {
        {
            int k = j + 1;
            int least_greater = j + 1;
            while (k < nums.size())
            {
                if (nums[k] > nums[j] && nums[k] < nums[least_greater])
                {
                    least_greater = k;
                }
                k++;
            }
            auto temp = nums[least_greater];
            nums[least_greater] = nums[j];
            nums[j] = temp;
            std::sort(nums.begin() + (j + 1), nums.end());
        }
    }
}

int main()
{
    
    const char* str = "pwwkew";
    std::vector<int> vec = { 4,5,8,9,7 };
    nextPermutation(vec);
    auto area = maxArea(vec);
    auto leb = find_max_len(str);
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
