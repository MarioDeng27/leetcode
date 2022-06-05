/*
 * @Description:
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-02 00:44:43
 * @LastEditors: Mario Deng
 * @LastEditTime: 2022-06-05 20:21:37
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
    bool search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int mid;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[l] == nums[mid] && nums[r] == nums[mid])
            {
                l++;
                r--;
            }
            else if (nums[l] <= nums[mid] && nums[r] != nums[mid])
            {
                if (nums[l] <= target && nums[mid] > target)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else if (nums[mid] <= nums[r] && nums[l] != nums[mid])
            {
                if (nums[mid] < target && nums[r] >= target)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            else if (nums[l] == nums[mid] && nums[r] == nums[mid])
            {
                while (l <= r)
                {
                    if (nums[l] == target || nums[r] == target)
                        return true;
                    l++;
                    r--;
                }
                return false;
            }
        }
        return false;
    }
};
int main()
{
    //"aewfafwafjlwajflwajflwafj"
    //[ "apple", "ewaf", "awefawfwaf", "awef", "awefe", "ewafeffewafewf" ] auto v = {1, 0, 0, 0, 1};
    auto b = Solution().mySqrt(8);
    cout << "ss" << endl;
    return 0;
}