/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-01 00:39:23
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-07-01 00:40:23
 */
//剑指 Offer 47. 礼物的最大价值
//方法1:动态规划，速度快，转移方程简单
class Solution {
public:
    
    int maxValue(vector<vector<int>>& grid) 
    {
        int R = grid.size();
        int C = grid[0].size();
        vector<vector<int>> dp(R+1,vector<int>(C+1,0));

        for(int i = R-1; i >= 0; i--)
        {
            for(int j = C-1; j>= 0; j--)
            {
                dp[i][j] = max(dp[i+1][j],dp[i][j+1])+grid[i][j];
            }
        }
       return dp[0][0];
    }
};

//方法2:有记忆的递归，但到最后一个case 的时候还是超出了时间限制
class Solution {
public:
    map<pair<int,int>,int> m;
    int getValue(vector<vector<int>>& grid, int r, int c)
    {
        if(r == grid.size()-1&& c == grid[0].size()-1)
            return grid[r][c];
        if(r >= grid.size()||c >= grid[0].size())
            return 0;
        
        int val1;
        int val2;
        if(m.count({r+1,c}) > 0)
            val1 = m[{r+1,c}];
        else
        {
            val1 = getValue(grid,r+1,c);
            m[{r+1,c}] = val1;
        }
            val1 = getValue(grid,r+1,c);
        if(m.count({r,c+1}) > 0)
            val2 = m[{r,c+1}];
        else
        {
            val2 = getValue(grid,r,c+1);
            m[{r,c+1}] = val2;
        }
        return grid[r][c] + max(val1,val2);
    }
    int maxValue(vector<vector<int>>& grid) 
    {
        return getValue(grid,0,0);
    }
};