/*
 * @Description:
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2022-07-04 15:32:03
 * @LastEditors: Mario Deng
 * @LastEditTime: 2022-07-04 15:47:56
 */
// dfs用栈来实现
class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        vector<int> dir = {-1, 0, 1, 0, -1};
        int m = grid.size(), n = m ? grid[0].size() : 0, local_area, area = 0, x, y;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    local_area = 1;
                    grid[i][j] = 0;
                    stack<pair<int, int>> st;
                    st.push({i, j});
                    while (!st.empty())
                    {
                        auto [a, b] = st.top();
                        st.pop();
                        for (int k = 0; k < 4; k++)
                        {
                            x = a + dir[k];
                            y = b + dir[k + 1];
                            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1)
                            {
                                local_area++;
                                grid[x][y] = 0;
                                st.push({x, y});
                            }
                        }
                    }
                    area = max(area, local_area);
                }
            }
        }
        return area;
    }
};
// dfs用递归实现，先判断边界条件再搜索
class Solution
{
public:
    vector<int> dir = {-1, 0, 1, 0, -1};
    int m, n;
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        m = grid.size(), n = m ? grid[0].size() : 0;
        int area = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    area = max(area, dfs(grid, i, j));
                }
            }
        }
        return area;
    }
    int dfs(vector<vector<int>> &grid, int a, int b)
    {
        if (grid[a][b] == 0)
            return 0;
        grid[a][b] = 0;
        int area = 1;
        for (int i = 0; i < 4; i++)
        {
            int x = a + dir[i];
            int y = b + dir[i + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1)
            {
                area += dfs(grid, x, y);
            }
        }
        return area;
    }
};
// dfs用递归实现，先搜索再在最开始判断边界条件
class Solution
{
public:
    vector<int> dir = {-1, 0, 1, 0, -1};
    int m, n;
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        m = grid.size(), n = m ? grid[0].size() : 0;
        int area = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    area = max(area, dfs(grid, i, j));
                }
            }
        }
        return area;
    }
    int dfs(vector<vector<int>> &grid, int a, int b)
    {
        if (a < 0 || a >= m || b < 0 || b >= n || grid[a][b] == 0)
            return 0;
        grid[a][b] = 0;
        int area = 1;
        for (int i = 0; i < 4; i++)
        {
            int x = a + dir[i];
            int y = b + dir[i + 1];
            area += dfs(grid, x, y);
        }
        return area;
    }
};