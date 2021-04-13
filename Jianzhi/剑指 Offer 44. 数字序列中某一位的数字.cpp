/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-04-11 16:18:23
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-04-11 16:18:25
 */
class Solution
{
public:
    int findNthDigit(int n)
    {
        if (n == 0)
            return 0;
        //n其实求的是第n+1个位置的数字
        long start = 1;         //每一个digit对应的第一个元素
        long digit = 1;         //数字的长度
        long countofnums = 9;   //每一种数字的长度共有的数字
        long countofdigits = 9; //每一种数字的长度共有的位数
        //找到对应的数字长度类型，以及从start开始，初始索引是1，的第n个（以及处理过n）的位数,n处理后是不可能为0的，它一定大于0.因为n>countofdigits这个条件
        while (n > countofdigits)
        {
            n -= countofdigits;
            start *= 10;
            digit++;
            countofnums *= 10;
            countofdigits = digit * countofnums;
        }

        //找到对应的数字
        long num = start + (n - 1) / digit;
        //找到对应数字的对应的位的数值
        int pos = (n - 1) % digit;
        string str = to_string(num);
        return str[pos] - '0';
    }
};