/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-02 20:40:11
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-02 20:40:32
 */
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> myset(nums.begin(), nums.end());
        int longest = 0;
        for (auto x : myset)
        {

            if (myset.find(x - 1) == myset.end())
            {
                int currNum = x;
                int currlen = 1;
                while (myset.find(++currNum) != myset.end())
                    currlen++;
                longest = max(longest, currlen);
            }
        }
        return longest;
    }
};