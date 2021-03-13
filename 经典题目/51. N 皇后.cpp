/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-13 14:03:14
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-13 14:03:16
 */
class Solution
{
public:
    vector<vector<string>> res;
    unordered_set<int> cols;
    unordered_set<int> diag1;
    unordered_set<int> diag2;
    vector<string> int2String(vector<int> queens, int n)
    {
        vector<string> res;
        for (int i = 0; i < queens.size(); i++)
        {
            string str(n, '.');
            str[queens[i]] = 'Q';
            res.push_back(str);
        }
        return res;
    }
    void backTrack(vector<int> &queens, int n, int row)
    {
        if (row == n)
        {
            vector<string> queensStr = int2String(queens, n);
            res.push_back(queensStr);
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (cols.count(i) != 0)
                    continue;
                if (diag1.count(i - row) != 0)
                    continue;
                if (diag2.count(i + row) != 0)
                    continue;
                queens[row] = i;
                cols.insert(i);
                diag1.insert(i - row);
                diag2.insert(i + row);
                backTrack(queens, n, row + 1);
                queens[row] = -1;
                cols.erase(i);
                diag1.erase(i - row);
                diag2.erase(i + row);
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<int> queens(n, -1);
        backTrack(queens, n, 0);
        return res;
    }
};