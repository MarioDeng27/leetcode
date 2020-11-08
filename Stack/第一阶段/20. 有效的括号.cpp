#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <unordered_map>
#include <stack>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        if (s.size() % 2 != 0)
            return false;
        stack<char> st;
        for (auto c : s)
        {
            if (c == '(' || c == '[' || c == '{' || st.empty() == true)
                st.push(c);
            else
                switch (c)
                {
                    char ch;
                case ')':
                    ch = st.top();
                    if (ch == '(')
                    {
                        st.pop();
                        break;
                    }
                    return false;
                case ']':
                    ch = st.top();
                    if (ch == '[')
                    {
                        st.pop();
                        break;
                    }
                    return false;
                case '}':
                    ch = st.top();
                    if (ch == '{')
                    {
                        st.pop();
                        break;
                    }
                    return false;
                default:
                    break;
                }
        }
        return st.empty();
    }
};