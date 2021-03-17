/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-17 19:30:09
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-17 19:30:10
 */
long num = 1000000007;
int getAns(int n, int m, int k)
{
    if (k < n || k > n * m)
        return 0;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 1;
        if (i == 1)
        {
            for (int j = 1; j <= m && j <= k; j++)
                dp[1][j] = 1;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = i + 1; j <= k; j++)
        {
            for (int a = 1; a <= m && j - a >= 0; a++)
                dp[i][j] += dp[i - 1][j - a];
        }
    }
    return dp[n][k] % num;
}

int main()
{
    int t;
    int c = getAns(4, 5, 8);
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        cout << getAns(n, m, k) << endl;
    }
    return 0;
}