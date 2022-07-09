/*
 * @Description:
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2022-07-08 11:07:28
 * @LastEditors: Mario Deng
 * @LastEditTime: 2022-07-08 11:08:51
 */
//先DFS找到第一个岛屿，然后通过BFS蔓延并记录途中的海洋格子数，值得注意的是找到一个海洋格子就要快速把它标记为已寻找过，不然时间复杂度会增加
class Solution
{
public:
    vector<int> dir = {-1, 0, 1, 0, -1};
    int m, n;
    void dfs(queue<pair<int, int>> &points, vector<vector<int>> &grid, int r, int c)
    {
        if (grid[r][c] == 0)
        {
            grid[r][c] = 2;
            points.push({r, c});
            return;
        }
        grid[r][c] = 2;
        for (int i = 0; i < 4; i++)
        {
            int x = r + dir[i];
            int y = c + dir[i + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != 2)
            {
                dfs(points, grid, x, y);
            }
        }
    }
    int shortestBridge(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = m ? grid[0].size() : 0;
        if (m == 0 || n == 0)
            return 0;
        queue<pair<int, int>> points;
        bool isfound = false;
        for (int i = 0; i < m; i++)
        {
            if (isfound)
                break;
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    dfs(points, grid, i, j);
                    isfound = true;
                    break;
                }
            }
        }
        int level = 0;
        while (!points.empty())
        {
            level++;
            int size = points.size();
            while (size--)
            {
                auto [r, c] = points.front();
                points.pop();
                for (int i = 0; i < 4; i++)
                {
                    int x = r + dir[i];
                    int y = c + dir[i + 1];
                    if (x >= 0 && x < m && y >= 0 && y < n)
                    {
                        if (grid[x][y] == 2)
                            continue;
                        if (grid[x][y] == 1)
                            return level;
                        points.push({x, y});
                        grid[x][y] = 2;
                    }
                }
            }
        }
        return level;
    }
};