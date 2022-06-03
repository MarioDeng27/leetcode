/*
 * @Description:
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2022-06-03 19:17:32
 * @LastEditors: Mario Deng
 * @LastEditTime: 2022-06-03 19:17:40
 */
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int l = 0;
        map<char, int> need;
        for (int i = 0; i < t.size(); i++)
        {
            need[t[i]]++;
        }
        map<char, int> windows;
        string res;
        int len = INT_MAX;
        for (int r = 0; r < s.size(); r++)
        {
            if (need.find(s[r]) != need.end())
            {
                windows[s[r]]++;
                if (windows[s[r]] >= need[s[r]])
                {
                    bool isok = true;
                    for (auto it = need.begin(); it != need.end(); it++)
                    {
                        if (windows[it->first] < it->second)
                        {
                            isok = false;
                            break;
                        }
                    }
                    if (isok)
                    {
                        while (need.find(s[l]) == need.end() || windows[s[l]] > need[s[l]])
                        {
                            if (need.find(s[l]) != need.end())
                                windows[s[l]]--;
                            l++;
                        }
                        if (len > r - l + 1)
                        {
                            res = s.substr(l, r - l + 1);
                            len = r - l + 1;
                        }
                        windows[s[l]]--;
                        l++;
                    }
                }
            }
        }
        return res;
    }
};