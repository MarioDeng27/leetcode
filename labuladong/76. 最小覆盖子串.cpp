/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-14 14:29:07
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-14 14:53:18
 */
class Solution
{
public:
    string minWindow(string s, string t)
    {
        map<char, int> need;
        map<char, int> windows;
        int valid = 0;
        for (auto chr : t)
            need[chr]++;
        int left = 0;
        int right = 0;
        int start = 0;
        int len = INT_MAX;
        while (right < s.size())
        {
            char chr = s[right];
            right++;

            if (need.count(chr) > 0)
            {
                windows[chr]++;
                if (windows[chr] == need[chr])
                    valid++;
            }

            while (valid == need.size())
            {
                if ((right - left) < len)
                {
                    start = left;
                    len = right - left;
                }
                char tmp = s[left];
                left++;

                if (need.count(tmp) > 0)
                {
                    if (windows[tmp] == need[tmp])
                        valid--;
                    windows[tmp]--;
                }
            }
        }
        if (len == INT_MAX)
            return "";
        return s.substr(start, len);
    }
};