/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-09-30 16:38:05
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-09-30 17:06:40
 */
//动态规划
//第i个柱子所能取得的雨水取决于其左右两边，即[0,i]和[i,n-1]中的最高高度的较小值，那么接的雨水就是这个较小值与height[i]的差值
//所以只要求出第i个柱子左右两边包括i的两个最大值就可以
//leftMax代表[0,i]的最大值
//rightMax代表[i,n-1]的最大值
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (n <= 2)
            return 0;
        vector<int> leftMax(n);
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++)
        {
            leftMax[i] = max(height[i], leftMax[i - 1]);
        }
        vector<int> rightMax(n);
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            rightMax[i] = max(height[i], rightMax[i + 1]);
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res += (min(leftMax[i], rightMax[i]) - height[i]);
        }
        return res;
    }
};
//双指针
/*
    leftMax 用来记录[0,left]的最大值
    rightMax 用来记录[right,n-1]的最大值

    当height[left] < height[right]
    则必定有 leftMax < rightMax (这个证明得一步一步证明：https://leetcode-cn.com/problems/trapping-rain-water/solution/jie-yu-shui-by-leetcode-solution-tuvc/)
    
*/
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int leftMax = 0;
        int rightMax = 0;
        int res = 0;
        while (left < right)
        {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if (height[left] < height[right])
            {
                res += (leftMax - height[left]);
                left++;
            }
            else
            {
                res += (rightMax - height[right]);
                right--;
            }
        }
        return res;
    }
};