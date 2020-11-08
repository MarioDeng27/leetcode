#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <sstream>
#include <climits>
using namespace std;
/*
    方法一:动态规划
	dp表示字符串s第i个字母到第j个字母组成的串是否是回文串
	dp = true,对应的串是回文,反之.
	如果dp中i=j(l=0)则dp一定是true
	如果dp中i+1 = j(l=1),表示串就是有两个相邻的字母组成的,如果两个子母相等则为true
	其他情况,也就是j-i>1,至少是三个字母组成的串可以这样判断: 
	dp[i][j] = dp[i+1][j-1] && s[i]==s[j],只要能确定这二者是否为true,都为true则该dp为true
	动态规划的状态转移方程就是这样的,
	在状态转移方程中，从长度较短的字符串向长度较长的字符串进行转移的，因此一定要注意动态规划的循环顺序
	再循环过程中会逐一记录每个小dp的值,后面将会给大dp作为条件进行判断
*/
class Solution
{
public:
    string longestPalindrome(string s)
    {
        string res;
        int n = s.size();
        //dp[i][j], 0<=i,j<=n-1 对应的dp都为0初始值
        vector<vector<int>> dp(n, vector<int>(n));
        //l表示长度. 大长度的由小长度去判断,这就是动态规划,l = 0表示本身, l=1,表示有两个字母
        for (int l = 0; l < n; l++)
        {
            for (int i = 0; i + l < n; i++)
            {
                int j = i + l; //通过i和j表示该穿的右边界索引
                if (l == 0)
                    dp[i][j] = 1;
                else if (l == 1)
                    dp[i][j] = s[i] == s[j];
                else
                    dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
                if (dp[i][j] == 1 && l + 1 > res.size()) //l+1表示该串的长度
                    res = s.substr(i, l + 1);
            }
        }
        return res;
    }
};
/*
    方法二:中心扩展算法,方法一的优化
    https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zui-chang-hui-wen-zi-chuan-by-leetcode-solution/#comment
*/
class Solution
{
public:
    pair<int, int> expandAroundCenter(string &s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }
    string longestPalindrome(string s)
    {
        //表示回文串的左右两边索引,循环过程中维护这两个值,表示最长的回文串
        int start = 0;
        int end = 0;

        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            //两种基本的case,其中一种就是以单个字母进行向外扩展,也就是说回文串的长度是奇数的情况
            auto p1 = expandAroundCenter(s, i, i);
            //以两个相邻字母进行向外扩展,是偶数的情况
            auto p2 = expandAroundCenter(s, i, i + 1);
            //当以当前i值的情况向外扩展,得到的符合回文串并且是该情况下最长的,与目前的答案长度进行比较
            if (p1.second - p1.first > end - start)
            {
                start = p1.first;
                end = p1.second;
            }
            if (p2.second - p2.first > end - start)
            {
                start = p2.first;
                end = p2.second;
            }
        }
        return s.substr(start, end - start + 1);
    }
};
