/*
    双指针实现滑动窗口:

    具体思想:通过r右移, 不断扩张,直到符合条件为止
            通过l右移, 不断缩小窗口宽度,每次缩小之前维护reslen和l,直到不符合条件,返回步骤1


    定义左指针和右指针l和r
    1. r向右移动扩张,遇到合适的字符将其记录到window_m中,直到找到满足符合条件停下来,这边的判断条件是check()
    2. l向右移动缩小,如果遇到字符在need_m中,就将其在window_m中的个数减少1,直到不满足符合条件停下来,也是check(),每次进行判断,只要是符合条件的,维护reslen和resl表示当前最合适的长度和左指针
    3. 当r到达最右边时,如果符合条件的,就移动l直到不满足条件,然后r超出n就结束,因为就算移动l,剩下的字符中肯定是不会满足条件的

    check实现:如果windows对应的字符的数量小于need_m的数量,则肯定是不符合要求的,即该子串是肯定不能覆盖t这个字符串中所有字符的
*/
class Solution
{
public:
    unordered_map<char, int> need_m, window_m;
    bool check()
    {
        for (auto item : need_m)
        {
            if (window_m[item.first] < item.second)
                return false;
        }
        return true;
    }
    string minWindow(string s, string t)
    {

        for (auto c : t)
            ++need_m[c];
        int l = 0, r = -1;
        int reslen = INT_MAX;
        int resl = -1;
        int n = s.size();
        while (r < n)
        {
            if (need_m.find(s[++r]) != need_m.end())
            {
                ++window_m[s[r]];
            }
            while (check() && l <= r)
            {
                if (r - l + 1 < reslen)
                {
                    reslen = r - l + 1;
                    resl = l;
                }
                if (need_m.find(s[l]) != need_m.end())
                    --window_m[s[l]];
                l++;
            }
        }
        if (resl == -1)
            return "";
        return s.substr(resl, reslen);
    }
};