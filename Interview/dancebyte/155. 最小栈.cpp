/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-02 22:04:59
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-02 22:05:20
 */
//方法：辅助栈，找到任意一个在栈顶元素对应的最小值，并放在辅助栈中

class MinStack
{
public:
    /** initialize your data structure here. */
    stack<int> st;
    stack<int> stHelper;
    MinStack()
    {
        stHelper.push(INT_MAX);
    }

    void push(int x)
    {
        st.push(x);
        stHelper.push(min(stHelper.top(), x));
    }

    void pop()
    {
        st.pop();
        stHelper.pop();
    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return stHelper.top();
    }
};