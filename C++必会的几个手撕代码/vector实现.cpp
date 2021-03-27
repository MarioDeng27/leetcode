/*
 * @FilePath: \Sorte:\DataStructures-Algorithms\DataStructures-Algorithms\leetcode\C++必会的几个手撕代码\vector实现.cpp
 * @Brief: 
 * @Version: 1.0
 * @Date: 2021-03-24 11:10:46
 * @Author: Mario Deng
 * @Copyright: your copyright description
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-24 11:28:06
 */
#include <bits/stdc++.h>
#include <memory>
using namespace std;
template <class _Ty, class _Alloc = allocator<_Ty>>

class vector
{
    typedef T value_type;
    typedef value_type *iterator;
    typedef const value_type *const_iterator;
    typedef value_type &reference;
    typedef value_type *pointer;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type; //表示两个迭代器之间的距离 ,c++内置定义 typedef int ptrdiff_t;
    public：
        iterator
        begin() { return _Myfirst; }
    iterator end() { return _Mylast; }
    size_type size() const { return size_type(end() - begin()); }
    size_type capacity() const { return size_type(_Myend - begin()); }
    bool empty() const { return begin() == end(); }
    reference operator[](size_type n) { return *(begin() + n); }
    reference front() { return *begin(); }
    reference back() { return *(end() - 1); }
    //...
};

template <class T, class alloc = allocator<T>>
class myVector
{
public:
    typedef T valueType;
    typedef valueType *iterator;
    typedef valueType &reference;

    myVector(){};
    myVector(size_t n, valueType val){};
    myVector(size_t n){};
    iterator begin() { return _start; }
    iterator end() { return _end; }
    size_t size() { return (size_t)(_end - _start); }
    size_t capacity() { return (size_t)(_endOfStorage - _start); }

private:
    iterator _start;
    iterator _end;
    iterator _endOfStorage;
};

list<int> l;
