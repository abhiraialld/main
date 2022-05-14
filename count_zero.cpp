// count_zero.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<algorithm>

int count_zero(int arr[], int N)
{
    if (arr[0] == 0 && arr[N - 1] == 0)
        return N;
    else if (arr[0] == 1 && arr[N - 1] == 1)
        return 0;
    int left = 0;
    int right = N - 1;
    int mid = 0;
    while (left <= right)
    {
        mid = (right - left) / 2 + left;
        if (arr[mid] == 0 && arr[mid - 1] == 1)
            break;
        else if (arr[mid] == 0)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return (N - mid);
}

int Find_Maximum(int arr[], int N)
{
    if (N == 1)
    {
        return arr[0];
    }
    if (arr[0] > arr[1])
        return arr[0];
    else if (arr[N - 2] < arr[N - 1])
        return arr[N - 1];
    int left = 0;
    int right = N - 1;
    int mid = 0;
    while (left <= right)
    {
        mid = (right - left) / 2 + left;
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            break;
        }
        else if (arr[mid + 1] < arr[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return arr[mid];
}

int triplet_count(int arr[], int N)
{
    if (N < 3)
    {
        return 0;
    }
    int nTripletCount = 0;
    int index = 0;

    for (; index < N; index++)
    {
        int left = 0;
        int right = N - 1;
        int req_sum = arr[index] * -1;
        while (left < right)
        {
            if (left == index)
            {
                left++;
                continue;
            }
            if (right == index)
            {
                right--;
                continue;
            }
            if (arr[left] + arr[right] == req_sum)
            {
                if (arr[left] == arr[right])
                {
                    nTripletCount += (right - left) * (right - left - 1) / 2;
                    break;
                }
                else
                {
                    int nFirstElementCount = 0;
                    int nTempLeftIndex = left;
                    while (arr[left] == arr[nTempLeftIndex])
                    {
                        nFirstElementCount++;
                        nTempLeftIndex++;
                    }
                    int nSecondElementCount = 0;
                    int nTempRightIndex = right;
                    while (arr[right] == arr[nTempRightIndex])
                    {
                        nSecondElementCount++;
                        nTempRightIndex--;
                    }
                    nTripletCount += nSecondElementCount * nFirstElementCount;
                    left = nTempLeftIndex;
                    right = nTempRightIndex;
                }
            }
            else
            {
                left++;
                right--;
            }
        }
    }
    return nTripletCount;
}

bool DoesSubSetExist(int arr[], int N, int sum)
{
    if (N == 0 || (N == 1 && arr[N - 1] != sum))
    {
        return false;
    }
    else if ((N == 1 && arr[0] == sum) || arr[N - 1] == sum)
    {
        return true;
    }
    int nLeftIndex = 0;
    int nRightIndex = 1;
    int nLocalSum = arr[nLeftIndex] + arr[nRightIndex];
    while (true)
    {
        if (nLocalSum == sum)
        {
            return true;
        }
        if (nRightIndex == N - 1 && (sum > nLocalSum || nRightIndex == nLeftIndex))
        {
            break;
        }
        if (nRightIndex == nLeftIndex && nLocalSum > sum)
        {
            nLocalSum = 0;
            nLeftIndex = -1;
        }
        if (nLocalSum < sum)
        {
            nRightIndex++;
            nLocalSum += arr[nRightIndex];
            if (nLeftIndex == -1)
            {
                nLeftIndex = nRightIndex;
            }
        }
        else
        {
            nLocalSum -= arr[nLeftIndex];
            nLeftIndex++;
        }
    }
    return false;
}


int main()
{
    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
    int retVal = DoesSubSetExist(arr, sizeof(arr) / sizeof(arr[0]), 15);
    std::cout << " : " << retVal;
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
