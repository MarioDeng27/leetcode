#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

/*
    自己的想法，循环将其中一个队列的元素导入另一个元素来模拟出栈
*/

class MyStack
{
public:
    /** Initialize your data structure here. */
    queue<int> q1;
    queue<int> q2;
    bool flag = true; //true表示当前存储数据的是ｑ1
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        if (flag)
            q1.push(x);
        else
            q2.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int temp;
        if (flag)
        {

            while (!q1.empty())
            {
                temp = q1.front();
                q1.pop();
                if (q1.empty())
                    break;
                q2.push(temp);
            }
        }
        else
        {
            while (!q2.empty())
            {
                temp = q2.front();
                q2.pop();
                if (q2.empty())
                    break;
                q1.push(temp);
            }
        }
        flag = !flag;
        return temp;
    }

    int top()
    {
        int temp;
        if (flag)
        {

            while (!q1.empty())
            {
                temp = q1.front();
                q1.pop();
                q2.push(temp);
            }
        }
        else
        {
            while (!q2.empty())
            {
                temp = q2.front();
                q2.pop();
                q1.push(temp);
            }
        }
        flag = !flag;
        return temp;
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return q1.empty() && q2.empty();
    }
};

//第一次优化后
class MyStack
{
public:
    /** Initialize your data structure here. */
    queue<int> q1;
    queue<int> q2;
    //bool flag = true; //true表示当前存储数据的是ｑ1
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        q1.push(x);
    }
    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int result = q1.back();
        int size = q1.size();
        size--;
        while (size--)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1 = q2;
        while (!q2.empty())
        {
            q2.pop();
        }
        return result;
    }

    int top()
    {
        return q1.back();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return q1.empty();
    }
};

//第二次优化后,用一个队列，将队列的头弹出继续放到队列中的尾部
class MyStack
{
public:
    queue<int> que;
    /** Initialize your data structure here. */
    MyStack()
    {
    }
    /** Push element x onto stack. */
    void push(int x)
    {
        que.push(x);
    }
    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int size = que.size();
        size--;
        while (size--)
        { // 将队列头部的元素（除了最后一个元素外） 重新添加到队列尾部
            que.push(que.front());
            que.pop();
        }
        int result = que.front(); // 此时弹出的元素顺序就是栈的顺序了
        que.pop();
        return result;
    }

    /** Get the top element. */
    int top()
    {
        return que.back();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return que.empty();
    }
};
