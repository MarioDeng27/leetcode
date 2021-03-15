/*
 * @FilePath: \Sorte:\DataStructures-Algorithms\DataStructures-Algorithms\leetcode\Dynamic Programming\线性动态规划\单串问题\最大子数组和系列\面试题 17.24. 最大子矩阵.cpp
 * @Brief: 
 * @Version: 1.0
 * @Date: 2021-03-13 00:31:35
 * @Author: Mario Deng
 * @Copyright: your copyright description
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-13 00:36:23
 */
//局部的子矩阵，求出每个局部子矩阵的和，然后求出最大值，这是最开始想法

/*
    具体是这样想，对于局部子矩阵，i从第一行开始作为局部子矩阵的首行，然后j作为尾行从首行开始慢慢往下到整个矩阵的最后一行。这样就定义好了高度一定的局部子矩阵，接下来就是移动k，就是列，通过一个列长度为C的数组对应保存每一列从i到j的和，通过连续子序列最大和的算法，算出在这种情况下的最大值。然后之后考虑sum的正负来更新左上角的坐标，然后一旦sum大于历史最大值，就更新res答案。
*/
class Solution
{
public:
    vector<int> getMaxMatrix(vector<vector<int>> &matrix)
    {
        vector<int> res(4, 0);
        int maxSum = INT_MIN;
        int R = matrix.size();
        int C = matrix[0].size();
        int startRow = 0;
        int startCol = 0;
        for (int i = 0; i < R; i++)
        {
            vector<int> helper(C, 0);
            for (int j = i; j < R; j++)
            {
                int sum = 0;
                for (int k = 0; k < C; k++)
                {
                    helper[k] += matrix[j][k];
                    if (sum > 0)
                    {
                        sum += helper[k];
                    }
                    else
                    {
                        sum = helper[k];
                        startRow = i;
                        startCol = k;
                    }
                    if (sum > maxSum)
                    {
                        maxSum = sum;
                        res[0] = startRow;
                        res[1] = startCol;
                        res[2] = j;
                        res[3] = k;
                    }
                }
            }
        }
        return res;
    }
};