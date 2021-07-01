//剑指 Offer 48. 最长不含重复字符的子字符串
//双指针+哈希表
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        set<char> myset;
        int res = 0;
        int l = 0;
        for(int r = 0 ;  r < s.size(); r++)
        {   
            if(myset.count(s[r]) == 0)
                myset.insert(s[r]);
            else
            {
                while(s[l] != s[r])
                {
                    myset.erase(s[l]);    
                    l++;
                }
                l++;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};