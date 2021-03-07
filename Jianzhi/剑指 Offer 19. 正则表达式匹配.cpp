/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-07 17:44:35
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-07 17:44:56
 */
//超出时间限制了。。。。
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        return isMatchCore(s, 0, p, 0);
    }
    bool isMatchCore(string s, int sIndex, string p, int pIndex)
    {
        int sSize = s.size() - sIndex;
        int pSize = p.size() - pIndex;
        if (sSize == 0)
        {
            if (pSize % 2 != 0)
                return false;
            else
            {
                int i = pIndex + 1;
                while (i < pSize)
                {
                    if (p[i] != '*')
                        return false;
                    i += 2;
                }
                return true;
            }
        }
        else
        {
            if (pSize == 0)
                return false;
        }

        char sCurr = s[sIndex];
        char pCurr = p[pIndex];
        char pNext = 'a';
        if (pIndex + 1 < p.size())
            pNext = p[pIndex + 1];
        if (pNext != '*')
        {
            if (sCurr == pCurr || pCurr == '.')
                return isMatchCore(s, sIndex + 1, p, pIndex + 1);
            else
                return false;
        }
        else
        {
            if (sCurr == pCurr || pCurr == '.')
                return isMatchCore(s, sIndex + 1, p, pIndex) || isMatchCore(s, sIndex, p, pIndex + 2);
            else
                return isMatchCore(s, sIndex, p, pIndex + 2);
        }
        return false;
    }
};