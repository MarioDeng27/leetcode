/*
 * @FilePath: \Sorte:\DataStructures-Algorithms\DataStructures-Algorithms\leetcode\经常手撕的代码\146. LRU 缓存机制.cpp
 * @Brief: 
 * @Version: 1.0
 * @Date: 2021-03-09 22:53:55
 * @Author: Mario Deng
 * @Copyright: your copyright description
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-09 22:59:27
 */

//错误版本，使用了map<int,list::iter> 和 list<int>
//仅仅是map<int,list::iter> 和 list<int>（list就放value）会导致，当发生容量满了，要删除链表中最后一个元素的时候，链表是可以删了，但是map那边不好删，因为你只能知道一个value值或者是指向value的迭代器
//而map是不支持通过value值删除的，要么通过自身的map自身的迭代器删除，要么就是通过key值删除
class LRUCache
{
public:
    list<int> listCache;
    map<int, list<int>::iterator> mp;
    int cap;
    LRUCache(int capacity)
    {
        cap = capacity;
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
            return -1;
        int val = *mp[key];
        listCache.erase(mp[key]);
        listCache.push_front(val);
        //这一步很关键，相当于更新了哈希表里的value值，不然还是用之前的那个迭代器肯定有问题
        mp[key] = listCache.begin();
        return val;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
            listCache.erase(mp[key]);
        else
        {
            if (cap == listCache.size())
            {
                mp.erase(listCache.back());
                listCache.pop_back();
            }
        }
        listCache.push_front(value);
        mp[key] = listCache.begin();
    }
};
//正确使用STL里的List类模板来实现LRU算法
class LRUCache
{
public:
    list<pair<int, int>> listCache;
    map<int, list<pair<int, int>>::iterator> mp;
    int cap;
    LRUCache(int capacity)
    {
        cap = capacity;
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
            return -1;
        pair<int, int> p = *mp[key];
        listCache.erase(mp[key]);
        listCache.push_front(p);
        //这一步很关键，相当于更新了哈希表里的value值，不然还是用之前的那个迭代器肯定有问题
        mp[key] = listCache.begin();
        return p.second;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
            listCache.erase(mp[key]);
        else
        {
            if (cap == listCache.size())
            {
                //找到链表最后一个节点的key，通过它删除map中对应的记录
                mp.erase(listCache.back().first);
                listCache.pop_back();
            }
        }
        //不过之前list里面到底是有对应记录好，还是没记录好，反之就是返回最新的这对记录
        listCache.push_front({key, value});
        //更新map记录
        mp[key] = listCache.begin();
    }
};