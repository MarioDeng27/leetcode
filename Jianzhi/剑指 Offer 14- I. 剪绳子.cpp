/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-07 05:14:30
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-07 13:28:57
 */

//动态规划，找到前面的几个状态，当前状态可以由前几个状态来推，从而求出最优解
class Solution
{
public:
    int cuttingRope(int n)
    {
        //考虑一些特殊情况，如长度1，2，3.只有当长度4的时候才能用递推的方式，前面的几个相当于是最小因子，不能再分的问题
        if (n < 2)
            return 0;
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        vector<int> products(n + 1);
        products[0] = 0;
        products[1] = 1;
        products[2] = 2;
        products[3] = 3;

        for (int i = 4; i <= n; i++)
        {
            int maxVal = 0;
            for (int j = 1; j <= i / 2; j++)
            {
                maxVal = max(maxVal, products[j] * products[i - j]);
            }
            products[i] = maxVal;
        }
        return products[n];
    }
};

//方法二：贪婪算法：需要用到扎实的数学功底，找规律
class Solution
{
public:
    int cuttingRope(int n)
    {
        if (n < 2)
            return 0;
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        int timeOf3 = n / 3;
        if ((n - timeOf3 * 3) == 1)
            timeOf3 -= 1;
        int timeOf2 = (n - timeOf3 * 3) / 2;

        return (pow(3, timeOf3) * pow(2, timeOf2));
    }
};