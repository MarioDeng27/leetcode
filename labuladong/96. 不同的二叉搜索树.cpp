/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-02 19:51:09
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-02 19:51:09
 */
class Solution
{
    map<pair<int, int>, int> memory;

public:
    int count(int min, int max)
    {
        if (min > max)
        {
            return 1;
        }
        if (memory.count({min, max}) == 1)
            return memory[{min, max}];
        int res = 0;
        for (int i = min; i <= max; i++)
        {
            int leftcnt = count(min, i - 1);
            int rightcnt = count(i + 1, max);
            res += leftcnt * rightcnt;
        }
        memory[{min, max}] = res;
        return res;
    }
    int numTrees(int n)
    {
        return count(1, n);
    }
};