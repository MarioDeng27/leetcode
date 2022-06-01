/*
 * @Description:
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2022-06-01 15:45:59
 * @LastEditors: Mario Deng
 * @LastEditTime: 2022-06-01 15:47:56
 */
//贪心，对每个区间的右端点进行从小到达排序，进行个个排除，局部最优（若两个区间重叠，则必定要删去其中一个，那就删去右端点大的，因为它对后续的区间产生的负面影响的可能性更大）
class Solution
{
public:
    static bool compaire(vector<int> &a, vector<int> &b)
    {
        if (a[1] != b[1])
        {
            return a[1] < b[1];
        }
        else
        {
            return a[0] < b[0];
        }
    }
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), compaire);
        int res = 0;
        int rightlimit = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < rightlimit)
            {
                res++;
            }
            else
            {
                rightlimit = intervals[i][1];
            }
        }

        return res;
    }
};