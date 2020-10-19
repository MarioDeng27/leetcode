#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <sstream>
using namespace std;
/* 
    小顶堆实现：
    具体想法就是，只要每次能找到一个容器中最小元素值，然后把它从容器中删除，一直删除到只剩Ｋ个元素，这样 返回的最小值也就是容器中第Ｋ大元素 小顶堆的话也是优先队列，用pop() 将会返回队头元素也就是最小值 关于优先队列的知识可以参考： 升序队列，小顶堆 priority_queue<int, vector<int>, greater<int>> q;
    降序队列，大顶堆
    priority_queue<int, vector<int>, less<int>> q;
    greater和less是std实现的两个仿函数
    （就是使一个类的使用看上去像一个函数。其实现就是类中实现一个operator() ，这个类就有了类似函数的行为，就是一个仿函数类了）
*/
class KthLargest
{
    int K;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    KthLargest(int k, vector<int> &nums)
    {
        for (int n : nums)
        {
            pq.push(n);
            if (pq.size() > k)
                pq.pop();
        }
        K = k;
    }

    int add(int val)
    {
        pq.push(val);
        if (pq.size() > K)
            pq.pop();
        return pq.top();
    }
};

//也可以用multset这个容器，本身自动排序的特点找到一个容器中最小元素值，即．begin()
class KthLargest
{
    int K;
    multiset<int> st;

public:
    KthLargest(int k, vector<int> &nums)
    {
        for (int n : nums)
        {
            st.insert(n);
            if (st.size() > k)
                st.erase(st.begin());
        }
        K = k;
    }

    int add(int val)
    {
        st.insert(val);
        if (st.size() > K)
            st.erase(st.begin());
        return *st.begin();
    }
};
