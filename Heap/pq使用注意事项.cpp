/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-30 17:17:45
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-30 17:19:33
 */
/* https://blog.csdn.net/weixin_40736096/article/details/79711180?utm_medium=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromMachineLearnPai2-1.channel_param&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-BlogCommendFromMachineLearnPai2-1.channel_param
两个函数的头文件是<functional>

建堆的时候，默认是大根堆，第三个参数用greater<T>会变成小根堆；

排序的时候，默认是从小到大，但是第三个参数用greater<T>会变成从大到小

另外说一句，make_heap等heap操作函数在头文件<algorithm>里。

注意：　less 是前者小于后者，即实现从小到大排序，但是在创建优先队列时会变成大顶堆 */
template <class _Ty = void>
struct less
{ // functor for operator<
    typedef _Ty first_argument_type;
    typedef _Ty second_argument_type;
    typedef bool result_type;

    constexpr bool operator()(const _Ty &_Left, const _Ty &_Right) const
    { // apply operator< to operands
        return (_Left < _Right);
    }
};
//注意：　greater 是前者大于后者（前者优先级别大于后者），即实现从大到小排序，但是在创建优先队列时会变成小顶堆 template <class _Ty = void>
struct greater
{ // functor for operator>
    typedef _Ty first_argument_type;
    typedef _Ty second_argument_type;
    typedef bool result_type;

    constexpr bool operator()(const _Ty &_Left, const _Ty &_Right) const
    { // apply operator> to operands
        return (_Left > _Right);
    }
};

//总之：大顶堆和小顶堆的实现的比较方式和排序的比较方式相反，不管是单关键词排序还是多关键词排序

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
    { //起到less（左边的数字的优先级小，在形成compair的static函数或者struct Oder）的作用，如果a的小于b的，返回true，形成大顶堆
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
