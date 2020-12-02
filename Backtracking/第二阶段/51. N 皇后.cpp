/*
 * @Description: https://leetcode-cn.com/problems/n-queens/
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2020-12-02 18:05:36
 * @LastEditors: Mario Deng
 * @LastEditTime: 2020-12-02 18:12:29
 */
/*
    N皇后必须得满足,每个皇后不在同一行,列,斜线上:也就是说每一行,列,斜线只有一个皇后可以占据,位置可以用[row][col]来表示
    1. 行可以通过递归,每次row+1,然后track将上一次的对应row的一整行string(只含一个Q,放哪列后面会判断)插入尾部,这样就满足每一行就一个Q
    2. 列的话只要记录之前每一行所占的列索引,让当前行的Q不占据这些列就好
    3. 斜线的话,只要记录之前每一行所占据的斜线,让当前行的Q不占据这些斜线就好

    列可以维护一个集合,如果一个col不在集合里,那么这个col肯定与之前的行的Q不在同一列
    斜线维护两个集合(一个左上到右下,一个右上到左下),如果col-row/col+row 不在这个集合里,那么这个col肯定与之前的行的Q不在同一斜线

*/
class Solution
{
public:
    vector<vector<string>> res;
    void backtrack(int n, int row, vector<string> &track, unordered_set<int> &columns, unordered_set<int> &diagonals1, unordered_set<int> &diagonals2)
    {
        if (row == n)
        {
            res.push_back(track);
            return;
        }
        string temp(n, '.');
        for (int col = 0; col < n; col++)
        {
            if (columns.find(col) != columns.end())
            {
                continue;
            }
            int diagonal1 = row - col;
            if (diagonals1.find(diagonal1) != diagonals1.end())
            {
                continue;
            }
            int diagonal2 = row + col;
            if (diagonals2.find(diagonal2) != diagonals2.end())
            {
                continue;
            }
            temp[col] = 'Q';
            columns.insert(col);
            diagonals1.insert(diagonal1);
            diagonals2.insert(diagonal2);
            track.push_back(temp);
            backtrack(n, row + 1, track, columns, diagonals1, diagonals2);
            temp[col] = '.';
            columns.erase(col);
            diagonals1.erase(diagonal1);
            diagonals2.erase(diagonal2);
            track.pop_back();
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> track;
        unordered_set<int> columns;
        unordered_set<int> diagonals1;
        unordered_set<int> diagonals2;
        backtrack(n, 0, track, columns, diagonals1, diagonals2);
        return res;
    }
};