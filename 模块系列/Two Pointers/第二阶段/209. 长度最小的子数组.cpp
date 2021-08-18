/*
    双指针实现滑动窗口,具体可以参照76题模板来写
*/

class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int n = nums.size();
        int ansleft = -1;
        int anslen = INT_MAX;
        int l = 0, r = -1;
        int sum = 0;
        while (r < n - 1)
        {
            if (sum < s)
            {
                sum += nums[++r];
            }
            while (sum >= s && l <= r)
            {
                if (r - l + 1 < anslen)
                {
                    ansleft = l;
                    anslen = r - l + 1;
                }
                sum -= nums[l];
                l++;
            }
        }
        if (ansleft == -1)
            return 0;
        return anslen;
    }
};