/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-15 14:56:55
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-15 15:00:54
 */
/*
    假设 A[index] , A[j], A[i]
    原理和斐波那契数列差不多，找到need的大小就可以了，关键不明白提前创建好map，在判断的时候得到的index < j 和 不先创建好在进行for(int i = 0 : n)逐个创建有什么不同，反正记下就行了。

    逐个加进去，还能节省空间

    A[i][j] 表示  以 A[j], A[i]为后面两个，往前面找到底有几个可以组成等差数列

*/

class Solution
{
public:
    int longestArithSeqLength(vector<int> &A)
    {
        int n = A.size();
        map<int, int> indexOf;
        /* for (int i = 0; i < A.size(); i++)
        {
            indexOf[A[i]] = i;
        } */
        vector<vector<int>> dp(n, vector<int>(n, 2));
        int maxLen = 2;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int need = 2 * A[i] - A[j];
                if (indexOf.count(need) != 0)
                {
                    dp[j][i] = dp[i][indexOf[need]] + 1;
                    maxLen = max(maxLen, dp[j][i]);
                }
            }
            indexOf[A[i]] = i;
        }
        return maxLen;
    }
};