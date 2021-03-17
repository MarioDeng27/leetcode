/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-17 21:05:41
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-17 21:06:02
 */
class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> st;
        int curr = 0;
        for (int i = 0; i < pushed.size(); i++)
        {
            st.push(pushed[i]);
            for (; curr < popped.size(); curr++)
            {
                if (!st.empty() && st.top() == popped[curr])
                    st.pop();
                else
                    break;
            }
        }
        return st.empty();
    }
};