/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-28 21:04:26
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-28 22:26:29
 */
//dfs 后序遍历，自下向上
class Solution
{
public:
    /**
     * 
     * @param matrix int整型vector<vector<>> the matrix
     * @return int整型
     */
    vector<vector<int>> dir = {{0, 1}, {1, 0}};
    int M, N;
    map<pair<int, int>, int> mem;
    bool check(int r, int c)
    {
        return r >= 0 && r < M && c >= 0 && c < N;
    }
    //计算(r,c)到右下角的最小路径和
    int dfs(vector<vector<int>> &matrix, int r, int c)
    {
        //若r和c刚好在右下角，则代价值为matrix[r][c]
        if (r == matrix.size() - 1 && c == matrix[0].size() - 1)
            return matrix[r][c];
        //初始化代价值为最大值
        int res = INT_MAX;
        if (mem.count({r, c}))
            return mem[{r, c}];
        //遍历向下或者向右两个方向，取这两个方向的最小值
        for (int i = 0; i < dir.size(); i++)
        {
            int nextr = r + dir[i][0];
            int nextc = c + dir[i][1];
            //检查nextr和nextc下标的有效性，不能越界
            if (check(nextr, nextc))
            {
                //计算从(nextr, nextc)到右下角的最短路径和
                int cost = dfs(matrix, nextr, nextc);
                res = min(cost + matrix[r][c], res);
            }
        }
        mem[{r, c}] = res;
        return res;
    }
    //从左上角到右下角的最短路径和，这种情况就只有向下或者向右是最优的，所以就两个扩展方向
    int minPathSum(vector<vector<int>> &matrix)
    {
        // write code here
        M = matrix.size();
        if (M == 0)
            return 0;
        N = matrix[0].size();
        int res = dfs(matrix, 0, 0);
        return res;
    }
};

//dfs，前序遍历，从上到下，慢
class Solution
{
public:
    /**
     * 
     * @param matrix int整型vector<vector<>> the matrix
     * @return int整型
     */
    vector<vector<int>> dir = {{0, 1}, {1, 0}};
    int M, N;
    map<pair<int, int>, int> mem;
    bool check(int r, int c)
    {
        return r >= 0 && r < M && c >= 0 && c < N;
    }
    int res = INT_MAX;
    //计算从(0,0)到(r,c)的代价值，sum表示还没走之前已产生的代价值
    void dfs(vector<vector<int>> &matrix, int r, int c, int sum)
    {
        //只要有路径到达了右下角，则记录这条路径产生的代价值，维护res
        if (r == matrix.size() - 1 && c == matrix[0].size() - 1)
            res = min(res, sum + matrix[r][c]);
        //遍历向下或者向右两个方向，因为有这两种可能性，每次都只有这两种可能性
        for (int i = 0; i < dir.size(); i++)
        {
            int nextr = r + dir[i][0];
            int nextc = c + dir[i][1];
            //检查nextr和nextc下标的有效性，不能越界
            if (check(nextr, nextc))
            {
                //sum+matrix[r][c]表示走到(r,c)产生的代价值
                dfs(matrix, nextr, nextc, sum + matrix[r][c]);
            }
        }
    }
    //从左上角到右下角的最短路径和，这种情况就只有向下或者向右是最优的，所以就两个扩展方向
    int minPathSum(vector<vector<int>> &matrix)
    {
        // write code here
        M = matrix.size();
        if (M == 0)
            return 0;
        N = matrix[0].size();
        dfs(matrix, 0, 0, 0);
        return res;
    }
};
//dp 从右下角向左上角开始扩展
class Solution
{
public:
    /**
     * 
     * @param matrix int整型vector<vector<>> the matrix
     * @return int整型
     */
    vector<vector<int>> dir = {{0, 1}, {1, 0}};
    //从左上角到右下角的最短路径和，这种情况就只有向下或者向右是最优的，所以就两个扩展方向
    int minPathSum(vector<vector<int>> &matrix)
    {
        // write code here
        int M = matrix.size();
        if (M == 0)
            return 0;
        int N = matrix[0].size();
        //dp[i][j] 表示 (i,j)到右下角的最小代价值，dp[M-1][N-1] = matrix[M-1][N-1]
        vector<vector<int>> dp(M, vector<int>(N, INT_MAX));
        dp[M - 1][N - 1] = matrix[M - 1][N - 1];
        for (int i = M - 1; i >= 0; i--)
        {
            for (int j = N - 1; j >= 0; j--)
            {
                if (i == M - 1 && j == N - 1)
                    dp[M - 1][N - 1] = matrix[M - 1][N - 1];
                if (i + 1 < M && j + 1 < N)
                    dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + matrix[i][j];
                else if (i + 1 < M)
                {
                    dp[i][j] = dp[i + 1][j] + matrix[i][j];
                }
                else if (j + 1 < N)
                {
                    dp[i][j] = dp[i][j + 1] + matrix[i][j];
                }
            }
        }
        return dp[0][0];
    }
};

//dp 从左上角向右下角开始扩展
class Solution
{
public:
    /**
     * 
     * @param matrix int整型vector<vector<>> the matrix
     * @return int整型
     */
    vector<vector<int>> dir = {{0, 1}, {1, 0}};
    //从左上角到右下角的最短路径和，这种情况就只有向下或者向右是最优的，所以就两个扩展方向
    int minPathSum(vector<vector<int>> &matrix)
    {
        // write code here
        int M = matrix.size();
        if (M == 0)
            return 0;
        int N = matrix[0].size();
        //dp[i][j] 表示 (0,0)到(i,j)的最小代价值，dp[0][0] = matrix[0][0]
        vector<vector<int>> dp(M, vector<int>(N, INT_MAX));
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == 0 && j == 0)
                    dp[0][0] = matrix[0][0];
                if (i - 1 >= 0 && j - 1 >= 0)
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + matrix[i][j];
                else if (i - 1 >= 0)
                {
                    dp[i][j] = dp[i - 1][j] + matrix[i][j];
                }
                else if (j - 1 >= 0)
                {
                    dp[i][j] = dp[i][j - 1] + matrix[i][j];
                }
            }
        }
        return dp[M - 1][N - 1];
    }
};