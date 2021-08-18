/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-14 21:19:03
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-14 21:30:23
 */
/*
    变形，需要两个位置的情况，dp[i][j]，以j，i结尾
    dp[i][j] 表示数组中以索引i和j结尾的两个元素它能形成的斐波那契序列最长是多少。那么它的值取决于nums[i]和nums[j] 前面是否有满足斐波的要求的元素存在其索引是index，如果存在返回dp[j][index] 这个情况下的斐波序列长度 +1，表示自身也满足了
    那么任何dp情况下的初始值都2，如果找到一个数字那就加1
*/
class Solution
{
public:
    vector<vector<int>> dp;
    map<int, int> indexOf;
    int lenLongestFibSubseq(vector<int> &arr)
    {
        int n = arr.size();
        dp = vector<vector<int>>(n, vector<int>(n, 2));
        for (int i = 0; i < n; i++)
        {
            indexOf[arr[i]] = i;
        }
        int maxLen = 0;
        for (int i = 2; i < n; i++)
        {
            for (int j = 1; j <= i - 1; j++)
            {
                int need = arr[i] - arr[j];
                if (indexOf.count(need) != 0 && indexOf[need] < j)
                {
                    dp[i][j] = dp[j][indexOf[need]] + 1;
                    maxLen = max(maxLen, dp[i][j]);
                }
            }
        }
        return maxLen;
    }
};