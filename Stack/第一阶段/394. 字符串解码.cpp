#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
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
/*
    一个数子栈一个字符串栈
    一旦出现'['就将之前保存好的数子n 和 字符串word 保存到各自的栈中，注意，n和word不是对应的关系，本次的n应该与下一次的word对应
    一旦出现']'就将之前在各自栈中保存好的栈顶元素数字 k 和 temp取出，让 temp + 3*word(当前word),然后将word = 该值
*/
class Solution
{
public:
    string decodeString(string s)
    {
        stack<int> stnum;
        stack<string> ststr;
        int n = 0;
        string word;
        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
            {
                n = n * 10 + (s[i] - '0');
            }
            else if (s[i] == '[')
            {
                ststr.push(word);
                stnum.push(n);
                word = "";
                n = 0;
            }
            else if (isalpha(s[i]))
            {
                word += s[i];
            }
            else // c == ']'
            {
                string temp = ststr.top();
                ststr.pop();
                int k = stnum.top();
                stnum.pop();
                while (k--)
                {
                    temp += word;
                }
                word = temp;
            }
        }
        return word;
    }
};