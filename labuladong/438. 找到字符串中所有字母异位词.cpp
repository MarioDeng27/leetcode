/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-16 20:08:21
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-16 20:08:31
 */
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        unordered_map<char, int> need, window;
        int valid = 0;
        vector<int> res;
        for (auto chr : p)
            need[chr]++;
        int left = 0, right = 0;
        while (right < s.size())
        {
            char chr = s[right];
            right++;
            if (need.count(chr) > 0)
            {
                window[chr]++;
                if (window[chr] == need[chr])
                    valid++;
            }

            while (right - left == p.size())
            {
                if (valid == need.size())
                    res.push_back(left);
                char tmp = s[left];
                left++;
                if (need.count(tmp) > 0)
                {
                    if (window[tmp] == need[tmp])
                        valid--;
                    window[tmp]--;
                }
            }
        }
        return res;
    }
};