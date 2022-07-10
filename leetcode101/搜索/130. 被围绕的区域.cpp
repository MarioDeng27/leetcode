class Solution
{
public:
    int m, n;
    vector<int> dir = {-1, 0, 1, 0, -1};
    void dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, int r, int c, vector<pair<int, int>> &path, bool &res)
    {
        if (r == 0 || r == m - 1 || c == 0 || c == n - 1)
        {
            res = false;
        }
        for (int i = 0; i < 4; i++)
        {
            int x = r + dir[i];
            int y = c + dir[i + 1];
            if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O' && !visited[x][y])
            {
                visited[x][y] = true;
                path.push_back({x, y});
                dfs(board, visited, x, y, path, res);
            }
        }
    }
    void solve(vector<vector<char>> &board)
    {
        m = board.size();
        n = m ? board[0].size() : 0;
        if (!m || !n)
            return;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                vector<pair<int, int>> path;
                if (board[i][j] == 'O' && !visited[i][j])
                {
                    visited[i][j] = true;
                    path.push_back({i, j});
                    bool flag = true;
                    dfs(board, visited, i, j, path, flag);
                    if (flag)
                    {
                        for (auto [r, c] : path)
                        {
                            board[r][c] = 'X';
                        }
                    }
                }
            }
        }
    }
};