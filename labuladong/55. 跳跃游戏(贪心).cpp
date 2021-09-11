/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-09-09 22:37:54
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-09-10 00:58:18
 */
//贪心算法
/*
    如果能保证每个格子都能到，则通过数组最远可以到达 i+nums[i]的最大值
    那么如何判断格子是否能到达， 首先farthest一定是大于等于i，且等于i时必定是nums[i] = 0且前面的格子都最多只能到i，所以在这个时候是不会再跳了
*/
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int farthest = 0;
        for (int i = 0; i < n - 1; i++)
        {
            // 不断计算能跳到的最远距离
            farthest = max(farthest, i + nums[i]);
            // 可能碰到了 0，卡住跳不动了
            if (farthest <= i)
                return false;
        }
        return farthest >= n - 1;
    }
};