/*
 * @Description:
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2022-06-05 03:43:54
 * @LastEditors: Mario Deng
 * @LastEditTime: 2022-06-05 03:44:03
 */
class Solution
{
public:
    bool check(string s, int low, int high)
    {
        while (low <= high)
        {
            if (s[low] == s[high])
            {
                low++;
                high--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s)
    {
        int l = 0;
        int r = s.size() - 1;
        int cnt = 0;
        while (l <= r)
        {
            if (s[l] == s[r])
            {
                l++;
                r--;
            }
            else
            {
                return check(s, l + 1, r) || check(s, l, r - 1);
            }
        }
        return true;
    }
};