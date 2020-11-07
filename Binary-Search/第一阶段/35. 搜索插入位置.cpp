#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <sstream>
using namespace std;

/* 
    官方解法：
    在一个有序数组中找第一个大于等于 target 的下标
 */
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int n = nums.size();
        int left = 0, right = n - 1, ans = n;
        while (left <= right)
        {
            int mid = ((right - left) >> 1) + left;
            if (target <= nums[mid])
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }
};
//自己的想法
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        int mid;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (target < nums[mid])
                r = mid - 1;
            else if (target > nums[mid])
                l = mid + 1;
            else
                return mid;
        }
        if (nums[mid] < target)
            return mid + 1;
        else if (nums[mid] > target)
            return mid;
        else
            return mid;
    }
};