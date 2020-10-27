#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

//自己的想法
class Solution
{
public:
	int maxSubArray(vector<int> &nums)
	{
		int n = nums.size();
		int maxsub = nums[0];
		int sum = nums[0];
		for (int i = 1; i < n; i++)
		{
			if (sum + nums[i] < nums[i])
			{
				maxsub = max(maxsub, nums[i]);
				sum = nums[i];
			}
			else
			{
				sum = sum + nums[i];
				int b = max(maxsub, sum);
				/*if (maxsub != b)
				{
					sum = b;
				}*/
				ma1xsub = b;
			}
		}
		return maxsub;
	}
};

//动态规划
/*
首先,经过n次循环求出每个以第i个数字为结尾的最大子序和f(i)
	怎么算: max(f(i-1)+a[i],a[i]) ,只要和i之前的i-1为结尾的最大子序和与a[i]的相加和与a[i]自己相比较求大的
循环n次维护最大的子序和maxsum就行:
max(maxsum,f(i))
*/
class Solution2
{
public:
	int maxSubArray(vector<int> &nums)
	{
		int maxsub = nums[0];
		int sum = 0;
		for (auto i : nums)
		{
			//=左侧的就sum相当与f(i),=右侧的sum相当于f(i-1)
			sum = max(sum + i, i);
			maxsub = max(sum, maxsub);
		}
		return maxsub;
	}
};

class Solution
{
public:
	int maxSubArray(vector<int> &nums)
	{
		int maxsub = nums[0];
		int pre = 0;
		for (auto n : nums)
		{
			pre = max(pre + n, n);
			maxsub = max(maxsub, pre);
		}
		return maxsub;
	}
};

/*
分而治之,大问题可以分为若干个小问题去解决,只要小问题解决了,大问题就解决了.一直分到问题不能在分位置就是递归的终止条件

讨论在一个区间[l,r]内的维护量,分割点为m,左子区间[l,m],右子区间[m+1,r]
lsum: 在一个区间内以l左端点开始的最大子序列和,其值要么是 左区间的lsum 或者是左区间的isum + 右子区间的lsum
rsum: 在一个区间内以r右端点结尾的最大子序列和,其值要么是右区间的rsum 或者是右区间的isum + 左区间的rsum
msum: 在[l,r]区间内的最大子序列和,其值分两种情况:
											1. 不跨越m时,其值 要么是左区间的msum 或者是 右区间的msum
											2. 跨越m时,	其值 左区间的rsum + 右区间的lsum,只有这两个相加才会是跨越m时的最大值
											3. 取这三种情况的最大值即可
isum: 在[l,r]区间内的代数和,其值比较简单位,左区间的isum + 右区间的isum

讨论[l,r]区间怎么才能分割成两个区间,关键在于求得m
m = f(l,r),m通过l,r求出
然后分别要求出[l,m]和[m+1,r]两个区间的维护量,则又要分区,关键还是求得m,一直到区间不可在分为止,即l=r
*/

class Solution
{
public:
	struct ranges
	{
		int lsum;
		int rsum;
		int msum;
		int isum;
	};

	ranges combine(ranges l, ranges r)
	{
		int lsum = max(l.lsum, l.isum + r.lsum);
		int rsum = max(r.rsum, r.isum + l.rsum);
		int msum = max(max(l.msum, r.msum), l.rsum + r.lsum);
		int isum = l.isum + r.isum;
		return (ranges){lsum, rsum, msum, isum};
	}

	ranges get(vector<int> &nums, int a, int b)
	{
		if (a == b)
			return (ranges){nums[a], nums[a], nums[a], nums[a]};
		int m = (a + b) / 2;
		ranges l = get(nums, a, m);
		ranges r = get(nums, m + 1, b);
		return combine(l, r);
	}
	int maxSubArray(vector<int> &nums)
	{
		ranges r = get(nums, 0, nums.size() - 1);
		return r.msum;
	}
};
