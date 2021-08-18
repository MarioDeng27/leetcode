/*
 * @FilePath: \Sorte:\DataStructures-Algorithms\DataStructures-Algorithms\leetcode\Heap\第一阶段\692. 前K个高频单词.cpp
 * @Brief: 
 * @Version: 1.0
 * @Date: 2020-11-08 15:12:20
 * @Author: Mario Deng
 * @Copyright: your copyright description
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-01-25 16:50:22
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

/*
    自己的想法，其实就是一个排序问题：返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。
    使用map将每个单词出现的次数记录下来．
    １．通过排序将单词出现最高的并且单词的首字母最前的排在最前，可以将map转化成vector<pair<string,int>>这样的类型，通过自定义排序在通过sort对vec排序
    ２．通过优先队列，使用自定义的排序规则，即第二个方法的order结构体

    注意记住怎么实现bool排序的，即怎么实现多关键词排序
*/

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        map<string, int> m;
        for (auto str : words)
            ++m[str];
        vector<pair<string, int>> vec(m.begin(), m.end());
        sort(vec.begin(), vec.end(), comp);
        vector<string> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(vec[i].first);
        }
        return res;
    }
    static bool comp(pair<string, int> &a, pair<string, int> &b)
    {
        if (a.second != b.second)
            return a.second > b.second;
        else
        {
            return a.first < b.first;
        }
    }
};

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        map<string, int> m;
        vector<string> res;
        for (auto str : words)
            ++m[str];
        priority_queue<pair<string, int>, vector<pair<string, int>>, Order> pq(m.begin(), m.end());

        for (int i = 0; i < k; i++)
        {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
    //用于排序
    static bool comp(pair<string, int> &a, pair<string, int> &b)
    {
        if (a.second != b.second)
            return a.second > b.second;
        else
        {
            return a.first < b.first;
        }
    }

    struct Order
    { //起到less的作用，如果a的优先级大于b的，返回true，形成大顶堆
        bool operator()(pair<string, int> &a, pair<string, int> &b) const
        { //a,b频数大的，优先级大，频数相等，字典序小的优先级大.
            if (a.second != b.second)
                return a.second < b.second;
            else
            {
                return a.first > b.first;
            }
        }
    };
};