/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-09-18 22:18:09
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-09-19 12:16:04
 */
//回溯
vector<vector<int>> vec;
void backtrack(vector<int> &nums, int C, int index, vector<int> track, int sum)
{
    if (index == nums.size())
        return;

    sum += nums[index];
    track.push_back(index);
    if (sum == C)
    {
        vec.push_back(track);
    }
    //元素不能重复使用
    backtrack(nums, C, index + 1, track, sum);
    track.pop_back();
    sum -= nums[index];

    backtrack(nums, C, index + 1, track, sum);
}