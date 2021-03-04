/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-03 14:45:16
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-03 14:52:13
 */
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n == 0)
            return;
        vector<int> vec(n);
        k = k % n;
        for (int i = 0; i < k; i++)
        {
            vec[i] = nums[n - k + i];
        }
        for (int i = 0; i < n - k; i++)
        {
            vec[k + i] = nums[i];
        }
        nums = vec;
    }
};

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n == 0)
            return;
        k = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};