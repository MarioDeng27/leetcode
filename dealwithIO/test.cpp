/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-02 00:44:43
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-18 21:06:43
 */
/*
 * @FilePath: \Sort\test.cpp
 * @Brief: 
 * @Version: 1.0
 * @Date: 2020-10-05 22:41:14
 * @Author: Mario Deng
 * @Copyright: your copyright description
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-07-02 00:37:48
 */
#include <algorithm>
#include <array>
#include <atomic>
#include <bits/stdc++.h>
#include <cctype>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <pthread.h> // pthread_create(), pthread_join()
#include <queue>
#include <semaphore.h> // sem_init()
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <vector>
using namespace std;

/* #include <bits/stdc++.h>
using namespace std; */

void func(vector<vector<int>> &A)
{
    int R = A.size();
    int C = A[0].size();
    vector<vector<int>> B(R, vector<int>(C));
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            B[j][R - 1 - i] = A[i][j];
        }
    }
    A = B;
}
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
    在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。

    你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。

    如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。


    输入: 
    gas  = [1,2,3,4,5]
    cost = [3,4,5,1,2]

    输出: 3

    解释:
    从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油
    开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油
    开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油
    开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油
    开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油
    开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
    因此，3 可为起始索引。


    输入: 
    gas  = [2,3,4]
    cost = [3,4,3]

    输出: -1
*/

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
             {
                 if (a[0] == b[0])
                     return a[1] > b[1];

                 else
                     return a[0] < b[0];
             });

        int left = intervals[0][0];
        int right = intervals[0][1];
        vector<vector<int>> res;
        for (int i = 1; i < intervals.size(); i++)
        {
            vector<int> p = intervals[i];
            //存在覆盖的情况
            if (p[0] >= left && p[1] <= right)
            {
            }
            //存在相交的情况
            if (p[0] <= right && p[1] > right)
            {
                right = p[1];
            }
            //完全不相交
            if (p[0] > right)
            {
                res.push_back({left, right});
                left = p[0];
                right = p[1];
            }
        }
        res.push_back({left, right});
        return res;
    }
};
class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
    {
        int i = 0;
        int j = 0;
        vector<vector<int>> res;
        while (i < firstList.size() && j < secondList.size())
        {
            vector<int> first = firstList[i];
            vector<int> second = secondList[j];
            //不相交的情况
            if (first[0] > second[1] || second[0] > first[1])
            {
                //不做处理，只在后面对i或者j自增操作
            }
            //相交的情况
            else
            {
                //取交集，其实就是两个区间的起始的较大值以及终点的较小值
                res.push_back({max(first[0], second[0]), min(first[1], second[1])});
                //如果first结束的比second快，则first后面那一段有可能还会和second有交集，所以i++
            }
            if (first[1] < second[1])
                i++;
            else
                j++;
        }
        return res;
    }
};
int main()
{
    vector<int> nums = {200, 3, 140, 20, 10};
    // cout << Solution().rob(nums);
    return 0;
}
