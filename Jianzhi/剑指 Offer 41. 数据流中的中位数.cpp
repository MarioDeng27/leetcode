/*
 * @FilePath: \Sorte:\DataStructures-Algorithms\DataStructures-Algorithms\leetcode\Jianzhi\剑指 Offer 41. 数据流中的中位数.cpp
 * @Brief: 
 * @Version: 1.0
 * @Date: 2021-04-10 19:47:34
 * @Author: Mario Deng
 * @Copyright: your copyright description
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-04-10 19:47:36
 */
class MedianFinder
{
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, less<int>> smaller;
    priority_queue<int, vector<int>, greater<int>> bigger;
    int size = 0;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (size % 2 == 0)
        {
            bigger.push(num);
            int val = bigger.top();
            bigger.pop();
            smaller.push(val);
        }
        else
        {
            smaller.push(num);
            int val = smaller.top();
            smaller.pop();
            bigger.push(val);
        }
        size++;
    }

    double findMedian()
    {
        if (size % 2 == 1)
        {
            return smaller.top() * 1.0;
        }
        else
        {
            return (smaller.top() + bigger.top()) * 1.0 / 2;
        }
    }
};