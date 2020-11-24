/*
    二分法：

    参考这两个：
    https://leetcode-cn.com/problems/split-array-largest-sum/solution/fen-ge-shu-zu-de-zui-da-zhi-by-leetcode-solution/
    https://leetcode-cn.com/problems/split-array-largest-sum/solution/bai-hua-er-fen-cha-zhao-by-xiao-yan-gou/

    首先找到最小的最大子数组和的范围一定是介于[left,right]之间，left是整个数组中的最大元素，right是整个数组的和，然后通过left，right一分为二算出mid
    通过计算数组中存在连续的子数组的和不大于mid的个数cnt,如果cnt<=m(要求的子数组个数),则说明mid算的太大了，需要缩小搜查范围，缩小下界，就让right=mid
    当cnt>m时，说明mid算的太小了，分的组太多了，则缩小范围，即扩大下界，left = mid+1，此时的mid肯定不会是真正的答案
    注意一个特殊情况：当得到一个mid值，通过它可以得cnt个符合条件的子数组，如果cnt=m，但是left<mid则说明，mid还可以继续小，可以继续收敛，因为题干是要找到
    最小的最大子数组和

    当left增大，right缩小，最终到left=right时，此时的left必定属于某个子数组的和，它就是所有数组里面和的最大值，并且这个和是所有分法里面值最小的
*/

class Solution
{
public:
    bool check(vector<int> &nums, int x, int m)
    {
        int cnt = 1;
        int sum = 0;
        for (auto num : nums)
        {
            if (sum + num > x)
            {
                cnt++;
                sum = num;
            }
            else
            {
                sum += num;
            }
        }
        return cnt <= m;
    }

    int splitArray(vector<int> &nums, int m)
    {
        int left = 0, right = 0;
        for (auto num : nums)
        {
            right += num;
            left = max(num, left);
        }
        int mid;
        while (left < right)
        {
            mid = left + ((right - left) >> 1);
            if (check(nums, mid, m))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};

/*
    动态规划解决：还没写。太复杂了

*/