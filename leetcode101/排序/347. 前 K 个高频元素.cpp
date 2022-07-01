class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (auto num : nums)
        {
            mp[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, Order> pq(mp.begin(), mp.end());
        int i = 0;
        vector<int> ans;
        while (i < k)
        {
            ans.push_back(pq.top().first);
            pq.pop();
            i++;
        }
        return ans;
    }
    struct Order
    {
        bool operator()(pair<int, int> p1, pair<int, int> p2)
        {
            return p1.second < p2.second;
        }
    };
};
//桶排序，好好理解一下
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int max_count = 0;
        for (auto num : nums)
        {
            max_count = max(max_count, ++mp[num]);
        }
        vector<vector<int>> buckets(max_count + 1);
        for (auto item : mp)
        {
            buckets[item.second].push_back(item.first);
        }
        vector<int> res;
        for (int i = max_count; i >= 0; i--)
        {
            for (auto bucket : buckets[i])
            {
                res.push_back(bucket);
                if (res.size() == k)
                    return res;
            }
        }
        return res;
    }
};