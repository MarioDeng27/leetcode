/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-11 14:51:48
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-11 14:52:08
 */
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 0)
            return 0;
        int minVal = prices[0];
        int maxProfi = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            minVal = min(minVal, prices[i]);
            maxProfi = max(maxProfi, prices[i] - minVal);
        }
        return maxProfi;
    }
};