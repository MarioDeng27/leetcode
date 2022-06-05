/*
 * @Description:
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2022-06-05 17:58:57
 * @LastEditors: Mario Deng
 * @LastEditTime: 2022-06-05 17:59:02
 */
class Solution
{
public:
    int mySqrt(int a)
    {
        if (a == 0)
            return a;
        int l = 1, r = a, mid, sqrt;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            sqrt = a / mid;
            if (mid < sqrt)
            {
                l = mid + 1;
            }
            else if (mid > sqrt)
            {
                r = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        return r;
    }
};