/*
 * @FilePath: \Sorte:\DataStructures-Algorithms\DataStructures-Algorithms\leetcode\Jianzhi\剑指 Offer 12. 矩阵中的路径.cpp
 * @Brief: 
 * @Version: 1.0
 * @Date: 2021-03-06 14:06:10
 * @Author: Mario Deng
 * @Copyright: your copyright description
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-06 14:06:11
 */
/*
 * @FilePath: \Sorte:\DataStructures-Algorithms\DataStructures-Algorithms\leetcode\Jianzhi\剑指 Offer 12. 矩阵中的路径.cpp
 * @Brief: 
 * @Version: 1.0
 * @Date: 2021-03-06 14:06:10
 * @Author: Mario Deng
 * @Copyright: your copyright description
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-06 14:06:10
 */
class Solution {
public:
    int rows;
    int cols;
    bool exist(vector<vector<char>>& board, string word)
    {
        rows = board.size();
        if(rows == 0||word.size()==0)
            return false;
        cols = board[0].size();
        vector<vector<bool>>visited(board.size(),vector<bool>(board[0].size(),false));
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0 ; j < cols; j++)
            {
                bool hasFound = hasPath(board,i,j,word,0,visited);
                if(hasFound == true)
                    return true;
            }
        }
        return false;
    }
    bool hasPath(vector<vector<char>>&board,int row,int col,string word,int pathLen,vector<vector<bool>>&visited)
    {
        if(pathLen == word.size())
            return true;
        bool hasFound = false;
        if(row>=0&&row<rows&&col>=0&&col<cols&&visited[row][col]==false&&word[pathLen]==board[row][col])
        {
            visited[row][col]=true;
            //if(row+1<rows&&visted[row+1][col]==false)
            hasFound = hasPath(board,row-1,col,word,pathLen+1,visited)||hasPath(board,row+1,col,word,pathLen+1,visited)||hasPath(board,row,col-1,word,pathLen+1,visited)||hasPath(board,row,col+1,word,pathLen+1,visited);
            visited[row][col] = false;
        }
        return hasFound;
    }
};