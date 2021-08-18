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
    方法１：
    利用了两个指针，分别指向字串的两个左右边界
    创建了一个unorderedset来模拟一个队列，而且可以利用set的find查找功能，能很快的找到字串中是否出现重复字符
    如果要加一个新的字符，只要保证其在已有字串里没有出现过，则就将其加入字串，如果出现了，字串就从最左边开始一个一个扫过取，直到将字串里的重复字串全部去除为止
    最后将这个新字符加入到字串，然后判断现在子串的长度和之前出现过最大长度的字串的大小，将大值赋值给maxlen
*/
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> q;
        int l = 0;
        int r = 0;
        int maxlen = 0;
        for (int r = 0; r < s.size(); r++)
        {

            while (q.find(s[r]) != q.end())
            {
                q.erase(s[l]);
                l++;
            }
            q.insert(s[r]);
            maxlen = max(maxlen, r - l + 1);
        }
        return maxlen;
    }
};
/*
    方法２：
    利用了两个指针，分别指向字串的两个左右边界
    当要加入一个新的字符时，必须判断现有字串是否有相同的字符，具体方法为：
    从左指针开始向右扫一直扫到右指针前一个字符位置，一旦发现与新字符相同的字符，则将左指针ｌ的值变为当前扫描指针的后一位即ｉ＋１
    最后再判断一下最长子串的长度
    在程序最开始时，如果出现了只有单一字符的字符串，则返回１，这个情况单独判断
*/
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 1)
            return 1;
        int l = 0;
        int r = 0;
        int maxlen = 0;
        for (int r = 1; r < s.size(); r++)
        {
            for (int i = l; i < r; i++)
            {
                if (s[i] == s[r])
                {
                    l = i + 1;
                }
            }
            maxlen = max(maxlen, r - l + 1);
        }
        return maxlen;
    }
};