/*
    栈+反转字符串
    因为要用到栈的话最后的计算顺序都是反着的,加法是没有问题,因为由结合律和交换律,但是减法就不行了,所以必须将字符串给反转了
    这样用到栈才会变成实际的计算顺序,反反得正

    所以直到碰到'('左括号,才对栈进行计算处理,并把结果压入栈中

    那么因为123这个数字代表的是三个字符,逆序的话,必须成为3*1 + 2*10 + 1*100 这样子计算的结果才是123

    然后数字转字符串可以用int2string这个方法

    字符串转数字可以用stoi这个函数

    由于可能逆转之后最后遇到 +41这种情况,你计算出的操作数是14,但显然字符串已经遍历完,但你并没有讲操作数压入栈中

    所以遍历完字符串之后讲操作数再压入栈中

    最后进行一个栈计算
*/

class Solution
{
public:
    string int2string(int a)
    {
        stringstream ss;
        string temp;
        ss << a;
        ss >> temp;
        return temp;
    }
    int evaluateExpr(stack<string> &st)
    {
        int res = 0;
        if (!st.empty())
        {
            res = stoi(st.top());
            st.pop();
        }
        while (!st.empty() && st.top() != ")")
        {
            if (st.top() == "+")
            {
                st.pop();
                res += stoi(st.top());
                st.pop();
            }
            else if (st.top() == "-")
            {
                st.pop();
                res -= stoi(st.top());
                st.pop();
            }
        }
        return res;
    }
    int calculate(string s)
    {
        int res = 0;
        stack<string> st;
        string str(s.rbegin(), s.rend());
        int n = 0;
        int operand = 0;
        for (auto c : str)
        {
            if (c == ' ')
                continue;
            if (isdigit(c))
            {
                operand += pow(10, n) * (c - '0');
                n++;
            }
            else
            {
                if (n != 0)
                {
                    st.push(int2string(operand));
                    n = 0;
                    operand = 0;
                }
                if (c == '(')
                {
                    res = evaluateExpr(st);
                    st.pop();
                    st.push(int2string(res));
                }
                else
                {
                    string temp;
                    temp += c;
                    st.push(temp);
                }
            }
        }
        if (n != 0)
            st.push(int2string(operand));
        return evaluateExpr(st);
    }
};