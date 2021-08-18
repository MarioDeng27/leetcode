/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-10 11:34:22
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-10 11:34:24
 */

//https://leetcode-cn.com/problems/pizza-with-3n-slices/solution/3n-kuai-pi-sa-by-leetcode-solution/
class Solution
{
public:
    int maxSizeSlicesCore(vector<int> &slices)
    {
        int size = slices.size();
        int choose = (size + 1) / 3;

        vector<vector<int>> dp(size + 1, vector<int>(choose + 1));

        for (int i = 1; i <= size; i++)
        {
            for (int j = 1; j <= choose; j++)
            {
                dp[i][j] = max(dp[i - 1][j], (i - 2 >= 0 ? dp[i - 2][j - 1] : 0) + slices[i]);
            }
        }

        return dp[size][choose];
    }

    int maxSizeSlices(vector<int> &slices)
    {
        vector<int> vec1(slices.begin() + 1, slices.end());
        vector<int> vec2(slices.begin(), slices.end() - 1);

        return max(maxSizeSlicesCore(vec1), maxSizeSlicesCore(vec2));
    }
};