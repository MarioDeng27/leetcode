/*
 * @FilePath: \Sorte:\DataStructures-Algorithms\DataStructures-Algorithms\leetcode\Jianzhi\剑指 Offer 40. 最小的k个数.cpp
 * @Brief: 
 * @Version: 1.0
 * @Date: 2021-04-10 19:07:51
 * @Author: Mario Deng
 * @Copyright: your copyright description
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-04-10 19:07:51
 */
class Solution
{
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k)
    {
        if (k == 0)
            return {};
        priority_queue<int, vector<int>, less<int>> pq;
        for (int i = 0; i < arr.size(); i++)
        {
            if (pq.size() < k)
                pq.push(arr[i]);
            else
            {
                int val = pq.top();
                if (val > arr[i])
                {
                    pq.pop();
                    pq.push(arr[i]);
                }
            }
        }
        vector<int> res;
        int n = pq.size();
        for (int i = 0; i < n; i++)
        {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};