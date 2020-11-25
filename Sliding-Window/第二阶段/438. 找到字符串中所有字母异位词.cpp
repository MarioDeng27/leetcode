/*
    双指针实现滑动窗口,窗口宽度必定要满足p的大小
*/

class Solution
{
public:
    unordered_map<char, int> need_m, window_m;
    bool check()
    {
        for (auto item : need_m)
        {
            if (window_m[item.first] != item.second)
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p)
    {

        for (auto c : p)
            ++need_m[c];
        int l = 0, r = -1;
        int n = s.size();
        vector<int> res;
        while (r < n - 1)
        {
            if (need_m.find(s[++r]) != need_m.end())
            {
                ++window_m[s[r]];
            }
            if (r - l + 1 == p.size())
            {
                if (check())
                    res.push_back(l);
                if (need_m.find(s[l]) != need_m.end())
                {
                    --window_m[s[l]];
                }
                l++;
            }
        }
        return res;
    }
};

/*
    改良版:
    通过valid标志位来判断,子串和p是否符合要求

*/
class Solution
{
public:
    unordered_map<char, int> need_m, window_m;
    vector<int> findAnagrams(string s, string p)
    {

        for (auto c : p)
            ++need_m[c];
        int l = 0, r = -1;
        int n = s.size();
        vector<int> res;
        int valid = 0;
        while (r < n - 1)
        {
            if (need_m.find(s[++r]) != need_m.end())
            {
                ++window_m[s[r]];
                if (window_m[s[r]] == need_m[s[r]])
                {
                    valid++;
                }
            }
            if (r - l + 1 == p.size())
            {
                if (valid == need_m.size())
                    res.push_back(l);
                if (need_m.find(s[l]) != need_m.end())
                {
                    if (window_m[s[l]] == need_m[s[l]])
                        valid--;
                    --window_m[s[l]];
                }
                l++;
            }
        }
        return res;
    }
};