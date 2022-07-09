class Solution
{
public:
    unordered_set<int> cols;
    unordered_set<int> diags1, diags2;
    vector<vector<string>> res;
    int N;
    void backtrack(vector<string> &matrix, int row)
    {
        if (row == N)
            res.push_back(matrix);
        for (int col = 0; col < N; col++)
        {
            if (cols.find(col) == cols.end() && diags1.find(row + col) == diags1.end() && diags2.find(row - col) == diags2.end())
            {
                cols.insert(col);
                diags1.insert(row + col);
                diags2.insert(row - col);
                matrix[row][col] = 'Q';
                backtrack(matrix, row + 1);
                cols.erase(col);
                diags1.erase(row + col);
                diags2.erase(row - col);
                matrix[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        N = n;
        vector<string> matrix(n, string(n, '.'));
        for (int i = 0; i < n; i++)
        {
            cols.insert(i);
            diags1.insert(i);
            diags2.insert(-i);
            matrix[0][i] = 'Q';
            backtrack(matrix, 1);
            cols.erase(i);
            diags1.erase(i);
            diags2.erase(-i);
            matrix[0][i] = '.';
        }
        return res;
    }
};