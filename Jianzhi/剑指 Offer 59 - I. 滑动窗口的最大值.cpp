/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-02 22:47:51
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-07-02 22:47:51
 */
//剑指 Offer 59 - I. 滑动窗口的最大值
//自己的方法：
//滑动窗口的最大值，如果刚好再滑动后的有边界就是当前最大值
//不满足上面情况，如果滑动前的左边界需要考虑是不是最大值，如果是，则要重新去找窗口内的最大值
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        if(nums.size() == 0)
            return {};
        int maxVal = nums[0];
        for(int i = 1 ; i < k; i++)
        {
            if(maxVal < nums[i])
                maxVal = nums[i];
        }
        vector<int> res;
        res.push_back(maxVal);
        for(int i = k ; i < nums.size();i++)
        {
            if(nums[i-k] == maxVal&&nums[i] < maxVal)
            {
                int start = i - k + 1;
                int val = nums[start];
                for(int j = start; j <=i; j++)
                {
                    if(val < nums[j])
                        val = nums[j];
                }
                maxVal = val;
            }
            else if(nums[i]>= maxVal)
                maxVal = nums[i];
            res.push_back(maxVal);
        }
        return res;
    }
};