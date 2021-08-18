/*
 * @FilePath: \Sorte:\DataStructures-Algorithms\DataStructures-Algorithms\leetcode\Stack\第二阶段\155. 最小栈.cpp
 * @Brief: 
 * @Version: 1.0
 * @Date: 2020-11-14 21:06:25
 * @Author: Mario Deng
 * @Copyright: your copyright description
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-01-28 01:45:40
 */

class MinStack
{
public:
    /** initialize your data structure here. */
    vector<int> vec;
    vector<int> min_vec;
    MinStack()
    {
        min_vec.push_back(INT_MAX);
    }

    void push(int x)
    {
        vec.push_back(x);
        min_vec.push_back(min(min_vec.back(), x));
    }

    void pop()
    {
        vec.pop_back();
        min_vec.pop_back();
    }

    int top()
    {
        return vec.back();
    }

    int getMin()
    {
        return min_vec.back();
    }
};

class MinStack
{
public:
    /** initialize your data structure here. */
    stack<int> stval;
    stack<int> stmin;
    MinStack()
    {
        stmin.push(INT_MAX);
    }

    void push(int x)
    {
        //保证在每个不同的栈顶元素有不同的栈元素最小值
        stval.push(x);
        //如果stmin.top()>x,则表示，当前x是整个栈中的最小值，若反之，则表示，之前前一个的stmin的top才是当前最小值
        stmin.push(min(stmin.top(), x));
    }

    void pop()
    {
        stval.pop();
        stmin.pop();
    }

    int top()
    {
        return stval.top();
    }

    int getMin()
    {
        return stmin.top();
    }
};