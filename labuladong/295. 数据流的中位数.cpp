/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-10 21:03:17
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-10 21:03:18
 */
class MedianFinder
{
public:
    /** initialize your data structure here. */

    //small是大顶堆，large是小顶堆，large的数量要么等于small，要么比small的数量多一个
    priority_queue<int, vector<int>, less<int>> small;
    priority_queue<int, vector<int>, greater<int>> large;

    MedianFinder()
    {
    }

    void addNum(int num)
    {
        //往large里添加元素
        if (small.size() == large.size())
        {
            small.push(num);
            large.push(small.top());
            small.pop();
        }
        else
        {
            large.push(num);
            small.push(large.top());
            large.pop();
        }
    }

    double findMedian()
    {
        int size = small.size() + large.size();
        //偶数情况
        if (size % 2 == 0)
            return (small.top() + large.top()) * 1.0 / 2.0;
        else
            return large.top();
    }
};