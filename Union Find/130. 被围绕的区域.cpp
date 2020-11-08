/*
    方法一：DFS
*/
class Solution
{
public:
    void dfs(vector<vector<char>> &board, vector<bool> &flags, int cur_r, int cur_c)
    {
        int n = board.size();
        int m = board[0].size();
        flags[cur_r * m + cur_c] = true;
        if (cur_r - 1 >= 0 && board[cur_r - 1][cur_c] == 'O' && flags[(cur_r - 1) * m + cur_c] == false) //shang
            dfs(board, flags, cur_r - 1, cur_c);
        if (cur_r + 1 < n && board[cur_r + 1][cur_c] == 'O' && flags[(cur_r + 1) * m + cur_c] == false) //xia
            dfs(board, flags, cur_r + 1, cur_c);
        if (cur_c - 1 >= 0 && board[cur_r][cur_c - 1] == 'O' && flags[cur_r * m + cur_c - 1] == false) //zuo
            dfs(board, flags, cur_r, cur_c - 1);
        if (cur_c + 1 < m && board[cur_r][cur_c + 1] == 'O' && flags[cur_r * m + cur_c + 1] == false) //you
            dfs(board, flags, cur_r, cur_c + 1);
    }
    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        if (n == 0)
            return;
        int m = board[0].size();
        vector<bool> flags(n * m, false);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O' && (i == 0 || i == n - 1 || j == 0 || j == m - 1))
                {
                    flags[i * m + j] = true;
                    dfs(board, flags, i, j);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O' && flags[i * m + j] == false)
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

/*
    方法二:BFS
*/

class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        if (n == 0)
            return;
        int m = board[0].size();
        queue<pair<int, int>> q;
        const int dx[4] = {1, -1, 0, 0};
        const int dy[4] = {0, 0, 1, -1};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O' && (i == 0 || i == n - 1 || j == 0 || j == m - 1))
                {
                    q.push({i, j});
                }
            }
        }
        while (!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            board[x][y] = 'A';
            for (int i = 0; i < 4; i++)
            {
                if (x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < m && board[x + dx[i]][y + dy[i]] == 'O')
                {
                    q.push({x + dx[i], y + dy[i]});
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                if (board[i][j] == 'A')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};