/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-18 21:07:17
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-18 21:07:18
 */
/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-18 21:07:17
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-18 21:07:17
 */
class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
    {
        int i = 0;
        int j = 0;
        vector<vector<int>> res;
        while (i < firstList.size() && j < secondList.size())
        {
            vector<int> first = firstList[i];
            vector<int> second = secondList[j];
            //不相交的情况
            if (first[0] > second[1] || second[0] > first[1])
            {
                //不做处理，只在后面对i或者j自增操作
            }
            //相交的情况
            else
            {
                //取交集，其实就是两个区间的起始的较大值以及终点的较小值
                res.push_back({max(first[0], second[0]), min(first[1], second[1])});
                //如果first结束的比second快，则first后面那一段有可能还会和second有交集，所以i++
            }
            if (first[1] < second[1])
                i++;
            else
                j++;
        }
        return res;
    }
};