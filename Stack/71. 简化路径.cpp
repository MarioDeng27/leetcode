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
    string simplifyPath(string path)
    {
        if (path[path.size() - 1] != '/')
            path += '/';
        stack<string> st;
        string str = "";
        for (char c : path)
        {
            if (c == '/')
                if (str == "." || str == "")
                {
                    str = "";
                }
                else if (str == "..")
                {
                    if (!st.empty())
                        st.pop();
                    str = "";
                }
                else
                {
                    st.push(str);
                    str = "";
                }
            else
            {
                str += c;
            }
        }
        string spath = "";
        if (st.empty())
            return "/";
        while (!st.empty())
        {
            spath.insert(0, '/' + st.top());
            st.pop();
        }
        return spath;
    }
};
