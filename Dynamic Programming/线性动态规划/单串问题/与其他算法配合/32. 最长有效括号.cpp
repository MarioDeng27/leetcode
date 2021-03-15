/*
 * @FilePath: \Sorte:\DataStructures-Algorithms\DataStructures-Algorithms\leetcode\Dynamic Programming\线性动态规划\单串问题\与其他算法配合\32. 最长有效括号.cpp
 * @Brief: 
 * @Version: 1.0
 * @Date: 2021-03-15 22:01:27
 * @Author: Mario Deng
 * @Copyright: your copyright description
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-15 22:46:43
 */
/*
    动态规划实现：
    dp[i]表示以第i个元素结尾，包含该元素值的情况下符合要求的最长子序列

    当s[i] 等于( 肯定是dp[i] = 0

    当s[i] 等于)分两种情况讨论：

        若s[i-1] = '(' 则表示最后的这两个是符合条件的，则当前dp[i] = dp[i-2] + 2

        若s[i-1] = ')' 则表示这个前面的)已有归属，看看是否能找到更前面的单留下来的 '('，上哪找呢，其实就是 s[i-dp[i-1] -1] dp[i-1] 表示在i-1情况下的符合条件的长度，减去它再减1表示，到了那个有可能出现单个没配对的'(' 如果是那么在 dp[i-1]基础上肯定要加2，但是还有可能，它把前面中断的长度连接起来了，比如 ()(())在最后一个)情况下，它把第三个元素'('给配对了，所以在刚刚基础上还得加上dp[i-dp[i-1]-2]
        所以dp[i]=dp[i−1]+dp[i−dp[i−1]−2]+2
*/

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.size();
        vector<int> dp(n, 0);
        int maxLen = 0;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == ')')
            {
                if (s[i - 1] == '(')
                    dp[i] = (i - 2 >= 0 ? dp[i - 2] : 0) + 2;
                else if (s[i - 1] == ')' && i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
                {
                    dp[i] = dp[i - 1] + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};
/*
        https://leetcode-cn.com/problems/longest-valid-parentheses/solution/zui-chang-you-xiao-gua-hao-by-leetcode-solution/
        用栈实现，最主要的还是 -1加入了栈中，反之栈底元素肯定是当前情况下最后一个不匹配的右括号的坐标


*/
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> st;
        st.push(-1);
        int maxLen = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                st.push(i);
            else
            {
                st.pop();
                if (st.empty())
                    st.push(i);
                else
                {
                    maxLen = max(i - st.top(), maxLen);
                }
            }
        }
        return maxLen;
    }
};
//方法三：很巧妙，记住
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.size();
        int left = 0, right = 0;
        int maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                left++;
            else
                right++;
            if (left == right)
                maxLen = max(left + right, maxLen);
            if (left < right)
                left = right = 0;
        }
        left = right = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '(')
                left++;
            else
                right++;
            if (left == right)
                maxLen = max(left + right, maxLen);
            if (right < left)
                left = right = 0;
        }
        return maxLen;
    }
};