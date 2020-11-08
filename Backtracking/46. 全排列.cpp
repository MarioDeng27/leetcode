#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <sstream>
#include <climits>
using namespace std;
/*
    自己的想法：
    添加了一个used数组来表示nums数组中的值收否被添加到track的备选答案里
*/

class Solution
{
public:
    vector<vector<int>> res;
    int n = 0;
    void backtrack(vector<int> nums, vector<bool> used, int cnt, vector<int> track)
    {
        if (cnt == n)
        {
            res.push_back(track);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (used[i] == false)
            {
                track.push_back(nums[i]);
                used[i] = true;
                cnt++;
                backtrack(nums, used, cnt, track);
                track.pop_back();
                used[i] = false;
                cnt--;
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<bool> used(nums.size(), false);
        n = nums.size();
        backtrack(nums, used, 0, {});
        return res;
    }
};
/* 
    方给的答案：例子{1,2,3}
    全排列的集合里的各个元素其实就是相对位置不一样，所以通过swap　调换元素位置即可实现
    首先对于原始位置的１来说他能调换三次（第一次与自己交换）（第二次与２）（第三次与３）
        对于原始位置的２来说他能调换两次（第一次与自己交换）（第二次与３）
        对于原始位置的３来说他能调换一次（第一次与自己交换）
    对于每一次交换后只要符合条件被添加值答案组里，则得还原称交换元素前的状态，比如在１，２，３这时，２，３进行交换变成１，３，２被添加至答案组里
    则　得再交换回来　１，２，３，然后当前递归次序里，i＋＋　也许跳出了循环，也许再次与后面元素进行交换，基准还是以２为底
    等２换完之后，再来判断１，１还能和２和３交换，后面大概都一样，只要２和３已经用完了之后，再把１换到原始位置，进行判断．
 */
class Solution
{
public:
    void backtrack(vector<vector<int>> &res, vector<int> &output, int first, int len)
    {
        // 所有数都填完了
        if (first == len)
        {
            res.emplace_back(output);
            return;
        }
        for (int i = first; i < len; ++i)
        {
            // 动态维护数组
            swap(output[i], output[first]);
            // 继续递归填下一个数
            backtrack(res, output, first + 1, len);
            // 撤销操作
            swap(output[i], output[first]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        backtrack(res, nums, 0, (int)nums.size());
        return res;
    }
};