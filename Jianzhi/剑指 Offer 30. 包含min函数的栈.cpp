/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-17 20:40:20
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-17 20:40:41
 */
class MinStack
{
public:
    /** initialize your data structure here. */
    stack<int> st;
    stack<int> helper;
    MinStack()
    {
        helper.push(INT_MAX);
    }

    void push(int x)
    {
        st.push(x);
        if (helper.top() >= x)
            helper.push(x);
        else
            helper.push(helper.top());
    }

    void pop()
    {
        st.pop();
        helper.pop();
    }

    int top()
    {
        return st.top();
    }

    int min()
    {
        return helper.top();
    }
};