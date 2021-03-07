/*
 * @FilePath: \Sorte:\DataStructures-Algorithms\DataStructures-Algorithms\leetcode\Jianzhi\剑指 Offer 13. 机器人的运动范围.cpp
 * @Brief: 
 * @Version: 1.0
 * @Date: 2021-03-06 14:42:22
 * @Author: Mario Deng
 * @Copyright: your copyright description
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-06 14:42:43
 */
class Solution
{
public:
    int movingCount(int m, int n, int k)
    {
        if (m < 0 || n < 0 || k < 0)
            return 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count = movingCountCore(m, n, k, 0, 0, visited);
        return count;
    }

    int movingCountCore(int m, int n, int k, int row, int col, vector<vector<bool>> &visited)
    {
        int count = 0;
        if (row >= 0 && row < m && col >= 0 && col < n && visited[row][col] == false && (getSum(row) + getSum(col) <= k))
        {
            visited[row][col] = true;
            count = 1 + movingCountCore(m, n, k, row - 1, col, visited) + movingCountCore(m, n, k, row + 1, col, visited) + movingCountCore(m, n, k, row, col - 1, visited) + movingCountCore(m, n, k, row, col + 1, visited);
        }

        return count;
    }
    int getSum(int num)
    {
        int sum = 0;
        while (num != 0)
        {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};