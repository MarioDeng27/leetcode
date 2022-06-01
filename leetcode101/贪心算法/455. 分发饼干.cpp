/*
 * @Description:
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2022-06-01 14:49:25
 * @LastEditors: Mario Deng
 * @LastEditTime: 2022-06-01 14:50:22
 */
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = 0;
        int res = 0;
        for (int i = 0; i < g.size(); i++)
        {
            while (index < s.size())
            {
                if (g[i] <= s[index++])
                {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};