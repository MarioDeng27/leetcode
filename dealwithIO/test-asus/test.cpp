/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-02 00:44:43
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-12-16 20:31:44
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

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        int res = 0;
        int l = 0;
        int r = n - 1;
        while (l < r)
        {
            int index = r;
            if (height[l] < height[r])
            {
                index = l;
            }
            res = max(res, height[index] * (r - l));
            if (index == l)
                l++;
            else
                r--;
        }
        return res;
    }
};
class function_wrapper
{
    struct impl_base
    {
        virtual void call() = 0;
        virtual ~impl_base() {}
    };
    std::unique_ptr<impl_base> impl;
    template <typename F>
    struct impl_type : impl_base
    {
        F f;
        impl_type(F &&f_) : f(std::move(f_)) {}
        void call() { f(); }
    };

public:
    template <typename F>
    function_wrapper(F &&f) : impl(new impl_type<F>(std::move(f))){};
    void operator()() { impl->call(); }
    function_wrapper() = default;
    function_wrapper(function_wrapper &&other) : impl(std::move(other.impl)){};
    function_wrapper &operator=(function_wrapper &&other)
    {
        impl = std::move(other.impl);
        return *this;
    }
    function_wrapper(const function_wrapper &) = delete;
    function_wrapper(function_wrapper &) = delete;
    function_wrapper &operator=(const function_wrapper &) = delete;
};
class Point
{
public:
    Point(int _x, int _y) : x(_x), y(_y){};
    int x;
    int y;
};
class MessagerImp;
class Messager
{
protected:
    MessagerImp *messagerImp; //...
public:
    virtual void Login(string username, string password) = 0;
    virtual void SendMessage(string message) = 0;
    virtual void SendPicture(int image) = 0;
    Messager(MessagerImp *messagerImp) : messagerImp(messagerImp) {}
    virtual ~Messager() {}
};

class MessagerImp
{
public:
    virtual void PlaySound() = 0;
    virtual void DrawShape() = 0;
    virtual void WriteText() = 0;
    virtual void Connect() = 0;

    virtual ~MessagerImp() {}
};

//平台实现 n
class PCMessagerImp : public MessagerImp
{
public:
    virtual void PlaySound()
    {
        //**********
        cout << "PCMessagerImp "
             << "PlaySound()" << endl;
    }
    virtual void DrawShape()
    {
        //**********
        cout << "PCMessagerImp "
             << "DrawShape()" << endl;
    }
    virtual void WriteText()
    {
        //**********
        cout << "PCMessagerImp "
             << "WriteText()" << endl;
    }
    virtual void Connect()
    {
        //**********
        cout << "PCMessagerImp "
             << "Connect()" << endl;
    }
};

class MobileMessagerImp : public MessagerImp
{
public:
    virtual void PlaySound()
    {
        //==========
        cout << "MobileMessagerImp "
             << "PlaySound()" << endl;
    }
    virtual void DrawShape()
    {
        //==========
        cout << "MobileMessagerImp "
             << "DrawShape()" << endl;
    }
    virtual void WriteText()
    {
        //==========
        cout << "MobileMessagerImp "
             << "WriteText()" << endl;
    }
    virtual void Connect()
    {
        //==========
        cout << "MobileMessagerImp "
             << "Connect()" << endl;
    }
};

//业务抽象 m

//类的数目：1+n+m

class MessagerLite : public Messager
{

public:
    MessagerLite(MessagerImp *_messagerImp) : Messager(_messagerImp) {}
    virtual void Login(string username, string password)
    {
        cout << "On MessagerLite ";
        messagerImp->Connect();
        //........
    }
    virtual void SendMessage(string message)
    {
        cout << "On MessagerLite ";
        messagerImp->WriteText();
        //........
    }
    virtual void SendPicture(int image)
    {
        cout << "On MessagerLite ";
        messagerImp->DrawShape();
        //........
    }
};

class MessagerPerfect : public Messager
{

public:
    MessagerPerfect(MessagerImp *_messagerImp) : Messager(_messagerImp) {}
    virtual void Login(string username, string password)
    {
        cout << "On MessagerPerfect ";
        messagerImp->PlaySound();
        //********
        messagerImp->Connect();
        //........
    }
    virtual void SendMessage(string message)
    {
        cout << "On MessagerPerfect ";
        messagerImp->PlaySound();
        //********
        messagerImp->WriteText();
        //........
    }
    virtual void SendPicture(int image)
    {
        cout << "On MessagerPerfect ";
        messagerImp->PlaySound();
        //********
        messagerImp->DrawShape();
        //........
    }
};

void Process()
{
    //运行时装配
    MessagerImp *mImp = new PCMessagerImp();
    MessagerImp *mImp2 = new MobileMessagerImp();
    Messager *m = new MessagerPerfect(mImp);
    Messager *n = new MessagerLite(mImp2);
    m->Login("a", "b");
    n->Login("3", "2");
    //m->SendMessage("a");
    //m->SendPicture(1);
}

int main()
{
    Process();
    return 0;
}
