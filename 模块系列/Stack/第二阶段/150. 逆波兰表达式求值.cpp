/*
    逆波兰表达式求值/后缀表达式求值
    从左到右遍历表达式的每个数字和符合，遇到是数子就进栈，遇到是符号，就将处于栈顶两个数字出栈，进行运算，运算结果进栈，一直到最终获得结果。
*/

class Solution
{
public:
    bool isnum(string str)
    {
        for (auto c : str)
        {
            if (!isdigit(c) && c != '-' || c == '-' && str.size() == 1)
                return false;
        }
        return true;
    }
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (auto str : tokens)
        {
            if (isnum(str))
                st.push(stoi(str));
            else
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int res;
                if (str == "/")
                {
                    res = b / a;
                }
                if (str == "*")
                {
                    res = b * a;
                }
                if (str == "+")
                {
                    res = b + a;
                }
                if (str == "-")
                {
                    res = b - a;
                }
                st.push(res);
            }
        }
        return st.top();
    }
};

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (auto str : tokens)
        {
            if (str == "/" || str == "*" || str == "+" || str == "-")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int res;
                if (str == "/")
                {
                    res = b / a;
                }
                else if (str == "*")
                {
                    res = b * a;
                }
                else if (str == "+")
                {
                    res = b + a;
                }
                else if (str == "-")
                {
                    res = b - a;
                }
                st.push(res);
            }
            else
                st.push(stoi(str));
        }
        return st.top();
    }
};