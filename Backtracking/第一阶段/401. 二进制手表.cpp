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

//回溯算法
/*
模板:
result[]
def backtrack(路径,选择列表):
    if 满足结束条件:
        result.add(路径)
        return

    for 选择 in 选择列表:
        做选择
        backtrack(路径,选择列表)
        撤销选择
*/

/*
    自己的想法：
    总共10个LED,分别编号为　{0,1,2,3,4,5,6,7,8,9}
                对应的值为{1, 2, 4, 8, 16, 32, 1, 2, 4, 8},前５包含５是属于分钟的
    题目指定LED亮着的个数num，则就是从10中选num个，这是就可以用回溯法，backtrack就是本题追溯法的实现：
    返回pos表示　符合题意的集合（是值的下标的集合），然后经过双重循环，计算每个集合对应的时间字符串，将不符合题意的删除
*/
class Solution
{
public:
    vector<vector<int>> pos;
    int num = 0;
    void backtrack(int start, int cnt, vector<int> track)
    {
        if (cnt == num)
        {
            pos.push_back(track);
            return;
        }
        for (int i = start; i < 10; i++)
        {
            track.push_back(i);
            cnt++;
            backtrack(i + 1, cnt, track);
            track.pop_back();
            cnt--;
        }
    }
    vector<string> readBinaryWatch(int num)
    {
        vector<int> value = {1, 2, 4, 8, 16, 32, 1, 2, 4, 8};
        int p = 5;
        this->num = num;
        int h = 0;
        int m = 0;
        string temp;
        vector<string> res;
        backtrack(0, 0, {});
        for (auto v : pos)
        {
            for (auto i : v)
            {
                if (i <= p)
                {
                    m += value[i];
                }
                else
                {
                    h += value[i];
                }
            }
            if (h < 12 && m < 10)
            {
                temp = to_string(h) + ":0" + to_string(m);
                res.push_back(temp);
            }
            if (h < 12 && m >= 10 && m < 60)
            {
                temp = to_string(h) + ":" + to_string(m);
                res.push_back(temp);
            }
            h = 0;
            m = 0;
            temp = "";
        }
        //sort(res.begin(),res.end(),comp);
        return res;
    }
    static bool comp(string a, string b)
    {
        if (a.size() != b.size())
        {
            return a.size() < b.size();
        }
        else
        {
            return a < b;
        }
    }
};

//其他解法

class Solution
{
public:
    vector<string> readBinaryWatch(int num)
    {
        vector<string> res;
        //直接遍历  0:00 -> 12:00   每个时间有多少1
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 60; j++)
            {
                if (count1(i) + count1(j) == num)
                {
                    res.push_back(to_string(i) + ":" +
                                  (j < 10 ? "0" + to_string(j) : to_string(j)));
                }
            }
        }
        return res;
    }
    //计算二进制中1的个数
    int count1(int n)
    {
        int res = 0;
        while (n != 0)
        {
            n = n & (n - 1);
            res++;
        }
        return res;
    }
};