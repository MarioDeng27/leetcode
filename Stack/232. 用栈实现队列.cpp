#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <unordered_map>
#include <stack>
using namespace std;

class MyQueue
{
public:
    /** Initialize your data structure here. */
    stack<int> stin;
    stack<int> stout;
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        stin.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        int x = peek();
        stout.pop();
        return x;
    }

    /** Get the front element. */
    int peek()
    {
        if (stout.empty())
        {
            while (!stin.empty())
            {
                stout.push(stin.top());
                stin.pop();
            }
        }
        int x = stout.top();
        return x;
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return stin.empty() && stout.empty();
    }
};