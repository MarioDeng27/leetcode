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
    自己想法：
    用递归法来实现二分查找：
  */
class Solution
{
public:
    int binarysearch(vector<int> &nums, int target, int L, int R)
    {
        if (L == R && nums[R] != target)
            return -1;
        int mid = (L + R) / 2;
        if (nums[mid] > target)
            return binarysearch(nums, target, L, mid);
        else if (nums[mid] < target)
            return binarysearch(nums, target, mid + 1, R);
        else
            return mid;
    }
    int search(vector<int> &nums, int target)
    {
        int L = 0;
        int R = nums.size() - 1;
        return binarysearch(nums, target, L, R);
    }
};
/* 
    自己想法：
    用迭代法来实现二分查找：
    由于如果不单独判断nums[R]在迭代里是还没判断就跳出了循环了，所以前面单独判断，反而速度快
  */
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int L = 0;
        int R = nums.size() - 1;
        int mid;
        if (nums[R] == target)
            return R;
        if (nums[L] == target)
            return L;
        while (L < R)
        {
            mid = (L + R) / 2;
            if (target < nums[mid])
                R = mid;
            else if (target > nums[mid])
                L = mid + 1;
            else
                return mid;
        }
        return -1;
    }
};
/* 
    官方给出的答案模板，学习下！！！
 */

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int pivot, left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            pivot = (right + left) / 2;
            if (nums[pivot] == target)
                return pivot;
            if (target < nums[pivot])
                right = pivot - 1;
            else
                left = pivot + 1;
        }
        return -1;
    }
};