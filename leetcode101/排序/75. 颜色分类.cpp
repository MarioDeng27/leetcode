class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (auto num : nums)
        {
            mp[num]++;
        }
        vector<vector<int>> buckets(3);
        vector<int> res;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < mp[i]; j++)
            {
                res.push_back(i);
            }
        }
        nums = res;
    }
};