/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-09-09 20:52:05
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-09-09 20:52:05
 */
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        int n = points.size();
        sort(points.begin(), points.end(), compair);
        int res = 1;
        int end = points[0][1];
        for (int i = 1; i < n; i++)
        {
            int start = points[i][0];
            if (start > end)
            {
                res++;
                end = points[i][1];
            }
        }
        return res;
    }
    static bool compair(vector<int> &a, vector<int> &b)
    {
        if (a[1] == b[1])
            return a[0] < b[0];
        return a[1] < b[1];
    }
};