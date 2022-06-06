/*
 * @Description:
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-02 00:44:43
 * @LastEditors: Mario Deng
 * @LastEditTime: 2022-06-06 22:49:55
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
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int mid;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (nums[(mid - 1 + n) % n] != nums[mid] && nums[(mid + 1) % n] != nums[mid])
            {
                return nums[mid];
            }
            else if (nums[(mid - 1 + n) % n] == nums[mid] && (r - mid) % 2 == 1 || nums[(mid + 1) % n] == nums[mid] && (r - mid - 1) % 2 == 1)
            {
                if (nums[(mid - 1 + n) % n] == nums[mid])
                    l = mid + 1;
                else
                    l = mid + 2;
            }
            else
            {
                if (nums[(mid - 1 + n) % n] == nums[mid])
                    r = mid - 2;
                else
                    r = mid - 1;
            }
        }
        return nums[mid];
    }
};
int main()
{
    //"aewfafwafjlwajflwajflwafj"
    //[ "apple", "ewaf", "awefawfwaf", "awef", "awefe", "ewafeffewafewf" ] auto v = {1, 0, 0, 0, 1};
    auto b = Solution().findMin({1, 3, 3, 3});
    cout << "ss" << endl;
    return 0;
}