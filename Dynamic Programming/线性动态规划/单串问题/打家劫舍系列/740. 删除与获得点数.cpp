/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-14 18:36:55
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-14 18:42:51
 */
/*
    https://leetcode-cn.com/problems/delete-and-earn/solution/ru-guo-ni-li-jie-liao-da-jia-jie-she-zhe-ti-ni-ken/
    每个位置上的数字可以在两种情况中选择的：
    第一个，就是不删除当前位置的数字，那么当前的结果前一个的位置最优结果
    第二个，就是当前位置数字删除，那么结果就是i-2前面的那个最优结果+当前位置的数字乘以个数
    两种情况取大值。

    妙就妙在，将上面的原始数组转化成一个临时数组array，array 的索引j就是原始数组里面每个数的值，j在原始数组中存在的个数
    举个例子：

    nums = [2, 2, 3, 3, 3, 4]
    构造后：
    array=[0, 0, 2, 3, 1];
    
    完成之后，nums[i]+1 或者nums[i]-1 不能选择的问题就转化成array数组不能选择邻居的问题。 每一个单位的大小就是位置*值，转换成打家劫舍的问题了。就是到最后抢最多钱的问题

*/
class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        int maxVal = INT_MIN;
        map<int, int> m;
        for (auto const num : nums)
        {
            m[num]++;
            maxVal = max(num, maxVal);
        }
        vector<int> array(maxVal + 1, 0);
        for (auto it : m)
        {
            array[it.first] = it.second;
        }
        vector<int> dp(array.size(), 0);
        dp[0] = 0 * array[0];
        dp[1] = max(dp[0], 1 * array[1]);
        for (int i = 2; i < array.size(); i++)
        {
            dp[i] = max(dp[i - 1], i * array[i] + dp[i - 2]);
        }
        return dp[array.size() - 1];
    }
};