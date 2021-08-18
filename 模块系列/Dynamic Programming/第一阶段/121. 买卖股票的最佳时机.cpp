/*
    方法一:
    自己的想法
    假设我是观察员,每一天能赚最多的钱要么是 前一天能赚最多的钱,要么是今天的卖出价格-历史最低价格(minval)
    maxprofit[i] = max(maxproftit[i-1],price[i]-minval)
    https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/121-mai-mai-gu-piao-de-zui-jia-shi-ji-by-leetcode-/
    https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/gu-piao-wen-ti-python3-c-by-z1m/
*/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 0)
            return 0;
        int maxprofit = 0;
        int minval = prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            minval = min(prices[i], minval);
            maxprofit = max(maxprofit, prices[i] - minval);
        }
        return maxprofit;
    }
};

/*
    方法二:哨兵+单调栈
    在 pricesprices 数组的末尾加上一个 哨兵(也就是一个很小的元素，这里设为 0))，就相当于作为股市收盘的标记(后面就清楚他的作用了)
    假如栈空或者入栈元素大于栈顶元素，直接入栈
    假如入栈元素小于栈顶元素则循环弹栈，直到入栈元素大于栈顶元素或者栈空
    在每次弹出的时候，我们拿他与买入的值(也就是栈底)做差，维护一个最大值。
*/
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxprofit = 0;
        prices.push_back(0);
        vector<int> st;
        for (auto price : prices)
        {
            while (!st.empty() && st.back() > price)
            {
                maxprofit = max(maxprofit, st.back() - st.front());
                st.pop_back();
            }
            st.push_back(price);
        }
        return maxprofit;
    }
};