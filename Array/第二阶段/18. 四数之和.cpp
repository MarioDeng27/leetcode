/*
 * @FilePath: \Sorte:\DataStructures-Algorithms\DataStructures-Algorithms\leetcode\Array\第二阶段\18. 四数之和.cpp
 * @Brief: 
 * @Version: 1.0
 * @Date: 2020-11-08 15:12:53
 * @Author: Mario Deng
 * @Copyright: your copyright description
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-01-25 15:21:01
 */
//自己的想法
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0 && nums[i] > target)
                break;
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] > 0 && nums[i] + nums[j] > target)
                    break;
                if (j > i + 1 && nums[j - 1] == nums[j])
                    continue;
                int L = j + 1;
                int R = n - 1;
                while (L < R)
                {
                    int sum = nums[i] + nums[j] + nums[L] + nums[R];
                    if (target == sum)
                    {
                        res.push_back({nums[i], nums[j], nums[L], nums[R]});
                        while (L < R && nums[L] == nums[L + 1])
                            L++;
                        while (L < R && nums[R] == nums[R - 1])
                            R--;
                        L++;
                        R--;
                    }
                    else if (target > sum)
                        L++;
                    else
                        R--;
                }
            }
        }
        return res;
    }
};

/*
    官方解法：其实就是对我的方法做了些优化，
    把nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target这种情况一旦出现就退出遍历，因为越往后离target越远，这是不可能的
    把nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target一旦出现，表示当前以i作为最左边元素，并且以他作为前提，最大的sum也比target小，所以放弃当前i作为最左边元素的
    情况
    在for j部分也是同理，注意for循环的判断条件 n -2 或者n-3 ，以免索引越界
*/

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        if (nums.size() < 4)
            return {};
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < n - 3; i++)
        {
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                break;
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target)
                continue;
            for (int j = i + 1; j < n - 2; j++)
            {
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                    break;
                if (j > i + 1 && nums[j - 1] == nums[j])
                    continue;
                if (nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target)
                    continue;
                int L = j + 1;
                int R = n - 1;
                while (L < R)
                {
                    int sum = nums[i] + nums[j] + nums[L] + nums[R];
                    if (target == sum)
                    {
                        res.push_back({nums[i], nums[j], nums[L], nums[R]});
                        while (L < R && nums[L] == nums[L + 1])
                            L++;
                        while (L < R && nums[R] == nums[R - 1])
                            R--;
                        L++;
                        R--;
                    }
                    else if (target > sum)
                        L++;
                    else
                        R--;
                }
            }
        }
        return res;
    }
};