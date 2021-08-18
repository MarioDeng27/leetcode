/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-11 21:25:26
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-11 21:57:46
 */
/*
    关键是最开始的sort排序，让enve根据[0]即w的大小作为第一关键字和[1]即h的大小作为第二关键字来排序就是为了避免 当排序过程中w相等出现的问题（相等后者肯定是不能装下前者的），那么让h从大到小，这样后面根据h来进行计算的时候，当前面的值大于后面的值，这样就直接否定了这个情况，解释不了，还是看官方解释吧

    一般情况，只要w互不相等，从大到小排，那么这个问题就是，根据h的 最长严格递增子序列 的问题。但是由于设计了，第二关键字从大到小排的情况，所以就可以去除w互不相等的条件了。
*/

class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        sort(envelopes.begin(), envelopes.end(), compair);

        vector<int> dp(envelopes.size(), 1);
        for (int i = 1; i < envelopes.size(); i++)
        {
            int maxLen = 0;
            //方法1，对dp[i]求值
            for (int j = 0; j <= i - 1; j++)
            {
                if (envelopes[i][1] > envelopes[j][1])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            //方法2，对dp[i]求值
            /* for (int j = 0; j <= i - 1; j++)
            {
                if (envelopes[i][1] > envelopes[j][1])
                    maxLen = max(maxLen, dp[j]);
            }
            dp[i] = maxLen + 1; */
        }
        return *max_element(dp.begin(), dp.end());
    }

    static bool compair(const vector<int> &e1, const vector<int> &e2)
    {
        if (e1[0] != e2[0])
            return e1[0] < e2[0];
        else
            return e1[1] > e2[1];
    }
};
//基于二分查找的动态规划，其实就是看当前的num值能不能从之前的数组里找出合适的地方塞进去。
class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        sort(envelopes.begin(), envelopes.end(), compair);

        //vector<int> dp(envelopes.size(), 1);
        vector<int> nums;
        nums.push_back(envelopes[0][1]);
        for (int i = 1; i < envelopes.size(); i++)
        {
            int num = envelopes[i][1];
            if (num > nums.back())
                nums.push_back(num);
            else
            {
                //lower_bound(),找到大于或者等于val的第一个元素的位置，而upper_bound(),找到大于val的第一个元素的位置
                auto it = lower_bound(nums.begin(), nums.end(), envelopes[i][1]);
                //为什么可以覆盖前面的，因为enve往后的靠的即使后面的h小于前面的，但是因为w还是后面的大，肯定是不能让前面装下后面的
                if (it != nums.end())
                    *it = envelopes[i][1];
            }
        }
        return nums.size();
    }
    static bool compair(const vector<int> &e1, const vector<int> &e2)
    {
        if (e1[0] != e2[0])
            return e1[0] < e2[0];
        else
            return e1[1] > e2[1];
    }
};