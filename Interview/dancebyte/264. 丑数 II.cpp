/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-02 23:04:58
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-02 23:07:02
 */
//贼恶心，反正用小顶堆，记住小顶堆怎么创建就行，然后呢，就是从堆中选出最小的，一次×2，3，5放入队中（通过hash判断在重复性），在这之前从堆中弹出最小的，放入nums答案数组中，在×
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        priority_queue<long, vector<long>, greater<long>> pq;
        unordered_set<long> myset;
        vector<long> nums;
        pq.push(1);
        myset.insert(1);
        long ans;
        int mask[3] = {2, 3, 5};
        while (n > nums.size())
        {
            ans = pq.top();
            pq.pop();
            nums.push_back(ans);
            for (int i = 0; i < 3; i++)
            {
                if (myset.count(ans * mask[i]) == 0)
                {
                    long a = ans * mask[i];
                    pq.push(a);
                    myset.insert(a);
                }
            }
        }
        return ans;
    }
};