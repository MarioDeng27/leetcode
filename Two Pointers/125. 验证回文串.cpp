#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>
//#include <multimap>
#include <array>
#include <cctype>
#include <cmath>
using namespace std;
/*
    c++或c#中要求引用 #include <cctype>
    isalpha()用来判断一个字符是否为字母，如果是字符则返回非零，否则返回零。
    isalnum()用来判断一个字符是否为数字或者字母，也就是说判断一个字符是否属于a~z||A~Z||0~9
    islower()用来判断一个字符是否为小写字母，也就是是否属于a~z。
    isupper()和islower相反，用来判断一个字符是否为大写字母。
    tolower()函数是把字符串都转化为小写字母
    toupper()函数是把字符串都转化为小写字母
    判断标点符号 ispunct()
    判断空格 isspace()
    判断数字函数 isdigit()
    判断字母函数 isalpha()
*/

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string str = "";
        for (auto c : s)
        {
            if (isalnum(c))
                str += c;
        }
        if (str.size() == 0 || str.size() == 1)
            return true;
        int L = 0;
        int R = str.size() - 1;
        while (L < R)
        {
            if (tolower(str[L]) == tolower(str[R]))
            {
                L++;
                R--;
            }
            else
                return false;
        }
        return true;
    }
};

/*
    验证是否是回文字符串，只要把原先的串颠倒过来与原字符串相比较，如果相等则是回文，反之~
*/
class Solution
{
public:
    bool isPalindrome(string s)
    {
        string str = "";
        for (auto c : s)
        {
            if (isalnum(c))
                str += tolower(c);
        }
        if (str.size() == 0 || str.size() == 1)
            return true;
        string str1(str.rbegin(), str.rend());
        if (str == str1)
            return true;
        return false;
    }
};