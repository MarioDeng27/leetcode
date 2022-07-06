class Solution
{
public:
    vector<int> dir = {-1, 0, 1, 0, -1};
    void dfs(vector<vector<int>> &heights, int r, int c, vector<vector<bool>> &can_reach)
    {
        can_reach[r][c] = true;
        for (int i = 0; i < 4; i++)
        {
            int x = r + dir[i];
            int y = c + dir[i + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && can_reach[x][y] == false && heights[x][y] >= heights[r][c])
                dfs(heights, x, y, can_reach);
        }
    }
    int m, n;
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        m = heights.size(), n = m ? heights[0].size() : 0;
        if (m == 0 || n == 0)
            return {};
        vector<vector<bool>> can_reach_p(m, vector<bool>(n, false));
        vector<vector<bool>> can_reach_a(m, vector<bool>(n, false));
        //左右
        for (int i = 0; i < m; i++)
        {
            dfs(heights, i, 0, can_reach_p);
            dfs(heights, i, n - 1, can_reach_a);
        }
        //上下
        for (int j = 0; j < n; j++)
        {
            dfs(heights, 0, j, can_reach_p);
            dfs(heights, m - 1, j, can_reach_a);
        }
        vector<vector<int>> res;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (can_reach_p[i][j] && can_reach_a[i][j])
                {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};