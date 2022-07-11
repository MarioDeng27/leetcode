class Solution
{
public:
    vector<vector<int>> res;
    void backtrack(vector<int> &nums, vector<bool> &visited, vector<int> track)
    {
        if (track.size() == nums.size())
        {
            res.push_back(track);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (visited[i])
                continue;
            if (i > 0 && !visited[i - 1] && nums[i - 1] == nums[i])
                continue;
            visited[i] = true;
            track.push_back(nums[i]);
            backtrack(nums, visited, track);
            visited[i] = false;
            track.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<bool> visited(n, false);
        vector<int> track;
        backtrack(nums, visited, track);
        return res;
    }
};