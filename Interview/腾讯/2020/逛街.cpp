/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-22 15:41:53
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-22 15:41:55
 */
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param heights int整型vector 
     * @return int整型vector
     */
    vector<int> findBuilding(vector<int> &heights)
    {
        // write code here
        //在i位置向右（从左往右）看有几个单调增的数字，一旦有个高个子拦着就停了
        vector<int> a(heights.size());
        stack<int> stLeft;
        for (int i = heights.size() - 1; i >= 0; i--)
        {
            a[i] = stLeft.empty() ? 0 : stLeft.size();
            while (!stLeft.empty() && stLeft.top() <= heights[i])
                stLeft.pop();
            stLeft.push(heights[i]);
        }
        //在i位置向左（从右往左）看有几个单调增的数字，一旦有高个子拦着就停了
        vector<int> b(heights.size());
        stack<int> stRight;
        for (int i = 0; i <= heights.size() - 1; i++)
        {
            b[i] = stRight.empty() ? 0 : stRight.size();
            while (!stRight.empty() && stRight.top() <= heights[i])
                stRight.pop();
            stRight.push(heights[i]);
        }
        for (int i = 0; i < a.size(); i++)
            a[i] += (b[i] + 1);
        return a;
    }
};