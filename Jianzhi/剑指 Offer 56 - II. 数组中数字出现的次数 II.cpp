/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-16 18:34:43
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-16 18:35:04
 */
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        map<int, int> m;
        int res;
        for (auto num : nums)
        {
            m[num]++;
        }

        for (auto it : m)
        {
            if (it.second == 1)
                return it.first;
        }
        return 0;
    }
};
//凡是出现三次的数字对应位如果是1的话肯定是三的倍数，如果是只出现一次，那么每个对应位要么是1，要么是4，对应于只出现一个数的二进制编码
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        //记录所有数字对应位，1的个数，因为元素是int类型，最长是32位
        vector<int> array(32, 0);
        for (auto const num : nums)
        {
            uint32_t flag = 1;
            for (int i = 0; i < 32; i++)
            {
                if (num & flag)
                    ++array[i];
                flag <<= 1;
            }
        }
        uint32_t res = 0;
        for (int i = 31; i >= 0; i--)
        {
            res <<= 1;
            array[i] = array[i] % 3;
            res |= array[i];
        }

        return res;
    }
};