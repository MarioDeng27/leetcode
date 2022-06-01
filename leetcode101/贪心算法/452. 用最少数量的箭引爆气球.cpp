class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.size() < 2)
            return points.size();
        sort(points.begin(), points.end(),
             [](auto &a, auto &b)
             {
                 if (a[1] != b[1])
                 {
                     return a[1] < b[1];
                 }
                 else
                 {
                     return a[0] < b[0];
                 }
             });
        int rightlimit = points[0][1];
        int res = 1;
        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] <= rightlimit)
            {
            }
            else
            {
                rightlimit = points[i][1];
                res++;
            }
        }
        return res;
    }
};