/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-18 20:46:01
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-18 20:46:02
 */
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
             {
                 if (a[0] == b[0])
                     return a[1] > b[1];

                 else
                     return a[0] < b[0];
             });

        int left = intervals[0][0];
        int right = intervals[0][1];
        vector<vector<int>> res;
        for (int i = 1; i < intervals.size(); i++)
        {
            vector<int> p = intervals[i];
            //存在覆盖的情况
            if (p[0] >= left && p[1] <= right)
            {
            }
            //存在相交的情况
            if (p[0] <= right && p[1] > right)
            {
                right = p[1];
            }
            //完全不相交
            if (p[0] > right)
            {
                res.push_back({left, right});
                left = p[0];
                right = p[1];
            }
        }
        res.push_back({left, right});
        return res;
    }
};