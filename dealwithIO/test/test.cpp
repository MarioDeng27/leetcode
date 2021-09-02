/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-02 00:44:43
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-09-02 16:35:08
 */
/*
 * @FilePath: \Sort\test.cpp
 * @Brief: 
 * @Version: 1.0
 * @Date: 2020-10-05 22:41:14
 * @Author: Mario Deng
 * @Copyright: your copyright description
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-07-02 00:37:48
 */
#include <algorithm>
#include <array>
#include <atomic>
#include <bits/stdc++.h>
#include <cctype>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <pthread.h> // pthread_create(), pthread_join()
#include <queue>
#include <semaphore.h> // sem_init()
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <vector>
using namespace std;

/* #include <bits/stdc++.h>
using namespace std; */

void func(vector<vector<int>> &A)
{
    int R = A.size();
    int C = A[0].size();
    vector<vector<int>> B(R, vector<int>(C));
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            B[j][R - 1 - i] = A[i][j];
        }
    }
    A = B;
}
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

template <typename T>
struct TypeTraits
{
    static const int data_type = 0; //这里的static非常关键
};

template <>
struct TypeTraits<char>
{
    static const int data_type = 1;
};

template <>
struct TypeTraits<int>
{
    static const int data_type = 1;
};

template <>
struct TypeTraits<float>
{
    static const int data_type = 2;
};

template <>
struct TypeTraits<double>
{
    static const int data_type = 2;
};

//没有偏特化为1或2的情况走下面的operator
template <int data_type>
class TypeGroup
{
public:
    template <typename T>
    string operator()(T &t)
    {
        cout << "default: " << t << endl;
        return "0";
    }
};

//char 或者 int 走下面的code
template <>
class TypeGroup<1>
{
public:
    template <typename T>
    string operator()(T &t)
    {
        cout << "int/char: " << (int)t << endl;
        return "1";
    }
};

//double走下面的code
template <>
class TypeGroup<2>
{
public:
    template <typename T>
    string operator()(T &t)
    {
        cout << "double: " << setprecision(2) << t << endl;
        return "2";
    }
};

template <typename T>
class Test
{
public:
    void operator()(T t)
    {
        TypeGroup<TypeTraits<T>::data_type> test;
        test(t);
    }
};

int main()
{

    TypeTraits<int> a;
    cout << a.data_type << endl;
    TypeTraits<double> b;
    cout << b.data_type << endl;
    TypeTraits<string> c;
    cout << c.data_type << endl;

    Test<char> d;
    d(10);
    Test<double> e;
    e(3.1415);
    Test<string> f;
    f("hello world!");

    return 0;
}