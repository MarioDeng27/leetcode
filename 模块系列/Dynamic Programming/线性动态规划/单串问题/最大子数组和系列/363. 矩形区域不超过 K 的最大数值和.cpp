/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-14 16:56:56
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-14 16:58:45
 */

/*
    固定好高度之后得枚举所以不同宽度的值，通过筛选选出符合条件的最大值
*/
class Solution
{
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
    {
        int R = matrix.size();
        int C = matrix[0].size();
        int maxSum = INT_MIN;
        for (int i = 0; i < R; i++)
        {
            vector<int> array(C, 0);
            for (int j = i; j < R; j++)
            {
                for (int col = 0; col < C; col++)
                {
                    array[col] += matrix[j][col];
                }
                for (int col = 0; col < C; col++)
                {
                    int sum = 0;
                    for (int m = col; m < C; m++)
                    {
                        sum += array[m];
                        if (sum > maxSum && sum <= k)
                            maxSum = sum;
                    }
                }
            }
        }
        return maxSum;
    }
};