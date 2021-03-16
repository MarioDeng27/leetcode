/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-16 15:59:06
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-16 16:09:48
 */
//每次让n与1进行位与运算，这样就可以判断出最右边那一位是否是1，然后最后向右移一位，但是得注意，如果n本身是负数，这种方法不能用。主要是右移n
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int cnt = 0;
        while (n)
        {
            if (n & 1)
                cnt++;
            n = n >> 1;
        }
        return cnt;
    }
};
//初始化uint32_t flag = 1，每次n与flag进行位与运算，第一次可以判断出最右边是否为1，然后对flag进行左移1位，再与flag进行&，则可以判断次右边是否为1.主要是左移flag
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int cnt = 0;
        uint32_t flag = 1;
        while (flag && n >= flag)
        {
            if (n & flag)
                cnt++;
            flag = flag << 1;
        }
        return cnt;
    }
};
/*
    须知：有一个整数n,如果将n-1后再与n进行位与运算，则结果相当于把之前n最右边的1取反为0了，最右边1的左边的位保持不变
*/
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int cnt = 0;
        while (n)
        {
            cnt++;
            n = n & (n - 1);
        }
        return cnt;
    }
};