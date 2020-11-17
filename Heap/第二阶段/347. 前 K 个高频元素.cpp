class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> m;
        for (auto num : nums)
        {
            ++m[num];
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, Order> pq(m.begin(), m.end());
        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
    struct Order
    { //起到greater的作用，如果a的优先级大于b的，返回true
        bool operator()(pair<int, int> &a, pair<int, int> &b) const
        { //a,b频数大的，优先级大，频数相等，字典序小的优先级大.
            if (a.second != b.second)
                return a.second < b.second;
            else
            {
                return a.first > b.first;
            }
        }
    };
};