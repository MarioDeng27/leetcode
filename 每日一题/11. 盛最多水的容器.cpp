/*
 * @Author: your name
 * @Date: 2021-11-27 19:55:57
 * @LastEditTime: 2021-11-27 19:56:18
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \test-asusf:\cpp\leetcode\每日一题\11. 盛最多水的容器.cpp
 */
//时间复杂度为n的平方，超出时间限制
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int minval = min(height[i], height[j]);
                res = max(res, minval * (j - i));
            }
        }
        return res;
    }
};

//时间复杂度为n
//从两端开始缩进，每次缩进的方向是矮的那一端往高的那一端，因为如果反过来肯定是比当前计算的结果更小
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int res = 0;
        int l = 0;
        int r = n - 1;
        while (l < r)
        {
            int index = r;
            if (height[l] < height[r])
            {
                index = l;
            }
            res = max(res, height[index] * (r - l));
            if (index == l)
                l++;
            else
                r--;
        }
        return res;
    }
};