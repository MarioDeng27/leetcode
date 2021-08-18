/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-22 13:48:01
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-22 13:59:59
 */
//https://labuladong.gitbook.io/algo/shu-ju-jie-gou-xi-lie/shou-ba-shou-she-ji-shu-ju-jie-gou/dan-tiao-zhan
//从i之后找到第一个比他大的
vector<int> nextGreaterElement(vector<int> &nums)
{
    vector<int> res(nums.size()); // 存放答案的数组
    stack<int> s;
    // 倒着往栈里放
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        // 判定个子高矮
        while (!s.empty() && s.top() <= nums[i])
        {
            // 矮个起开，反正也被挡着了。。。
            s.pop();
        }
        // nums[i] 身后的 next great number
        res[i] = s.empty() ? -1 : s.top();
        //
        s.push(nums[i]);
    }
    return res;
}

//环形
vector<int> dailyTemperatures(vector<int> &T)
{
    vector<int> res(T.size());
    // 这里放元素索引，而不是元素
    stack<int> s;
    /* 单调栈模板 */
    for (int i = T.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && T[s.top()] <= T[i])
        {
            s.pop();
        }
        // 得到索引间距
        res[i] = s.empty() ? 0 : (s.top() - i);
        // 将索引入栈，而不是元素
        s.push(i);
    }
    return res;
}