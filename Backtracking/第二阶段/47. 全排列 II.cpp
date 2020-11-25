/*
    参考46全排列I
    关键就在去重,注意:
    if (i > 0 && visited[i - 1] == false && nums[i] == nums[i - 1])
    {
        continue;
    }
    表示,当底为i-1的情况下已经全部排完了,那么visted[i-1]必然回归为false那么这个时候是以i为底的情况下,因为i和i-1
    值相等,那么出现的情况肯定是和之前i-1为底的情况相同,所以跳过
    而如果visited[i-1]为true表示当前i-1为底的情况还在进行中,i和i-1相同是没问题的,因为这是该种情况下的第一次出现
*/
class Solution
{
public:
    vector<vector<int>> res;
    void backtrack(vector<int> &nums, vector<bool> &visited, vector<int> &track)
    {
        if (track.size() == nums.size())
        {
            res.push_back(track);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && visited[i - 1] == false && nums[i] == nums[i - 1])
            {
                continue;
            }
            if (visited[i] == false)
            {
                visited[i] = true;
                track.push_back(nums[i]);
                backtrack(nums, visited, track);
                track.pop_back();
                visited[i] = false;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<bool> visted(nums.size(), false);
        vector<int> track;
        backtrack(nums, visted, track);
        return res;
    }
};