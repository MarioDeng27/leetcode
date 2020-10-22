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
#include <climits>
using namespace std;
/* 
自己实现的：
 */
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        nums.insert(nums.begin(), INT_MIN);
        nums.insert(nums.end(), INT_MIN);
        int l = 1;
        int r = nums.size() - 2;
        int mid = (l + r) / 2;
        while (l <= r && l > 0 && r < nums.size() - 1)
        {
            mid = (l + r) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid - 1;
            else if (nums[mid] < nums[mid - 1])
                r = mid - 1;
            else if (nums[mid] < nums[mid + 1])
                l = mid + 1;
            else
                break;
        }
        return mid - 1;
    }
};
/* 
    https://leetcode-cn.com/problems/find-peak-element/solution/xun-zhao-feng-zhi-by-leetcode/
 */
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        return search(nums, 0, nums.size() - 1);
    }
    int search(vector<int> &nums, int l, int r)
    {
        if (l == r)
            return l;
        int mid = (l + r) / 2;
        if (nums[mid] > nums[mid + 1])
            return search(nums, l, mid);
        return search(nums, mid + 1, r);
    }
};
