/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-16 15:19:48
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-16 15:30:20
 */
#include <iostream>
#include <vector>
using namespace std;
// 初始化：创建二维数组status[m][n]，初始化status[0][0]=0, status[0][1]=1, status[0][n-1]=1, 其余(...) = 0
// 状态的确定：status[x][y]
// 假设小赛是第0个同学，旁边则为第1个和第n-1个，设状态为status[i][j]：i+1次传花后以第j位同学结束的序列有多少种
// 状态转移方程：
// status[i][j] = status[i-1][(j+1)%n] + status[i-1][(j+n-1)%n]
// 结果为status[m-1][0]
int getAns(int n, int m)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][1] = 1;
    dp[0][n - 1] = 1;
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = dp[i - 1][(j + 1) % n] + dp[i - 1][(j - 1 + n) % n];
        }
    }
    return dp[m - 1][0];
}
int main()
{
    int n, m;
    cin >> n >> m;
    cout << getAns(n, m) << endl;
    return 0;
}