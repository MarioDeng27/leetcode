/*
 * @Description:
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2022-06-04 18:35:01
 * @LastEditors: Mario Deng
 * @LastEditTime: 2022-06-05 03:26:29
 */
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        long c1 = c;
        long r = sqrt(c1);
        long l = 0;
        while (l <= r)
        {
            long t = l * l + r * r;
            if (t < c1)
            {
                l++;
            }
            else if (t > c1)
            {
                r--;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};