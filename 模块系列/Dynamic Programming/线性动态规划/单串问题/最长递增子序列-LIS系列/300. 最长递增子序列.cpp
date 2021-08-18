/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-11 22:07:19
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-11 22:26:20
 */
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++)
        {
            int maxLen = 0;
            //往 0 - i-1的数字中找到比nums[i]小的数字，并且找到这堆数字中对应dp值最大的那个数组，然后在当前dp里加1如果没找到比nums[i]小的则让当前dp等于1，所以这边让maxLen初始值为0 的原因
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                    maxLen = max(maxLen, dp[j]);
            }
            dp[i] = maxLen + 1;
        }
        return *max_element(dp.begin(), dp.end());
    }
};

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> dp(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

//利用helper数组，这个数组表示，是严格递增的，且它的末尾元素都是最小的，如果发现当前元素x比helper里末尾元素小，则找到helper里面第一次出现比这个x大于或者等于的数字，然后将其替换掉，这里有贪心的思想在。
//因为如果这个数组不是严格单调递增，而是存在递减的地方，那么这个helper肯定不是我们要的答案。比如10，9，11，17
//要么10，11，17要么9，11，17所以，在寻找的时候，凡是出现比末尾元素小的数字，就要去helper里找到合适的地方将其里面的某一元素给替换掉。
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> helper;
        helper.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > helper.back())
                helper.push_back(nums[i]);
            else
            {
                auto it = lower_bound(helper.begin(), helper.end(), nums[i]);
                *it = nums[i];
            }
        }
        return helper.size();
    }
};