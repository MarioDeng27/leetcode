/*
 * @FilePath: \Sorte:\DataStructures-Algorithms\DataStructures-Algorithms\leetcode\Jianzhi\剑指 Offer 43. 1～n 整数中 1 出现的次数.cpp
 * @Brief: 
 * @Version: 1.0
 * @Date: 2021-04-10 21:04:21
 * @Author: Mario Deng
 * @Copyright: your copyright description
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-04-10 21:04:22
 */
//https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/solution/mian-shi-ti-43-1n-zheng-shu-zhong-1-chu-xian-de-2/
class Solution
{
public:
    int countDigitOne(int n)
    {
        int res = 0;
        int high = n / 10;
        int cur = n % 10;
        int low = 0;
        long digit = 1;
        while (high != 0 || cur != 0)
        {
            if (cur == 0)
            {
                res += high * digit;
            }
            else if (cur == 1)
            {
                res += high * digit + low + 1;
            }
            else
            {
                res += (high + 1) * digit;
            }
            low += cur * digit;
            cur = high % 10;
            high = high / 10;
            digit = digit * 10;
        }
        return res;
    }
};