/*
    1. 首先将input通过'/n'分割成若干个string组成的数组
    注意'/n'和'/t'是一个字符
*/

class Solution
{
public:
    vector<string> strsplit(string input)
    {
        string::size_type pos = 0;
        string::size_type start = 0;
        vector<string> res;
        while ((pos = input.find_first_of('\n', pos)) != string::npos)
        {
            res.push_back(input.substr(start, pos - start));
            pos += 1;
            start = pos;
        }
        res.push_back(input.substr(start, pos - start));
        return res;
    }
    int lengthLongestPath(string input)
    {
        vector<string> vec = strsplit(input);
        stack<int> st;
        int res = 0;
        for (auto str : vec)
        {
            string::size_type level = str.find_last_of('\t') + 1;
            while (level < st.size())
                st.pop();
            int len;
            if (!st.empty())
                len = st.top() + str.size() - level + 1;
            else
                len = str.size() - level;
            st.push(len);
            if (str.find('.', 0) != string::npos)
            {
                res = max(res, len);
            }
        }
        return res;
    }
};