#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

/*
    暴力法:
    每次求以i下标为结尾的[j,i]的和,0<=j<=i,如果出现和为k就加1
*/
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int count = 0;
        for (int start = 0; start < nums.size(); ++start)
        {
            int sum = 0;
            for (int end = start; end >= 0; --end)
            {
                sum += nums[end];
                if (sum == k)
                {
                    count++;
                }
            }
        }
        return count;
    }
};
/*
分析:https://leetcode-cn.com/problems/subarray-sum-equals-k/solution/he-wei-kde-zi-shu-zu-by-leetcode-solution/
    前缀和 + 哈希表优化 实现

    分析过程:我们可以基于方法一利用数据结构进行进一步的优化
    我们知道方法一的瓶颈在于对每个 i，我们需要枚举所有的 j来判断是否符合条件，这一步是否可以优化呢？答案是可以的

    关键在于分别将下标为i结尾pre(i)的前子序列和放到map里,并计数
    而且,边放pre之前还判断在当前的map里是否出现了 pre-k 为关键索引的数目,如果有就将count加上该数目

    如果先将所有pre算出放进map然后再用find(pre(i)-k)搜寻,可能会搜寻到i之后的一些和,这与i下标的元素不一定连续
*/
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int count = 0;
        //第一个int记录以i为下标的 [0,1]的总数和,用pre(i)表示,第二个int记录以该和作为索引出现的次数
        unordered_map<int, int> m;
        int pre = 0;
        //很关键,这表示以如果在判断 pre-k 的值为0 时 出现的个数,如果后面还出现 pre是0 还会再相加,表示当前 pre(i) = 0,可以作为后面pre(j) j>i用
        //初始值为1表示,就算不出现pre(i),当 出现 pre-k = 0的时候, 表示从0-i的和就是符合条件的子序列
        m[0] = 1;
        for (auto i : nums)
        {
            pre = pre + i;
            if (m.find(pre - k) != m.end())
                count += m[pre - k];
            ++m[pre];
        }
        return count;
    }
};
/*
    前缀和+哈希表

    第i次，pre表示以i结尾的前的所有元素之和，pre(i)

    第i+1元素到第j元素的连续子数组之和表示：pre[j]-pre[i]

    每次计算出当前pre的值就将该值记录到哈希表中增加一次。

    只要出现pre-k的值在哈希表中出现，那么count就增加对应值。理论就是  让k = pre[j]-pre[i] ,j在后面，i在前面，提前记录了pre[i]的值在哈希表里

    就是变计算前缀和做判断，然后将该前缀和记录到哈希表里
*/
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        map<int, int> m;
        int pre = 0;
        int count = 0;
        m[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            pre += nums[i];
            if (m.find(pre - k) != m.end())
                count += m[pre - k];
            m[pre]++;
        }
        return count;
    }
};