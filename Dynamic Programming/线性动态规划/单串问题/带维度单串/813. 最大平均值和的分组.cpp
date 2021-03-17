/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-17 20:11:14
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-17 20:11:34
 */
class Solution
{
public:
    //通过公式算平均数
    double getAve(vector<int> &A, int start, int end)
    {
        double sum = 0;
        for (int i = start; i <= end; i++)
        {
            sum += A[i];
        }
        return sum / (end - start + 1);
    }
    double largestSumOfAverages(vector<int> &A, int K)
    {
        int n = A.size();
        if (n < K)
            return 0;
        vector<vector<double>> dp(n + 1, vector<double>(K + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            dp[i][1] = getAve(A, 0, i - 1);
        }

        for (int i = 2; i <= n; i++)
        {
            for (int j = 2; j <= K && j <= i; j++)
            {
                double maxVal = 0;
                for (int m = 1; m <= i - 1; m++)
                    maxVal = max(maxVal, dp[m][j - 1] + getAve(A, m, i - 1));
                dp[i][j] = maxVal;
            }
        }
        return dp[n][K];
    }
};

//通过前缀和算平均数
class Solution
{
public:
    double largestSumOfAverages(vector<int> &A, int K)
    {
        int n = A.size();
        if (n < K)
            return 0;
        vector<vector<double>> dp(n + 1, vector<double>(K + 1, 0));
        vector<double> sums(n);
        sums[0] = A[0];
        for (int i = 1; i < n; i++)
        {
            sums[i] = sums[i - 1] + A[i];
        }

        for (int i = 1; i <= n; i++)
        {
            dp[i][1] = sums[i - 1] / i;
        }

        for (int i = 2; i <= n; i++)
        {
            for (int j = 2; j <= K && j <= i; j++)
            {
                double maxVal = 0;
                for (int m = 1; m <= i - 1; m++)
                    maxVal = max(maxVal, dp[m][j - 1] + (sums[i - 1] - sums[m - 1]) / (i - m)); //从m下表就是第m+1个开始到第i-1下标，就是第i个
                dp[i][j] = maxVal;
            }
        }
        return dp[n][K];
    }
};