/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-07 15:02:48
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-07 15:02:49
 */
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> status;
    void backtrack(vector<int> &nums, vector<int> &track)
    {
        if (track.size() == nums.size())
            res.push_back(track);

        for (int i = 0; i < nums.size(); i++)
        {
            if (status[i] == 1)
                continue;
            status[i] = 1;
            track.push_back(nums[i]);
            backtrack(nums, track);
            track.pop_back();
            status[i] = 0;
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        status = vector<int>(nums.size(), 0);
        vector<int> track;
        backtrack(nums, track);
        return res;
    }
};