/*
 * @Description:
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-02 00:44:43
 * @LastEditors: Mario Deng
 * @LastEditTime: 2022-06-05 03:42:25
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
class Solution
{
public:
    bool check(string s, int low, int high)
    {
        while (low <= high)
        {
            if (s[low] == s[high])
            {
                low++;
                high--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s)
    {
        int l = 0;
        int r = s.size() - 1;
        int cnt = 0;
        while (l <= r)
        {
            if (s[l] == s[r])
            {
                l++;
                r--;
            }
            else
            {
                return check(s, l + 1, r) || check(s, l, r - 1);
            }
        }
        return true;
    }
};
int main()
{
    auto v = {1, 0, 0, 0, 1};
    auto b = Solution().judgeSquareSum(2147482647);
    cout << "ss" << endl;
    return 0;
}