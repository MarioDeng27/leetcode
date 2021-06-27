/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-06-28 00:16:56
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-06-28 00:43:55
 */
//5782. 最大子序列交替和
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) 
    {
        if(nums.size() == 0)
            return 0;
        long long res = 0;
        int pre = 0;
        //pre记录当天的前一天买入的价格，而当今天的价格比前一天的价格高，则以该高价卖出，并且获取利润放入res（钱包里）
        //如果当今天的价格不高于前一天的价格，则还是以pre的价格卖出，相当于前一天没有买入的意思，并且再以今天的高价买入，为下一次的更高价作准备
        //总结：只要当天价格比前一天价格高，则算入res里（因为2 4 6选两个数，后一个比前一个高，则会选择2 6 ，而这个程序的过程就是 4-2 + 6 - 4， 抵消了4的中间价的感觉，所以4相当于中间变量，用于计算）
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i]>pre)
            {
                res += (nums[i] - pre);
            }
            pre = nums[i];
        }
        return res;
    }
};

//动态规划：https://leetcode-cn.com/problems/maximum-alternating-subsequence-sum/solution/zui-da-zi-xu-lie-jiao-ti-he-by-leetcode-epqrk/
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) 
    {
        if(nums.size() == 0)
            return 0;
        long long odd = 0;
        long long even = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            odd = max(even - nums[i], odd); // 对于odd这样的子序列中找出最后一个下标元素是奇数的最大交替和，可以有两种选择，即选择当前的nums[i],即从之前的even转变过来，要么不选，还是用之前的odd来作为新的odd
            even = max(odd + nums[i], even);// 同理even
        }
        return max(odd, even);
    }
};