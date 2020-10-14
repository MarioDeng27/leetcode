#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

//自己的想法
//每多一个元素,就在前面已有的元素子集基础上再加上该元素就是新添加的子集
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> resultsets;
        for (int i = 0; i < nums.size(); i++)
        {
            int n = resultsets.size();
            for (int j = 0; j < n; j++)
            {
                vector<int> tempvec = resultsets[j];
                tempvec.push_back({nums[i]});
                resultsets.push_back(tempvec);
            }
            if (resultsets.size() == 0)
            {
                resultsets.push_back({});
                resultsets.push_back({nums[i]});
            }
        }
        return resultsets;
    }
};

//迭代法实现子集枚举
//通过位运算来实现
class Solution
{
public:
    vector<int> t;
    vector<vector<int>> ans;
    //(1 << n)表示总共的子集数
    //1 << n表示每次循环判断把数组中的第几位数字是否要添加进去,是或否取决于mask值
    //如果mask值是110,即6,则在第二个循环里,会有三次判断机会,只有在第二次 i<<1 = 010/2 和第三次 i<<2 = 100/4
    //把nums[1]和nums[2]添加到该元素子集中,其值包含nums[1]和nums[2]
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); ++mask)
        {
            t.clear();
            for (int i = 0; i < n; ++i)
            {
                if (mask & (1 << i))
                {
                    t.push_back(nums[i]);
                }
            }
            ans.push_back(t);
        }
        return ans;
    }
};

//回溯算法
/*
模板:
result[]
def backtrack(路径,选择列表):
    if 满足结束条件:
        result.add(路径)
        return

    for 选择 in 选择列表:
        做选择
        backtrack(路径,选择列表)
        撤销选择
*/
class Solution
{
public:
    vector<vector<int>> result;

    void backtrack(vector<int> nums, int start, vector<int> track)
    {
        result.push_back(track);
        for (int i = start; i < nums.size(); i++)
        {
            track.push_back(nums[i]);
            backtrack(nums, i + 1, track);
            track.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> track;
        backtrack(nums, 0, track);
        return result;
    }
};
