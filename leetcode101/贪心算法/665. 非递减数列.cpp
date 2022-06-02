/*
 * @Description:
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2022-06-02 19:58:35
 * @LastEditors: Mario Deng
 * @LastEditTime: 2022-06-02 20:03:23
 */
//假设第i-1个数之前都是符合条件，则若出现num[i-1]>nums[i]的情况，按照贪心的想法，要么将nums[i-1]修改为nums[i]，要么将nums[i]修改为nums[i-1],由于前者修改值后会影响这些书之前的鉴别结果，因此需要额外判断是否能这样改，判断条件就是nums[i-1] > nums[i+1]，那么只能将nums[i]修改为nums[i-1]才能满足要求，另一种改发不行。
class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return true;
        int cnt = 0;
        for (int i = 1; i < n; i++)
        {
            int x = nums[i - 1];
            int y = nums[i];
            if (x > y)
            {
                cnt++;
                if (cnt > 1)
                    return false;
                if (i > 1 && nums[i - 2] > y)
                {
                    nums[i] = x;
                }
            }
        }
        return true;
    }
};