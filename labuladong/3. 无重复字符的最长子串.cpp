/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-16 20:31:19
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-16 20:31:19
 */
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0)
            return 0;
        int left = 0, right = 0;
        int res = 0;
        unordered_set<char> window;
        while (right < s.size())
        {
            char chr = s[right];
            right++;
            if (window.count(chr) == 0)
            {
                window.insert(chr);
                res = max(res, right - left);
            }
            else if (window.count(chr) > 0)
            {
                while (s[left] != chr)
                {
                    window.erase(s[left]);
                    left++;
                }
                left++;
            }
        }
        return res;
    }
};