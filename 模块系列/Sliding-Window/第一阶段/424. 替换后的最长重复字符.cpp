#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
/*
    方法１：
    1.定义l和r分别表示窗口的左右两边界，其宽度为d=r-l+1
    2.计算当前窗口（包含边界）　加上　窗口右边的新字符后　出现相同字母次数的最大值hischarmax，方法可以是，每次添加新字符后该字符出现的次数与历史最大次数相比，取大值
    则若 hischarmax + k　大于或等于　其字符串长度（滑动窗口宽度）则表示滑动窗口还可能向右扩张（若his+k > d,则必定能扩张，若相等，得看下次出现的新字符是否能让his变得更大）
    若his+k小于d 则表示新加入字符后滑动窗口的宽度（新字符串的长度不能满足题意的可替换后的最长重复字符串）
    所以减小一次左指针所指向的字母在字母次数表中的次数（窗口左边界），然后左指针向右滑动１，来表示窗口长度不变但向右移动了１，因为在之前r在for循环里也加了１
    接下来在继续判断
    3.直到窗口滑到里整个字符串的最右边后停止，计算窗口宽度就是答案，或者也可以计算s.size()-l来表示

    注意：
    窗口扩张：left不变，right++
    窗口滑动：left++, right++
    直到right一直到最右边，然后保存的窗口的宽度一直是之前符合条件的那个最长宽度，但不一定是当前l和r对应的字串，但长度没变

    本方法１，采用map存储当前窗口中各个字母的出现次数
*/
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int l = 0;
        int r = 0;
        int hischarmax = 0;
        map<char, int> m;
        for (int r = 0; r < s.size(); r++)
        {
            ++m[s[r]];
            hischarmax = max(hischarmax, m[s[r]]);
            //在这里，即使hischarmax+k　＝　滑动窗口的宽度，仍然可以试着取扩张，而不是滑动窗口
            if (r - l + 1 > hischarmax + k)
            {
                --m[s[l]];
                l++;
            }
        }
        return s.size() - l;
    }
};
/* 
    方法２：
    1.定义l和r分别表示窗口的左右两边界，其宽度为d=r-l+1
    2.计算当前窗口（包含边界）　加上　窗口右边的新字符后　出现相同字母次数的最大值hischarmax，方法可以是，每次添加新字符后该字符出现的次数与历史最大次数相比，取大值
    则若 hischarmax + k　大于或等于　其字符串长度（滑动窗口宽度）则表示滑动窗口还可能向右扩张（若his+k > d,则必定能扩张，若相等，得看下次出现的新字符是否能让his变得更大）
    若his+k小于d 则表示新加入字符后滑动窗口的宽度（新字符串的长度不能满足题意的可替换后的最长重复字符串）
    所以减小一次左指针所指向的字母在字母次数表中的次数（窗口左边界），然后左指针向右滑动１，来表示窗口长度不变但向右移动了１，因为在之前r在for循环里也加了１
    接下来在继续判断
    3.直到窗口滑到里整个字符串的最右边后停止，计算窗口宽度就是答案，或者也可以计算s.size()-l来表示

    注意：
    窗口扩张：left不变，right++
    窗口滑动：left++, right++

    本方法２，采用int[26]存储当前窗口中各个字母的出现次数，因为题目已提到字符串中的元素都是大写的，这样的话效率会比map好
 */
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int l = 0;
        int r = 0;
        int hischarmax = 0;
        int count[26] = {0};
        for (int r = 0; r < s.size(); r++)
        {
            count[s[r] - 'A']++;
            hischarmax = max(hischarmax, count[s[r] - 'A']);
            //在这里，即使hischarmax+k　＝　滑动窗口的宽度，仍然可以试着取扩张，而不是滑动窗口
            if (r - l + 1 > hischarmax + k)
            {
                --count[s[l] - 'A'];
                l++;
            }
        }
        return s.size() - l;
    }
};