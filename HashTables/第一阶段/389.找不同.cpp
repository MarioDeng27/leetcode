#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
using namespace std;
//自己的想法
class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        map<char, int> m;
        for (auto i : s)
            ++m[i];
        for (auto i : t)
            ++m[i];
        for (auto i : m)
        {
            if (i.second % 2 == 1)
                return i.first;
        }
        return;
    }
};
//自己的想法
class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != t[i])
                return t[i];
        }
        return t[t.size() - 1];
    }
};
/*
    异或运算的特性：
    异或自己得0，任何数异或0得自己本身；
    具有交换律、结合律，例如 1^2^3^4^2^3^1 = (1^1)^(2^2)^(3^3)^4 = 0^0^0^4 = 0^4 = 4;
    总结：异或运算擅长找不同。
*/
class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        char c = 0;
        for (auto i : s)
            c ^= i;
        for (auto i : t)
            c ^= i;

        return c;
    }
};