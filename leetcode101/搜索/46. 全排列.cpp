class Solution
{
public:
    void backtrack(vector<int> &nums, int i)
    {
        if (i == nums.size())
        {
            res.push_back(nums);
            return;
        }
        for (int j = i; j < nums.size(); j++)
        {
            swap(nums[i], nums[j]);
            backtrack(nums, i + 1);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int> &nums)
    {
        backtrack(nums, 0);
        return res;
    }
};

class Solution
{
public:
    void backtrack(vector<int> &nums, vector<bool> &status, vector<int> &track)
    {
        if (track.size() == nums.size())
        {
            res.push_back(track);
            return;
        }
        for (int j = 0; j < nums.size(); j++)
        {
            if (!status[j])
            {
                track.push_back(nums[j]);
                status[j] = true;
                backtrack(nums, status, track);
                track.pop_back();
                status[j] = false;
            }
        }
    }
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<bool> status(nums.size(), false);
        vector<int> track;
        backtrack(nums, status, track);
        return res;
    }
};