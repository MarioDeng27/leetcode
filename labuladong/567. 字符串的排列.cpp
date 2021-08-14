/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-14 14:53:56
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-14 14:53:57
 */
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        map<char, int> need;
        map<char, int> windows;
        for (auto chr : s1)
            need[chr]++;
        int left = 0;
        int right = 0;
        int valid = 0;

        while (right < s2.size())
        {
            char chr = s2[right];
            right++;
            if (need.count(chr) > 0)
            {
                windows[chr]++;
                if (windows[chr] == need[chr])
                    valid++;
            }
            while (right - left >= s1.size())
            {
                if (valid == need.size())
                    return true;
                char tmp = s2[left];
                left++;
                if (need.count(tmp) > 0)
                {
                    if (windows[tmp] == need[tmp])
                        valid--;
                    windows[tmp]--;
                }
            }
        }
        return false;
    }
};