/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-09-19 12:16:49
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-09-19 12:16:50
 */
class Solution
{
public:
    vector<vector<int>> vec;
    void backtrack(vector<int> &nums, int C, vector<int> track, int sum, int index)
    {
        if (sum == C)
        {
            vec.push_back(track);
            return;
        }
        if (sum > C || index >= nums.size())
        {
            return;
        }

        backtrack(nums, C, track, sum, index + 1);

        sum += nums[index];
        track.push_back(nums[index]);
        //如果元素可以重复使用
        backtrack(nums, C, track, sum, index);
        track.pop_back();
        sum -= nums[index];
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        backtrack(candidates, target, vector<int>(), 0, 0);
        return vec;
    }
};