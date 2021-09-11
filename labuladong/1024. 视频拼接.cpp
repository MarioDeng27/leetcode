/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-09-09 21:57:43
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-09-09 21:57:43
 */
class Solution
{
public:
    int videoStitching(vector<vector<int>> &clips, int time)
    {
        int n = clips.size();
        sort(clips.begin(), clips.end(), compair);
        int curEnd = 0;
        int nextEnd = 0;
        int i = 0;
        int res = 0;
        while (i < n && clips[i][0] <= curEnd)
        {
            int maxval = 0;
            while (i<n&&clips[i][0] <= curEnd)
            {
                nextEnd = max(nextEnd, clips[i][1]);
                i++;
            }
            res++;
            curEnd = nextEnd;
            if (curEnd >= time)
                return res;
        }
        return -1;
    }
    static bool compair(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }
};