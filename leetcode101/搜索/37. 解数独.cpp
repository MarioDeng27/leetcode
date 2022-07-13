class Solution
{
public:
    unordered_set<int> sets[3][3];
    unordered_set<int> cols[9];
    unordered_set<int> rows[9];
    vector<pair<int, int>> waits;
    bool res = false;
    void dfs(vector<vector<char>> &board, int index)
    {
        if (index == waits.size())
        {
            res = true;
            return;
        }
        auto [row, col] = waits[index];
        for (int i = 1; i <= 9; i++)
        {
            if (sets[row / 3][col / 3].count(i) == 0 && rows[row].count(i) == 0 && cols[col].count(i) == 0)
            {
                board[row][col] = '0' + i;
                sets[row / 3][col / 3].insert(i);
                rows[row].insert(i);
                cols[col].insert(i);
                dfs(board, index + 1);
                if (res)
                    return;
                board[row][col] = '.';
                sets[row / 3][col / 3].erase(i);
                rows[row].erase(i);
                cols[col].erase(i);
            }
        }
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char chr = board[i][j];
                if (chr != '.')
                {
                    rows[i].insert(chr - '0');
                    cols[j].insert(chr - '0');
                    sets[i / 3][j / 3].insert(chr - '0');
                }
                else
                {
                    waits.push_back({i, j});
                }
            }
        }
        dfs(board, 0);
    }
};

//高效快速
class Solution
{
public:
    //前两个表示第几行第几列的块，如果第三个值为5，则表示5已经在方块里了
    bool block[3][3][10];
    //前一个表示第几列
    bool cols[9][10];
    //前一个表示第几行
    bool rows[9][10];
    vector<pair<int, int>> waits;
    bool res = false;
    void dfs(vector<vector<char>> &board, int index)
    {
        if (index == waits.size())
        {
            res = true;
            return;
        }
        auto [row, col] = waits[index];
        for (int i = 1; i <= 9; i++)
        {
            if (!block[row / 3][col / 3][i] && !rows[row][i] && !cols[col][i])
            {
                board[row][col] = '0' + i;
                block[row / 3][col / 3][i] = true;
                rows[row][i] = true;
                cols[col][i] = true;
                dfs(board, index + 1);
                if (res)
                    return;
                board[row][col] = '.';
                block[row / 3][col / 3][i] = false;
                rows[row][i] = false;
                cols[col][i] = false;
            }
        }
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        memset(block, false, sizeof(block));
        memset(rows, false, sizeof(rows));
        memset(cols, false, sizeof(cols));
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char chr = board[i][j];
                if (chr != '.')
                {
                    int pos = chr - '0';
                    rows[i][pos] = true;
                    cols[j][pos] = true;
                    block[i / 3][j / 3][pos] = true;
                }
                else
                {
                    waits.push_back({i, j});
                }
            }
        }
        dfs(board, 0);
    }
};