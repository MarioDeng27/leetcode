/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-16 17:18:39
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-16 17:18:40
 */
class Solution
{
public:
    vector<int> singleNumbers(vector<int> &nums)
    {
        int seed = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            seed = seed ^ nums[i];
        }
        uint32_t flag = 1;
        while (seed && flag <= seed)
        {
            if (seed & flag)
                break;
            flag = flag << 1;
        }
        vector<int> A, B;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] & flag)
                A.push_back(nums[i]);
            else
                B.push_back(nums[i]);
        }
        int a = A[0];
        for (int i = 1; i < A.size(); i++)
        {
            a = a ^ A[i];
        }
        int b = B[0];
        for (int j = 1; j < B.size(); j++)
        {
            b = b ^ B[j];
        }
        return {a, b};
    }
};

class Solution
{
public:
    vector<int> singleNumbers(vector<int> &nums)
    {
        int seed = 0;
        for (auto num : nums)
        {
            seed ^= num;
        }
        uint32_t flag = 1;
        while (!(seed & flag))
        {
            flag <<= 1;
        }
        int a = 0, b = 0;
        for (auto num : nums)
        {
            if (num & flag)
                a ^= num;
            else
                b ^= num;
        }
        return {a, b};
    }
};