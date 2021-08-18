/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2020-12-03 16:39:58
 * @LastEditors: Mario Deng
 * @LastEditTime: 2020-12-03 16:43:19
 */
/*
    自己的想法,先找出board中符合word第一个字符的所有索引坐标
    然后放入backtrack的函数里去一层一层找,如果最后一个word最后一个字符与board中连续的单元的其中一个相同,并且index长度等于word的长度
    则证明单词board中有单词找到

    每一个board中的元素要去判断是否和当前索引的word中的字符相等时,visited对应索引要true,证明这个单词被用过,当后面的情况不符合条件时,则在恢复false状态


*/
class Solution
{
public:
    bool res = false;
    int R;
    int C;
    void backtrack(vector<vector<char>> &board, vector<vector<bool>> &visited, string word, int index, int row, int col)
    {
        if (word[index] != board[row][col])
            return;
        index++;
        if (index == word.size())
        {
            res = true;
            return;
        }
        if (res == true)
            return;
        if (row - 1 >= 0 && visited[row - 1][col] == false && res == false)
        {
            visited[row - 1][col] = true;
            backtrack(board, visited, word, index, row - 1, col);
            visited[row - 1][col] = false;
        }
        if (row + 1 < R && visited[row + 1][col] == false && res == false)
        {
            visited[row + 1][col] = true;
            backtrack(board, visited, word, index, row + 1, col);
            visited[row + 1][col] = false;
        }
        if (col - 1 >= 0 && visited[row][col - 1] == false && res == false)
        {
            visited[row][col - 1] = true;
            backtrack(board, visited, word, index, row, col - 1);
            visited[row][col - 1] = false;
        }
        if (col + 1 < C && visited[row][col + 1] == false && res == false)
        {
            visited[row][col + 1] = true;
            backtrack(board, visited, word, index, row, col + 1);
            visited[row][col + 1] = false;
        }
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        R = board.size();
        C = board[0].size();
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        char ch = word[0];
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (visited[i][j] == false && board[i][j] == ch)
                {
                    visited[i][j] = true;
                    backtrack(board, visited, word, 0, i, j);
                    visited[i][j] = false;
                }
                if (res == true)
                    break;
            }
            if (res == true)
                break;
        }
        return res;
    }
};
