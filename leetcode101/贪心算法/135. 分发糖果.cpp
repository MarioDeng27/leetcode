/*
 * @Description:
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2022-06-01 15:24:16
 * @LastEditors: Mario Deng
 * @LastEditTime: 2022-06-01 15:27:33
 */
//若要满足分高者比相邻孩子拿的糖果多，可以进行两次便利，从左往右和从右往左，首先保证右边的孩子高的一定比左边多，这样粒度是+1，就能保证局部最优。再接着从右往左，就是去把第一次遍历没有考虑到的剩下情况给补充了，粒度也是+1，就能保证局部最优，两次加起来就是系统最优。
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> candynums(n, 1);
        for (int i = 1; i < n; i++)
        {
            if (ratings[i - 1] < ratings[i])
            {
                candynums[i] = candynums[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1] && candynums[i] <= candynums[i + 1])
            {
                candynums[i] = candynums[i + 1] + 1;
            }
        }
        /* int res = 0;
        for (int i = 0; i < n; i++)
        {
            res += candynums[i];
        } */
        return accumulate(candynums.begin(), candynums.end(), 0);
    }
};