/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-02-28 22:08:38
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-02-28 22:08:38
 */
class Solution
{
public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size();
        if (row == 0)
            return false;
        int col = matrix[0].size();
        int i = 0;
        int j = col - 1;
        while (i < row && j >= 0)
        {
            if (matrix[i][j] > target)
                j--;
            else if (matrix[i][j] < target)
                i++;
            else
                return true;
        }
        return false;
    }
};