class Solution
{
public:
    vector<int> dir = {-1, 0, 1, 0, -1};
    void backtrack(vector<vector<char>> &board, vector<vector<bool>> &visited, string word, int index, int x, int y)
    {
        if (res)
            return;
        if (index == word.size())
        {
            res = true;
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            if (res)
                return;
            int r = x + dir[i];
            int c = y + dir[i + 1];
            if (r >= 0 && r < n && c >= 0 && c < m && word[index] == board[r][c] && !visited[r][c])
            {
                visited[x][y] = true;
                backtrack(board, visited, word, index + 1, r, c);
                visited[x][y] = false;
            }
        }
    }
    bool res = false;
    int n, m;
    bool exist(vector<vector<char>> &board, string word)
    {
        n = board.size();
        if (n == 0)
            return false;
        m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (res)
                    return res;
                if (word[0] == board[i][j] && !visited[i][j])
                {
                    visited[i][j] = true;
                    backtrack(board, visited, word, 1, i, j);
                    visited[i][j] = false;
                }
            }
        }
        return res;
    }
};