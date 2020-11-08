#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <unordered_map>
#include <stack>
using namespace std;
/*
    自己的想法：用栈实现的
    栈中连续元素不会出现２［ａ］，一旦出现］就会把２［ａ］转化成ａａ
*/
class Solution
{
public:
    string decodeString(string s)
    {
        stack<string> st;
        int num = 1;
        string temp = "";
        //string res = "";
        for (char c : s)
        {
            if (c == ']')
            {
                string strval = "";
                while (st.top() != "[")
                {
                    strval.insert(0, st.top());
                    st.pop();
                }
                st.pop();
                string strnum = "";
                while (!st.empty() && st.top() >= "0" && st.top() <= "9")
                {
                    strnum.insert(0, st.top());
                    st.pop();
                }
                if (strnum != "")
                    num = atoi(strnum.c_str());
                string temp = "";
                while (num--)
                {
                    temp += strval;
                }
                st.push(temp);
            }
            else
            {
                string s(1, c);
                st.push(s);
            }
        }
        string sa = "";
        while (!st.empty())
        {
            sa.insert(0, st.top());
            st.pop();
        }
        return sa;
    }
};