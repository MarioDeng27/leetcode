/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-18 20:35:04
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-18 20:37:56
 */
/*
    1. 区间问题先排序（通过区间的起始索引升序以及终点索引降序进行排序）
    2. 再画图，判断出区间的相对位置的情况有哪几种，这种情况下总共就三种：
    排完序之后可以被覆盖
    相交
    完全不相交
*/
class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
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
        int res = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            vector<int> p = intervals[i];
            //存在覆盖的情况
            if (p[0] >= left && p[1] <= right)
            {
                res++;
            }
            //存在相交的情况
            if (p[0] <= right && p[1] > right)
            {
                right = p[1];
            }
            //完全不相交
            if (p[0] > right)
            {
                left = p[0];
                right = p[1];
            }
        }
        return intervals.size() - res;
    }
};