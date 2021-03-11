/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-10 12:00:27
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-10 12:00:48
 */
class Solution
{
public:
    bool isStraight(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int countOf0 = 0;
        int gaps = 0;
        int prev = nums[0];
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == 0)
                countOf0++;
            else
            {
                if (nums[i] == nums[i + 1])
                    return false;
                gaps += nums[i + 1] - nums[i] - 1;
            }
        }
        return gaps <= countOf0;
    }
};