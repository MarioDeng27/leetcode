/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-07 16:20:41
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-07 16:20:41
 */
class Solution
{
public:
    vector<vector<int>> help;
    set<int> col;
    set<int> diag1;
    set<int> diag2;
    void backtrack(int n, int row, vector<int> &track)
    {
        if (n == row)
            help.push_back(track);
        for (int i = 0; i < n; i++)
        {
            if (col.find(i) != col.end())
                continue;
            if (diag1.find(row + i) != diag1.end())
                continue;
            if (diag2.find(row - i) != diag2.end())
                continue;
            col.insert(i);
            diag1.insert(row + i);
            diag2.insert(row - i);
            track.push_back(i);
            backtrack(n, row + 1, track);
            track.pop_back();
            col.erase(i);
            diag1.erase(row + i);
            diag2.erase(row - i);
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<int> track;
        backtrack(n, 0, track);
        vector<vector<string>> res;
        for (int i = 0; i < help.size(); i++)
        {
            vector<string> temp;
            for (int j = 0; j < help[i].size(); j++)
            {
                string str(n, '.');
                str[help[i][j]] = 'Q';
                temp.push_back(str);
            }
            res.push_back(temp);
        }
        return res;
    }
};