// practise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<queue>
//#include<queue>
using namespace std;



//int createSegmentTree(vector<int>& arr, int l, int h, int index, vector<int>& sum)
//{
//    if (l == h)
//    {
//        sum[index] = arr[l];
//        return arr[l];
//    }
//    auto mid = l + (h - l) / 2;
//    sum[index] = createSegmentTree(arr, l, mid, 2 * index + 1, sum) +
//        createSegmentTree(arr, mid + 1, h, 2 * index + 2, sum);
//    return sum[index];
//}
//
//
//int getSegmentSum(vector<int>& sum, int sl, int sh, int l, int h, int index)
//{
//    if (h < sl || l > sh)
//    {
//        return 0;
//    }
//    if (sl >= l && sh <= h)
//    {
//        return sum[index];
//    }
//    auto mid = sl + (sh - sl) / 2;
//    auto dsum = getSegmentSum(sum, sl, mid, l, h, 2 * index + 1) +
//        getSegmentSum(sum, mid + 1, sh, l, h, 2 * index + 2);
//    return dsum;
//}
//
//
//int get_max_length(string str)
//{
//    unordered_map<char, int> umap;
//    int m_l = 0;
//    int s = 0;
//    int i = 0;
//    for (i = 0; i < str.length(); i++)
//    {
//        if (umap.find(str[i]) != umap.end() && umap[str[i]] >= s)
//        {
//            if (i - s  > m_l)
//            {
//                m_l = i - s;
//            }
//            s = umap[str[i]] + 1;
//        }
//        umap[str[i]] = i;
//    }
//    if (i - s > m_l)
//    {
//        m_l = i - s;
//    }
//    return m_l;
//}
//
//
//vector<int> ds;
//vector<int> vrank;
//
//
//int findParent(int u)
//{
//    if (ds[u] == -1)
//    {
//        return u;
//    }
//    return findParent(ds[u]);
//}
//
//void dsunion(int u, int v)
//{
//    auto pu = findParent(u);
//    auto pv = findParent(v);
//    if (pu == pv)
//    {
//        return;
//    }
//    if (vrank[pu] > vrank[pv])
//    {
//        ds[pv] = pu;
//    }
//    else if (vrank[pv] > vrank[pu])
//    {
//        ds[pu] = pv;
//    }
//    else
//    {
//        ds[pv] = pu;
//        vrank[pu]++;
//    }
//}

bool BFS(vector<vector<int>>& graph, int source, int sink, vector<int>& parent)
{
    std::queue<int> eq;
    eq.push(source);
    vector<bool> visited;
    visited.insert(visited.begin(), 6, false);
    visited[source] = true;
    int u = source;
    while (!eq.empty())
    {
        u = eq.front();
        eq.pop();
        for (int i = 0; i < 6; i++)
        {
            if (!visited[i] && graph[u][i] > 0)
            {
                parent[i] = u;
                eq.push(i);
                visited[i] = true;
                if (i == sink)
                {
                    return true;
                }
            }
        }
    }
    return false;
}


int no_of_Active_Items(std::vector<std::vector<int>>& mat, int m, int n)
{
    int nRow = m, nCol = n;
    int nItems = m * n;
    std::vector<bool> bActiveRow(m, true);
    std::vector<bool> bActiveCol(n, true);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((mat[i][j] <= 10 && mat[i][j] % 5 == 0) || mat[i][j] == 6)
            {
                if (!bActiveRow[i] || !bActiveCol[j])
                {
                    continue;
                }
                nItems -= nRow;
                nItems -= nCol - 1;
                bActiveCol[j] = false;
                bActiveRow[i] = false;
                nRow--;
                nCol--;
            }
        }
    }
    return nItems;
}

int maxLength(std::vector<std::vector<int>>& mat, int i, int j, int m, int n, int k, int maxK)
{
    if (i >= m)
    {
        return std::numeric_limits<int>::min();
    }
    if(j >= n)
    {
       return std::numeric_limits<int>::min();
    }
    if (i == m - 1 && j == n - 1)
    {
        return mat[i][j];
    }
    auto sum = mat[i][j] + maxLength(mat, i + 1, j, m, n, maxK, maxK);
    if (k > 1)
    {
        auto lsum = mat[i][j] + maxLength(mat, i, j + 1, m, n, k - 1, maxK);
        sum = lsum > sum ? lsum : sum;
    }
    return sum;
}

bool comapre( std::pair<int, int> a, std::pair<int, int> b)
{
    return a.first < b.first;
}

class server
{
public :
    int index, weight;
};

bool compareh(server a, server b)
{
    if (a.weight == b.weight)
    {
        return a.index > b.index;
    }
    return a.weight > b.weight;
}
int getServer(vector<int>& ser, vector<int>& task)
{
    vector<int> arr;
    vector<std::pair<int, int>> dep;
    std::vector<server> vSer;
    std::priority_queue<server, vector<server>, decltype(&compareh)> pq(compareh);
    int i = 0;
    for (i = 0; i < ser.size(); i++)
    {
        server p;
        p.weight = ser[i];
        p.index = i;
        pq.push(p);
        vSer.push_back(p);
    }
    for ( i = 0; i < task.size(); i++)
    {
        arr.push_back(i);
        std::pair<int, int> p;
        p.first = i + task[i];
        p.second = i;
        dep.push_back(p);
    }

    std::sort(dep.begin(), dep.end(), comapre);
    


    i = 0; 
    int j = 0;
    std::vector<int> aSer(task.size(), 0);
    for (i = 0; i < task.size(); i++)
    {
        if (dep[j].first <= arr[i])
        {
            while (dep[j].first <= arr[i])
            {
                pq.push(vSer[aSer[dep[j].second]]);
                j++;
            }
        }
        if (!pq.empty())
        {
            auto ser = pq.top();
            pq.pop();
            aSer[i] = ser.index;
        }
        else
        {
            auto firstdep = dep[j].first;
            while (dep[j].first == firstdep)
            {
                pq.push(vSer[aSer[dep[j].second]]);
                j++;
            }
            auto ser = pq.top();
            pq.pop();
            aSer[i] = ser.index;
        }
    }
    return 0;

}


int maxDistinct(vector<int>& arr, int k)
{
    std::unordered_map<int, int> hm;
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&comapre)> pq(comapre);
    for (int i = 0; i < arr.size(); i++)
    {
        hm[arr[i]]++;
    }
    for (auto p : hm)
    {
        pq.push(p);
    }
    while (k > 0)
    {
        auto p = pq.top();
        pq.pop();
        if (p.second > k)
        {
            p.second -= k;
            k = 0;
        }
        else
        {
            if (p.second == 1)
            {
                k -= 1;
                continue;
            }
            k -= p.second - 1;
            p.second = 1;
        }
        pq.push(p);
    }
    return pq.size();
}



void distsort(vector<int>& arr, int k)
{
    std::priority_queue<int, vector<int>, greater<int>> h;
    int i = 0;
    for (i = 0; i <= 3; i++)
    {
        h.push(arr[i]);
    }
    int j = i - k;
    arr[0] = h.top();
    h.pop();
    while (i < arr.size())
    {
        arr[j] = h.top();
        h.pop();
        h.push(arr[i]);
        i++;
        j++;
    }
    while (!h.empty())
    {
        arr[j++] = h.top();
        h.pop();
    }
    return;
}

int getMaxAera(std::vector<vector<int>>& mat, int m, int n)
{
    std::vector<std::vector<int>> bmat = mat;
    int maxArea = std::numeric_limits<int>::min();
    int len = 0;
    int min = std::numeric_limits<int>::max();
    for (int i = 0; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (mat[i][j] == 0)
            {
                bmat[i][j] = 0;
                min = std::numeric_limits<int>::max();
                continue;
            }
            else
            {
                bmat[i][j] = bmat[i][j - 1] + 1;
            }

        }
    }
    for (int j = n - 1; j > 0; j--)
    {
        for (int i = 0; i < m; i++)
        {
            if (mat[i][j] == 0)
            {
                len = 0;
                min = std::numeric_limits<int>::max();
                continue;
            }
            else
            {
                len++;
                min = (min > bmat[i][j]) ? bmat[i][j] : min;
                auto area = min * len;
                maxArea = (maxArea < area) ? area : maxArea;
            }
        }
    }

    bmat = mat;

    for (int j = 0; j < n; j++)
    {
        for (int i = 1; i < m; i++)
        {
            if (bmat[i][j] == 0)
            {
                continue;
            }
            bmat[i][j] = bmat[i - 1][j] + 1;
        }
    }

    for (int i = 0; i < m; i++)
    {
        len = 0;
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 0)
            {
                len = 0;
                min = std::numeric_limits<int>::max();
                continue;
            }
            else
            {
                len++;
                min = (min > bmat[i][j]) ? bmat[i][j] : min;
                auto area = min * len;
                maxArea = (maxArea < area) ? area : maxArea;
            }
        }
    }


    return maxArea;
}

void printSpiral(std::vector<vector<int>>& mat, int m, int n, int i)
{
    if (i >= (m + 1) / 2)
    {
        return;
    }
    int lj = i;
    while (lj <= n - 1 - i)
    {
        std::cout << " " << mat[i][lj];
        lj++;
    }

    int li = i + 1;
    while (li <= m - 1 - i)
    {
        cout << " " << mat[li][n - 1 - i];
        li++;
    }
    if (m - 1 - i != i)
    {
        lj = n - 2 - i;
        while (lj > i - 1)
        {
            std::cout << " " << mat[m - 1 - i][lj];
            lj--;
        }
    }
    if (i != n - 1 - i)
    {
        li = m - 2 - i;
        while (li > i)
        {
            cout << " " << mat[li][i];
            li--;
        }
    }
    printSpiral(mat, m, n, i + 1);
}




//void fillMatrix(std::vector<vector<int>>& mat, std::vector<int>& vec, int i, int j, int index)
//{
//    int m = mat.size();
//    int n = mat[0].size();
//    if (i > (m - 1) / 2)
//    {
//        return;
//    }
//    for (int li = j; li < n - i; li++)
//    {
//        mat[i][li] = vec[index++];
//    }
//    int li = i + 1;
//    for (; li < m - i ; li++)
//    {
//        mat[li][n - 1-j] = vec[index++];
//    }
//    int lj = n - 2 - j;
//    for (; lj > i-1; lj--)
//    {
//        mat[m-1-j][lj] = vec[index++];
//    }
//    li = m - 2 - i;
//    while (li > i)
//    {
//        mat[li][j] = vec[index++];
//        li--;
//    }
//}


void transpose(std::vector<vector<int>>& a, int n, int i)
{
    if (i >= n / 2)
    {
        return;
    }
    for (int j = i; j < n - 1 - i; j++)
    {
        auto temp = a[i][j];
        a[i][j] = a[n - 1 - j][i];
        a[n - 1 - j][i] = a[n - 1 - i][n - 1 - j];
        a[n - 1 - i][n - 1 - j] = a[j][n - 1 - i];
        a[j][n - 1 - i] = temp;
    }
    transpose(a, n, i + 1);
}


int klarge(vector<vector<int>>& mat, int k)
{
    auto axor = mat;
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(mat[0][0]);
    for (int i = 0; i < mat.size(); i++)
    {
        int j = (i == 0) ? 1 : 0;
        for (; j < mat[0].size(); j++)
        {
            auto no = mat[i][j];
            if (i - 1 > -1 && j - 1 > -1)
            {
                no = no ^ mat[i - 1][j - 1] ^ mat[i][j - 1] ^ mat[i - 1][j];
            }
            else if (i - 1 > -1)
            {
                no = no ^ mat[i - 1][j];
            }
            else
            {
                no = no ^ mat[i][j - 1];
            }
            axor[i][j] = no;
            if (pq.size() < k)
            {
                pq.push(no);
            }
            else
            {
                if (no > pq.top())
                {
                    pq.pop();
                    pq.push(no);
                }
            }
        }
    }
    return pq.top();
}

bool compareapple(pair<int, int> a, pair <int, int> b)
{
    return a.second > b.second;
}

int applecount(vector<int> apples, vector<int> days)
{
    auto ldays = days;
    for (int i = 0; i < apples.size(); i++)
    {
        ldays[i] += i;
    }
    std::priority_queue<std::pair<int, int>, vector<pair<int, int>>, decltype(&compareapple)> pq(compareapple);
    int i = 0;
    int a_count = 0;
    for (i = 0; i < apples.size(); i++)
    {
        if (apples[i] != 0)
        {
            pair<int, int> p;
            p.first = apples[i];
            p.second = ldays[i];
            pq.push(p);
        }
        if (!pq.empty())
        {
            while (!pq.empty() && pq.top().second <= i)
            {
                pq.pop();
            }
            if (!pq.empty())
            {
                auto n = pq.top();
                pq.pop();
                a_count++;
                n.first--;
                if (n.first > 0)
                {
                    pq.push(n);
                }
            }
        }
    }

    if (!pq.empty())
    {
        while (!pq.empty())
        {
            while (!pq.empty() && pq.top().second <= i)
            {
                pq.pop();
            }
            if (!pq.empty())
            {
                auto n = pq.top();
                pq.pop();
                a_count++;
                n.first--;
                if (n.first > 0)
                {
                    pq.push(n);
                }
            }
            i++;
        }
    }
    return a_count;
}

int main()
{
    //vector<int> parent;
    //parent.insert(parent.begin(), 6, -1);
    //vector<vector<int>> mat;
    //mat.insert(mat.begin(), 5, vector<int>());
    //int val = 1;
    ///*for (int i = 0; i < mat.size(); i++)
    //{
    //    for (int j = 0; j < 4; j++)
    //    {
    //        mat[i].push_back(val++);
    //    }
    //}*/
    //mat[0] = { 1,2,3, 4, 5};
    //mat[1] = { 6,7,8,9, 10 };
    //mat[2] = { 11,12,13,14, 15};
    //mat[3] = { 16,17,18,19, 20 };
    //mat[4] = { 21,22,23,24, 25};
   // mat[3] = { 1,1,0,0 };
    //getMaxAera(mat, 4, 4);
    // 
    //auto len = maxLength(mat, 0, 0, 3, 3, 2, 2);
    //BFS(graph, 0, 5, parent);
    //transpose(mat, 5, 0);
    vector<int> apples = { 3,0,0,0,0,2 };
    vector<int> days = { 3,0,0,0,0,2 };

    vector<vector<int>> mat(2, vector<int>());
    mat[0] = { 5,2 };
    mat[1] = { 1,6 };
    auto k = applecount(apples, days);
    //auto c = getServer(ser, task);
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
