// strobogrammatic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<vector>
#include<list>
#include<queue>
#include<set>
#include<unordered_map>
#include<unordered_set>

using namespace std;
string always = "012";
string conditional = "69";

class node
{
public :
    int i, j;
    int sum;
    node(int a, int b)
    {
        i = a;
        j = b;
        sum = a + b;
    }
    bool operator<(const node& obj) const
    {
        return sum < obj.sum;
    }
    bool operator>(const node& obj) const
    {
        return sum > obj.sum;
    }
    bool operator==(const node& obj) const
    {
        return (i == obj.i) && (j == obj.j);
    }
};

template<>
class hash<node>
{
public:
    std::size_t operator()(const node& obj) const
    {
        return ((hash<int>()(obj.i) << 3) ^ (hash<int>()(obj.j) >> 2));
    }
};


int divide_min_continuos(std::vector<int>& vec, int i, int sm, vector<int>& set)
{
    if (i == vec.size())
    {
        if (sm != set.size() - 1)
        {
            return std::numeric_limits<int>::max();
        }
        auto high = std::numeric_limits<int>::min();
        for (auto setsum : set)
        {
            if (setsum > high)
            {
                high = setsum;
            }
        }
        return high;
    }
    int min = std::numeric_limits<int>::max();
    vector<int> temp = set;
    temp[sm] += vec[i];
    auto ret = divide_min_continuos(vec, i + 1, sm, temp);
    min = (ret < min) ? ret : min;

    if (i > sm && sm < set.size() - 1)
    {
        temp = set;
        temp[sm + 1] += vec[i];
        ret = divide_min_continuos(vec, i + 1, sm + 1, temp);
        if (ret < min)
        {
            min = ret;
        }
    }
    return min;
}

void BFS(vector<list<int>>& adj)
{
    queue<int> qu;
    std::vector<bool> visited(adj.size(), false);
    
    qu.push(0);
    while (!qu.empty())
    {
        auto vert = qu.front();
        qu.pop();
        visited[vert] = true;
        std::cout << "\t" << vert;
        for (auto tvert : adj[vert])
        {
            if (!visited[tvert])
            {
                visited[tvert] = true;
                qu.push(tvert);
            }
        }
    }
}


void DFS(int source, vector<list<int>>& adj, vector<bool>& visited)
{
    std::cout << "\t" << source;
    visited[source] = true;
    for (auto tvert : adj[source])
    {
        if (!visited[tvert])
        {
            visited[tvert] = true;
            DFS(tvert, adj, visited);
        }
    }
}


int max_profit_k(vector<int> prices, int n, int k)
{
    if (k <= 0 || n <= 1)
    {
        return 0;
    }
    int maxprofit = max_profit_k(prices, n - 1, k);
    for (int i = n - 2; i > -1; i--)
    {
        int profit = max_profit_k(prices, i, k - 1);
        int min = std::numeric_limits<int>::max();
        for (int j = i; j < n - 1; j++)
        {
            if (prices[j] < min)
            {
                min = prices[j];
            }
        }
        if (min < prices[n - 1])
        {
            profit += prices[n - 1] - min;
        }
        if (profit > maxprofit)
        {
            maxprofit = profit;
        }
    }
    std::cout << "\n" << "fun(" << n << ", "<< k << ") : " << maxprofit;
    return maxprofit;
}


int find_max_profit_buy_first(int index, int k, vector<int>& prices)
{
    if (k <= 0 || index >= prices.size() - 1)
    {
        return 0;
    }
    auto maxprofit = find_max_profit_buy_first(index + 1, k, prices);
    auto max = prices[index];
    for (int i = index + 2; i <= prices.size(); i++)
    {
        auto profit = find_max_profit_buy_first(i, k - 1, prices);
        max = prices[i - 1] > max ? prices[i - 1] : max;
        /*for (int j = index + 1; j < i; j++)
        {
            if (prices[j] > max)
            {
                max = prices[j];
            }
        }*/
        profit += (max - prices[index]);
        maxprofit = (profit > maxprofit) ? profit : maxprofit;
    }
    return maxprofit;
}



int no_of_coins(vector<int>& vec, int amount, vector<int>& dp)
{
    if (0 == amount)
    {
        return 0;
    }
    if (-1 != dp[amount])
    {
        return dp[amount];
    }
    int min = -1;
    for (int i = 0; i < vec.size(); i++)
    {
        if (amount - vec[i] >= 0)
        {
            auto lmax = no_of_coins(vec, amount - vec[i], dp);
            if (-1 == lmax)
            {
                continue;
            }
            else
            {
                min = (min == -1 || lmax + 1 < min) ? lmax + 1 : min;
            }
        }
    }
    dp[amount] = min;
    return min;
}

int max_prod_subarray(vector<int> vec, int ind)
{
    if (ind >= vec.size())
    {
        return 0;
    }
    auto max_prod = max_prod_subarray(vec, ind + 1);
    auto elem = vec[ind];
    for (int i = ind + 1; i < vec.size(); i++)
    {
        elem *= vec[i];
        max_prod = (elem > max_prod) ? elem : max_prod;
        auto temp = max_prod_subarray(vec, i + 1);
        max_prod = (temp > max_prod) ? temp : max_prod;
    }
    return max_prod;
}

int GetMedian(int arr[], int n)
{
    auto mid = (n - 1) / 2;
    if (n % 2 == 0)
    {
        return (arr[mid] + arr[mid + 1])/2;
    }
    return arr[mid];
}


int calculateMedian(int vec1[], int vec2[], int e1, int e2)
{
    if (e1 == 1 && e2 == 1)
    {
        return (vec1[0] + vec2[0]) / 2;
    }
    else if ((e1 == 1 && e2 == 2) || (e1 == 2 && e2 == 1))
    {
        auto& large = (e2 > e1) ? vec2 : vec1;
        auto& small = (e2 > e1) ? vec1 : vec2;
        if (small[0] > large[0])
        {
            return (small[0] > large[1] ? large[1] : small[0]);
        }
        else
        {
            return large[0];
        }
    }
    else if (e1 == 2 && e2 == 2)
    {
        auto a = (vec1[0] > vec2[0]) ? vec1[0] : vec2[0];
        auto b = (vec1[1] > vec2[1]) ? vec2[1] : vec1[1];
        return (a + b) / 2;
    }
    int m1 = GetMedian(vec1, e1);
    int m2 = GetMedian(vec2, e2);

    if (m1 < m2)
    {
        return calculateMedian(vec1 + (e1 - 1) / 2, vec2, (e1 / 2) + 1, (e2) / 2 + 1);
        /*if (e2 % 2 == 0)
        {
            return calculateMedian(vec1 + (e1 - 1) / 2, vec2, e1/2 + 1 , (e2/2) + 1);
        }
        else
        {
            return calculateMedian(vec1 + (e1 - 1) / 2, vec2, e1/2 + 1 , (e2) / 2);
        }*/
    }
    else if (m2 > m1)
    {
        return calculateMedian(vec1, vec2 + (e2 - 1) / 2, (e1 / 2) + 1, e2 / 2 + 1);
        //if (e1 % 2 == 0)
        //{
        //    return calculateMedian(vec1, vec2 + (e2 - 1)/2, (e1 / 2) + 1, e2/2 + 1);
        //}
        //else
        //{
        //    return calculateMedian(vec1, vec2 + (e2 - 1)/2, (e1) / 2 + 1, e2 - (e2 - 1) / 2 );
        //}
    }
    else
    {
        return m1;
    }
}

void minLength(int found, int n, int k, string& str, string& resStr, unordered_set<string> &hs)
{
    if (n * k * n + 1 <= str.length())
    {
        return;
    }
    if (str.length() >= n)
    {
        string sub = str.substr(str.length() - n);
        std::cout << "\nBefore fun : " << str << " found : " << found;
        if (hs.find(sub) == hs.end())
        {
            found++;
            if (hs.empty())
            {
                std::cout << "\n Map is empty \n";
            }
            for (auto i : hs)
            {
                std::cout << "\t" << i;
            }
            std::cout << endl;
            hs.insert(sub);
            std::cout << "\n fun : " << str << " found : " << found;
        }
        
        if (found == n * k)
        {
            resStr = (resStr == "" || str.length() < resStr.length()) ? str : resStr;
            return;
        }
    }

    for (int i = 0; i < k; i++)
    {
        string tstr = str + std::to_string(i);
        unordered_set<string> ths = hs;
        minLength(found, n, k, tstr, resStr, ths);
    }
    return ;
}

class corrd
{
public :
    int i, j;
};

int no_of_pattern(int si, int sj, vector<vector<bool>>& mat, int length, int m, int n)
{
    int found = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (mat[i][j])
                continue;
            auto xdiff = (i - si);
            auto absxdiff = xdiff;
            absxdiff *= absxdiff < 0 ? -1 : 1;
            auto yDiff = (j - sj);
            auto absydiff = yDiff;
            absydiff *= absydiff < 0 ? -1 : 1;
            if ((absxdiff == 2 && yDiff == 0) || (xdiff == 0 && absydiff == 2) || (absxdiff == 2 && absydiff == 2))
            {
                if (!mat[i - (xdiff / 2)][j - (yDiff / 2)])
                {
                    continue;
                }
            }
            if (length == n)
            {
                continue;
            }
            else if (length <= n - 1 && length >= m - 1)
            {
                std::cout << "(" << si << "," << sj << ") : (" << i << "," << j << ")\n";
                found++;
            }
            mat[i][j] = true;
            found += (no_of_pattern( i, j, mat, length + 1,m,n));
            mat[i][j] = false;
        }
    }
    return found;
}

int binary_search(int arr[], int n, int data, bool searchBegin)
{
    if (n == 0)
        return -1;

    int left = 0, right = n - 1;
    while (left <= right)
    {
        auto mid = left + (right - left) / 2;
        if (searchBegin)
        {
            if (arr[mid] == data && arr[mid - 1] != arr[mid])
            {
                return mid;
            }
            else if (arr[mid] < data)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        else
        {
            if (arr[mid] == data && arr[mid + 1] != arr[mid])
            {
                return mid;
            }
            else if (arr[mid] > data)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
    }
    return -1;
}

void search_begin_end(int arr[], int n, int data, int& left, int &right)
{
    if (arr[0] == data)
    {
        left = 0;
    }
    else
    {
        left = binary_search(arr + 1, n - 1, data, true) + 1;
    }
    if (arr[n - 1] == data)
    {
        right = n - 1;
    }
    else
    {
        right = binary_search(arr, n - 1, data, false);
    }
}

struct range
{
    int begin, end;
    range(int i, int j)
    {
        begin = i;
        end = j;
    }
};

vector<range> mergeInterval(vector<range>& interv)
{
    vector<range> retInter;
    if (interv.empty())
    {
        return retInter;
    }
    retInter.push_back(interv[0]);
    int i = 1, j = 0;
    while (i < interv.size())
    {
        if (interv[i].begin <= retInter[j].end)
        {
            retInter[j].end = interv[i].end;
        }
        else
        {
            retInter.push_back(interv[i]);
            j++;
        }
        i++;
    }
    return retInter;
}


bool canConvert(std::string &source, std::string& dest)
{
    if (source == dest)
    {
        return true;
    }

    if (source.length() != dest.length())
    {
        return false;
    }
    bool ret = false;
    auto pos = source.find("XL");
    while (pos != std::string::npos && !ret)
    {
        //auto temp = source;
        source.replace(pos, 2, "LX");
        ret = canConvert(source, dest);
        source.replace(pos, 2, "XL");
        pos += 2;
        pos = source.find("XL", pos);
    }

    pos = source.find("RX");
    while (pos != std::string::npos && !ret)
    {
        source.replace(pos, 2, "XR");
        ret = canConvert(source, dest);
        source.replace(pos, 2, "RX");
        pos += 2;
        pos = source.find("RX", pos);
    }
    return ret;
}


float min_amnt(int ind, vector<float>& q, vector<float>& w, int k, float ratio)
{
    if (k == 0)
        return 0;
    if (ind == w.size())
    {
        return std::numeric_limits<float>::max();
    }
    auto min = min_amnt(ind + 1, q, w, k, ratio);
    float amount = 0;
    float newratio = ratio;
    if (newratio == 0)
    {
        amount = w[ind];
        newratio = w[ind] / q[ind];
    }
    else
    {
        amount = ratio * q[ind];
    }
    if (amount >= w[ind])
    {
        auto ret = amount + min_amnt(ind + 1, q, w, k - 1, newratio);
        min = (ret < min) ? (ret) : min;
    }
    return min;
}

bool checkAnagram(string str1, string str2)
{
    unordered_map<char, int> umap;
    for (int i = 0; i < str1.size(); i++)
    {
        umap[str1[i]]++;
    }
    int found = 0;
    for (int i = 0; i < str1.size(); i++)
    {
        if (umap.find(str2[i]) == umap.end())
            return false;
        umap[str2[i]]--;
        if (umap[str2[i]] == 0)
        {
            found++;
        }
        else if (umap[str2[i]] < 0)
        {
            return false;
        }
    }
    return (found == umap.size());
}


int fun(int ind, int k, vector<int>& arr)
{
    if (ind == arr.size() || k ==0)
    {
        return std::numeric_limits<int>::min();
    }
    int min_largest = std::numeric_limits<int>::max();
    int sum = 0;
    //if (k == 1)
    //{
    //    for (int i = ind; i < arr.size() - k + 1; i++)
    //    {
    //        sum += arr[i];
    //    }
    //    return sum;
    //}
    for (int i = ind; i < arr.size() - k + 1; i++)
    {
        sum += arr[i];
        auto temp = fun(i + 1, k - 1, arr);
        temp = sum > temp ? sum: temp;
        if (k > 1)
        {
            min_largest = temp < min_largest ? temp : min_largest;
        }
    }
    if (k == 1)
    {
        min_largest = sum;
    }
    return min_largest;
}


bool length_palindrome(int i, int j, string str, int& length)
{
    if (i == j)
    {
        length += 1;
        return true;
    }
    if (i + 1 == j)
    {
        if (str[i] == str[j])
        {
            length += 2;
            return true;
        }
        else
        {
            return false;
        }
    }

    if (str[i] == str[j])
    {
        length += 2;
        auto ret = length_palindrome(i + 1, j - 1, str, length);
        if (ret == true)
        {
            return true;
        }
    }
    int max_length = 0;
    length_palindrome(i, j - 1, str, max_length);

    int ret = 0;
    length_palindrome(i + 1, j, str, ret);
    max_length = (ret > max_length) ? ret : max_length;

    length = max_length;
    return false;
}


int nos(int ind, string str)
{
    if (ind == str.length() - 1)
    {
        return 1;
    }
    int numbers = 0;
    if (str[ind] > str[ind + 1])
    {
        numbers++;
    }
    numbers += nos(ind + 1, str);
    return numbers;
}

string derange(string& str)
{
    if (str.length() == 0)
    {
        return "";
    }
    priority_queue<char, vector<char>, std::greater<char>> pq;
    string regstr;
    for (int i = 0; i < str.length(); i++)
    {
        pq.push(str[i]);
    }
    int i = 0;
    while (!pq.empty())
    {
        auto ch = pq.top();
        pq.pop();
        if (ch != str[i] || i == str.length() - 1)
        {
            regstr += ch;
        }
        else
        {
            auto newch = pq.top();
            pq.pop();
            pq.push(ch);
            regstr += newch;
        }
        i++;
    }
    if (str[str.length() - 1] == regstr[str.length() - 1])
    {
        regstr[str.length() - 1] = regstr[str.length() - 2];
        regstr[str.length() - 2] = str[str.length() - 1];
    }
    return regstr;
}

void storesum(priority_queue<int>& maxh1, priority_queue<int>& maxh2, int k, priority_queue<int>& sum)
{
    if (0 == k)
    {
        return;
    }
    auto max1 = maxh1.top();
    auto max2 = maxh2.top();
    sum.push(max1 + max2);
    //sum[k - 1] = (max1 + max2) > sum[k - 1] ? max1 + max2 : sum[k - 1];
    maxh1.pop();
    storesum(maxh1, maxh2, k - 1, sum);
    maxh1.push(max1);
    maxh2.pop();
    storesum(maxh1, maxh2, k - 1, sum);
    maxh2.push(max2);
}


void KMaxCombinations(vector<int>& A,
    vector<int>& B, int K)
{
    // sort both arrays A and B
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int N = A.size();

    // Max heap which contains tuple of the format
    // (sum, (i, j)) i and j are the indices
    // of the elements from array A
    // and array B which make up the sum.
    priority_queue<pair<int, pair<int, int> > > pq;

    // my_set is used to store the indices of
    // the  pair(i, j) we use my_set to make sure
    // the indices doe not repeat inside max heap.
    set<pair<int, int> > my_set;

    // initialize the heap with the maximum sum
    // combination ie (A[N - 1] + B[N - 1])
    // and also push indices (N - 1, N - 1) along
    // with sum.
    pq.push(make_pair(A[N - 1] + B[N - 1],
        make_pair(N - 1, N - 1)));

    my_set.insert(make_pair(N - 1, N - 1));

    // iterate upto K
    for (int count = 0; count < K; count++)
    {
        // tuple format (sum, (i, j)).
        pair<int, pair<int, int> > temp = pq.top();
        pq.pop();

        cout << temp.first << endl;

        int i = temp.second.first;
        int j = temp.second.second;

        int sum = A[i - 1] + B[j];

        // insert (A[i - 1] + B[j], (i - 1, j))
        // into max heap.
        pair<int, int> temp1 = make_pair(i - 1, j);

        // insert only if the pair (i - 1, j) is
        // not already present inside the map i.e.
        // no repeating pair should be present inside
        // the heap.
        if (my_set.find(temp1) == my_set.end())
        {
            pq.push(make_pair(sum, temp1));
            my_set.insert(temp1);
        }

        // insert (A[i] + B[j - 1], (i, j - 1))
        // into max heap.
        sum = A[i] + B[j - 1];
        temp1 = make_pair(i, j - 1);

        // insert only if the pair (i, j - 1)
        // is not present inside the heap.
        if (my_set.find(temp1) == my_set.end())
        {
            pq.push(make_pair(sum, temp1));
            my_set.insert(temp1);
        }
    }
}

vector<int> maxkSum(vector<int>& veca, vector<int>& vecb, int k)
{
    std::priority_queue<int> maxh1;
    std::priority_queue<int> maxh2;

    for (auto a : veca)
    {
        maxh1.push(a);
    }

    for (auto b : vecb)
    {
        maxh2.push(b);
    }

    std::priority_queue<int> sum;
    storesum(maxh1, maxh2, k, sum);
    
    std::vector<int> result;
    int i = 0;
    while (!sum.empty() && i < k)
    {
        result.push_back(sum.top());
        sum.pop();
        i++;
    }

    return result;
}



//template<>
//class hash<std::pair<int, int>>
//{
//    size_t operator()(const std::pair<int,int>& a) 
//    {
//        return (hash<int>()(a.first) >> 2) ^ (hash<int>()(a.second) >> 2);
//    }
//};


int balance_operations(string str)
{
    int i = 0;
    int openCnt = 0, closedCount = 0;
    int operation_count = 0;
    int j = -1;
    while (i < str.length())
    {
        if (str[i] == '(')
        {
            openCnt++;
        }
        else if (str[i] == ')')
        {
            closedCount++;
        }
        if (closedCount > openCnt)
        {
            j = (j == -1) ? i : j;
            do
            {
                j++;
            } while (j < str.length() && str[j] != '(');
            operation_count += (j - i);
            i += 1;
            openCnt++;
        }
        i++;
    }
    return operation_count;
}

int mediansingle(int arr[], int n)
{
    if (n & 1)
    {
        return arr[(n - 1) / 2];
    }
    auto mid = (n - 1) / 2;
    return (arr[mid] + arr[mid + 1]) / 2;
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int max(int a, int b)
{
    return (a > b ? a : b);
}

int MO2(int a, int b)
{
    return (a + b) / 2;
}

int MO3(int a, int b, int c)
{
    auto sum = a + b + c;
    auto nmax = max(a, max(b, c));
    auto nmin = min(a, min(b, c));
    return (sum - nmax - nmin);
}

int MO4(int a, int b, int c, int d)
{
    auto sum = a + b + c +d;
    auto nmax = max(a, max(b, max(c, d)));
    auto nmin = min(a, min(b, min(c, d)));
    return (sum - nmin - nmax) / 2;
}



int GetMedian(int arr[], int brr[], int n, int m)
{
    if (n == 0)
    {
        return mediansingle(brr, m);
    }
    if (n == 1)
    {
        if (m == 1)
        {
            return MO2(arr[0], brr[0]);
        }
        auto mid = (m - 1) / 2;
        if (m & 1)
        {
            return MO4(brr[mid - 1], brr[mid], brr[mid + 1], arr[0]);
        }
        return MO3(brr[mid], brr[mid + 1], arr[0]);
    }
    if (n == 2)
    {
        if (m == 2)
        {
            return MO4(arr[0], arr[1], brr[0], brr[1]);
        }
        auto mid = (m - 1) / 2;
        if (m & 1)
        {
            return MO3(brr[mid], max(brr[mid - 1], arr[0]), min(brr[mid + 1], arr[1]));
        }
        return MO4(brr[mid], brr[mid + 1], max(brr[mid - 1], arr[0]), min(brr[mid + 2], arr[1]));
    }
    auto mid1 = (n - 1) / 2;
    auto mid2 = (m - 1) / 2;
    if (arr[mid1] <= brr[mid2])
    {
        return GetMedian(arr + mid1, brr, n / 2 + 1, m - mid1);
    }
    return GetMedian(arr, brr + mid1, n / 2 + 1, m - mid1);
}

int calculateMedian(int arr[], int n, int brr[], int m)
{
    if (n > m)
    {
        return GetMedian(brr, arr, m, n);
    }
    return GetMedian(arr, brr, n, m);
}


void altrotatematrix(vector<vector<int>>& a, int si, int n)
{
    if (n <= 1)
    {
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        auto temp = a[si][si + i];
        auto b = si + n - 1;
        auto c = si + n - 1 - i;
        a[si][si + i] = a[si + i][si + n - 1];
        a[si + i][si + n - 1] = a[si + n - 1][si + n - 1 - i];
        a[si + n - 1][si + n - 1 - i] = a[si + n - 1 - i][si];
        a[si + n - 1 - i][si] = temp;
    }
    altrotatematrix(a, si + 1, n - 2);
    return;
}

void rotatematrix(vector<vector<int>>& a, int si, int n)
{
    if (n <= 1)
    {
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        auto temp = a[si + i][si + n - 1];
        auto b = si + n - 1;
        auto c = si + n - 1 - i;
        a[si + i][si + n - 1] = a[si][si + i];
        a[si][si + i] = a[si + n - 1 - i][si];
        a[si + n - 1 - i][si] = a[si + n - 1][si + n - 1 - i];
        a[si + n - 1][si + n - 1 - i] = temp;
    }
    rotatematrix(a, si + 1, n - 2);
    return;
}


vector<int> parent;
std::vector<int> irank;

int Find(int i)
{
    if (-1 == parent[i])
    {
        return i;
    }
        auto par = Find(parent[i]);
        parent[i] = par;
        return par;

}

void Union(int i, int j)
{
    auto ipar = Find(i);
    auto jpar = Find(j);

    if (ipar == jpar)
    {
        return;
    }
    if (irank[ipar] > irank[jpar])
    {
        parent[jpar] = ipar;
    }
    else if (irank[ipar] < irank[jpar])
    {
        parent[ipar] = jpar;
    }
    else
    {
        parent[jpar] = ipar;
        irank[ipar]++;
    }

}

bool isPath(int i, int j, int mat[][4], int visited[][4])
{
    if (!((i > -1 && i < 4) && (j > -1 && j < 4)))
    {
        return false;
    }

    if (i == j && i == 3)
    {
        return true;
    }

    if (mat[i][j] == 0)
        return false;

    if (visited[i][j] != -1)
    {
        return (visited[i][j] == 0) ? false : true;
    }


    visited[i][j] = 0;
    bool ret = isPath(i, j + 1, mat, visited);
    ret = ret || isPath(i + 1, j, mat, visited);
    ret = ret || isPath(i - 1, j, mat, visited);
    ret = ret || isPath(i , j - 1, mat, visited);
    visited[i][j] = ret;
    return ret;
}

int countPaths(int i, int j, int n, int m, int visited[][3])
{
    if (i >= n || j >= m)
    {
        return 0;
    }

    if (i == n - 1 && j == m - 1)
    {
        return 1;
    }

    if (visited[i][j] != -1)
    {
        return visited[i][j];
    }
    int noofpaths = countPaths(i + 1, j, n, m, visited);
    noofpaths += countPaths(i , j + 1, n, m, visited);

    visited[i][j] = noofpaths;
    return noofpaths;

}

vector<int> vecx = {-1, 1, -2, -2, 2, 2, -1, 1};
vector<int> vecy = { 2, 2, -1, 1 ,-1, 1,-2, -2 };

bool fillKnightTour(int i, int j, int move, vector<vector<int>>& mat, vector<int>& x, vector<int>& y)
{
    int n = mat[0].size();

    if (!((i > -1 && i < n) && (j > -1 && j < n)))
    {
        return false;
    }
    if (mat[i][j] != -1)
    {
        return false;
    }

    if (move == mat[0].size() * mat[0].size())
    {
        mat[i][j] = move;
        return true;
    }
    std::cout << "\nfun( " << i << ", " << j << ") : " << move;
    mat[i][j] = move;
    for (int counter = 0; counter < vecx.size(); counter++)
    {
        auto newi = i + vecx[counter];
        auto newj = j + vecy[counter];

        if (fillKnightTour(newi, newj, move + 1, mat, vecx, vecy))
        {
            return true;
        }
    }
    mat[i][j] = -1;
    return false;
}

int find_maximum(int arr[], int n)
{
    auto left = 0;
    auto right = n - 1;
    while (left <= right)
    {
        auto mid = left + (right - left) / 2;
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        else if (arr[mid + 1] > arr[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}


bool canbeSorted(int a[], int n)
{
    int i = 0;
    while (i < n - 1 && a[i + 1] >= a[i])
    {
        i++;
    }
    if (i == n - 1)
    {
        return true;
    }
    auto j = i;
    while (j > 0 && a[j - 1] == a[j])
    {
        j--;
    }
    auto prev = j - 1;
    j = i + 1;
    while (j < n - 1 && a[j + 1] <= a[j])
    {
        j++;
    }
    if (prev == -1 && j == n - 1)
    {
        return true;
    }
    if (prev == -1 || a[j] >= a[prev])
    {
        while (j < n - 1)
        {
            if (a[j + 1] < a[j])
            {
                return false;
            }
            j++;
        }
        return true;
    }
    return false;
}

int find_rotation(int a[], int n)
{
    if (n == 0)
        return -1;
    if (n == 1) return n;
    if (n == 2)
    {
        return (a[0] <= a[1]) ? 0 : 1;
    }

    if (a[0] > a[1])
    {
        return 1;
    }
    else if (a[n - 1] < a[n - 2])
    {
        return n - 1;
    }
    auto left = 1;
    auto right = n - 2;
    while (left <= right)
    {
        auto mid = left + (right - left) / 2;
        if (a[mid] < a[mid - 1] && a[mid + 1] > a[mid])
        {
            return mid;
        }
        else if (a[mid] < a[right])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}

bool sum_pair_rotated(int a[], int n, int sum)
{
    auto left = find_rotation(a, n);
    auto right = (left - 1 + n) % n;
    while (a[left] < a[right])
    {
        auto lsum = a[left] + a[right];
        if (lsum == sum)
        {
            return true;
        }
        else if (lsum < sum)
        {
            left = (left + 1) % n;
        }
        else
        {
            right = (right - 1 + n) % n;
        }
    }
    return false;;
}


int searchRot(int arr[], int n, int elem)
{
    if (0 == n)
    {
        return -1;
    }
    auto left = 0;
    auto right = n - 1;
    while (left <= right)
    {
        auto mid = left + (right - left) / 2;
        if (elem == arr[mid])
        {
            return mid;
        }
        else if (arr[mid] < arr[right])
        {
            if (elem > arr[mid] && elem <= arr[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        else
        {
            if (arr[left] <= elem && elem < arr[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
    }
    return -1;
}

int main()
{

    int arr[] = { 38, 9, 10, 11, 15, 26 };
    auto ret = searchRot(arr, sizeof(arr) / sizeof(arr[0]), 26);

    auto mid = find_rotation(arr, sizeof(arr) / sizeof(arr[0]));
    //parent.assign(10, -1);
    //irank.assign(10, 0);

    //Union(0, 3);
    //Union(2, 8);
    //Union(4, 3);
    //Union(4, 7);
    //Union(5, 2);
    //Union(1, 6);
    //Union(0, 7);


    //vector<vector<int>> mat;
    //mat.assign(5, vector<int>());
    //for (int i = 0; i < 5; i++)
    //{
    //    mat[i].assign(5, -1);
    //}

    //bool ret = fillKnightTour(0, 0, 1, mat, vecx, vecy);

    //vector<vector<int>> a;
    //a.assign(4, vector<int>());
    //for (int i = 0; i < 4; i++)
    //{
    //    a[i].assign(4, 0);
    //}
    //int count = 1;
    //for (int i = 0; i < 4; i++)
    //{
    //    for (int j = 0; j < 4; j++)
    //    {
    //        a[i][j] = count++;
    //    }
    //}
    //altrotatematrix(a, 0, 4);
   // int brr[] = { 11, 12, 13, 14, 15, 16, 17, 18, 19 };
    //auto median = calculateMedian(arr, sizeof(arr) / sizeof(arr[0]), brr, sizeof(brr) / sizeof(brr[0]));
    //vector<int> vec1 = { 4,2,5,1 };
    //vector<int> vec2 = { 8,0,3,6 };

    //KMaxCombinations(vec1, vec2, 3);
    //vector<float> q = {10, 20, 5};
    //vector<float> w = {70, 50, 30};
    //auto ret = min_amnt(0, q, w, 2, 0.0f);
    //string str = "a#c";
    //auto count = 0;
    //for (int i = 0; i < str.size(); i++)
    //{
    //    if (str[i] == '#')
    //    {
    //        count += 2;
    //    }
    //    else
    //    {
    //        str[i - count] = str[i];
    //    }
    //}
    //string b = str.substr(0, 2);
    //string a = str.substr(0, str.size() - (count));
    //cout << a;
    //
    //int arr[] = { 5,7,7,8,8,10 };
    //int left = -1, right = -1;
    //search_begin_end(arr, sizeof(arr) / sizeof(arr[0]), 7, left, right);
    //string source = "X";
    //string dest = "L";
    //bool retVal = canConvert(source, dest);
    //vector<range> inter = { range(1,3), range(2,6) , range(8,10) , range(15,18) };
    //auto ret = mergeInterval(inter);
    /*vector<vector<bool>> mat;
    mat.assign(3, vector<bool>());
    for (int i = 0; i < 3; i++)
    {
        mat[i].assign(3, false);
    }
    auto found = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat[i][j] = true;
            found += no_of_pattern(i, j, mat, 0, 1, 1);
            mat[i][j] = false;
        }
    }*/


    //unordered_set<string> hs;
    //unordered_set<string> ths;
    //string str = "";
    //string resStr = "";

    //minLength(0, 2, 2, str, resStr, hs);
    //vector<int> vec{ 2,3,-2,4 };
    //vector<int> dp;
    //dp.assign(12, -1);
    //int arr1[] = { 2, 3, 5, 8 };
    //int arr2[] = { 10, 12, 14, 16, 18 };
    //auto profit = calculateMedian(arr1, arr2, sizeof(arr1)/sizeof(arr1[0]), sizeof(arr2) / sizeof(arr2[0]));
    //vector<int> vec = { 1,2,3,4,5 };
    //vector<int> set;
    //int m = 2;
    //set.assign(m, 0);
    //auto ret = divide_min_continuos(vec, 0, 0, set);
    ////vector<list<int>> adj;
    ////adj.assign(4, list<int>());
    ////adj[0].push_back(1);
    ////adj[0].push_back(2);
    ////adj[1].push_back(2);
    ////adj[2].push_back(3);
    ////adj[2].push_back(0);
    ////adj[3].push_back(3);
    ////std::vector<bool> visited(adj.size(), false);
    ////DFS(0, adj, visited);
    ///*priority_queue<node> heap;
    //heap.push(node(1, 2));
    //heap.push(node(2, 2));
    //heap.push(node(3, 2));
    //heap.push(node(5, 4));
    //heap.push(node(7, 2));
    //while (!heap.empty())
    //{
    //    auto elem = heap.top();
    //    heap.pop();
    //    std::cout << elem.sum << "\t" << elem.i << "\t"<<elem.j << "\n";
    //}*/
    //std::unordered_map<node*, int> umap;
    //node a(1, 2);
    //umap[&a] = 11;
    ////umap[node(2, 2)] = 12;
    ////umap[node(3, 2)] = 13;
    ////umap[node(4, 2)] = 14;



    //
    //if (umap.find(&a) != umap.end())
    //{
    //    std::cout << "\t" << umap[&a];
    //}
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
