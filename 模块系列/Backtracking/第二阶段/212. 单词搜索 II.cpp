/*
 * @Description: https://leetcode-cn.com/problems/word-search-ii/
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2020-12-04 20:54:16
 * @LastEditors: Mario Deng
 * @LastEditTime: 2020-12-04 20:54:17
 */
/*
    自己的想法,就是79题的应用,将words分为多次word进行查询

*/
class Solution
{
public:
    bool res = false;
    vector<string> ans;
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
            ans.push_back(word);
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
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        R = board.size();
        C = board[0].size();
        for (auto word : words)
        {
            res = false;
            char ch = word[0];
            vector<vector<bool>> visited(R, vector<bool>(C, false));
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
        }
        return ans;
    }
};