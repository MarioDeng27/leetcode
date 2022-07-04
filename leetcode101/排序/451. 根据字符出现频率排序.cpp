//优先队列
class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> mp;
        for (auto c : s)
        {
            mp[c]++;
        }
        priority_queue<pair<char, int>, vector<pair<char, int>>, Order> pq(mp.begin(), mp.end());
        string res;
        while (!pq.empty())
        {
            auto item = pq.top();
            pq.pop();
            res += string(item.second, item.first);
        }
        return res;
    }
    struct Order
    {
        bool operator()(pair<char, int> p1, pair<char, int> p2)
        {
            return p1.second < p2.second;
        }
    };
};
//桶排序
class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> mp;
        int max_count = 0;
        for (auto c : s)
        {
            max_count = max(++mp[c], max_count);
        }
        vector<vector<char>> buckets(max_count + 1);
        for (auto item : mp)
        {
            buckets[item.second].push_back(item.first);
        }
        string res = "";
        for (int i = max_count; i >= 0; i--)
        {
            for (auto item : buckets[i])
            {
                res += string(i, item);
            }
        }
        return res;
    }
};