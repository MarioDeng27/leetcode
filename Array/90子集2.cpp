#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
using namespace std;
//回溯算法实现
/*
    https://leetcode-cn.com/problems/subsets-ii/solution/90-zi-ji-iiche-di-li-jie-zi-ji-wen-ti-ru-he-qu-zho/
    和78子集的题目类似,只是里面的元素有重复,实际上就是要符合两个特点:
    子集里面的元素可以有重复,但是子集之间是不一样的,即使元素位置不一样元素相同这样也算一样
    拿[1,2,2]举例子
    同一树层上不能重复取2,同一树枝可以再次取2,树枝表示一个子集内部,树层表示成为各个子集之间的不能取同样的数字两次 
    // used[i - 1] == true，说明同一树支nums[i - 1]使用过,true表示成为一个子集过程中可以重复取同样的元素,纵向遍历,递归(就只看for里面就能明白些)
    // used[i - 1] == false，说明同一树层nums[i - 1]使用过,false表示成为不同子集过程中不能重复取同样的元素,横向遍历for循环
    // 而我们要对同一树层使用过的元素进行跳过
*/
class Solution
{
public:
    vector<vector<int>> result;

    void backtrack(vector<int> nums, vector<bool> &used, int start, vector<int> track)
    {
        result.push_back(track);
        for (int i = start; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
                continue;
            track.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, used, i + 1, track);
            used[i] = false;
            track.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<int> track;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums, used, 0, track);
        return result;
    }
};