/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-09 18:03:13
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-09 18:37:08
 */
#include <algorithm>
#include <atomic>
#include <cmath>
#include <condition_variable>
#include <cstring>
#include <functional>
#include <iostream>
#include <mutex>
#include <pthread.h> // pthread_create(), pthread_join()
#include <queue>
#include <semaphore.h> // sem_init()
#include <stdlib.h>    //rand()，srand()函数在这个头文件中
#include <thread>
#include <time.h> //time(0)在这个头文件中
#include <unordered_set>
#include <vector>
using namespace std;
//信号量实现，信号量能决定线程之间执行的相对顺序，它的计数值可以大于1
class FooBar
{
private:
    int n;

protected:
    sem_t fooJobDone;
    sem_t barJobDone;

public:
    FooBar(int n)
    {
        this->n = n;
        sem_init(&fooJobDone, 0, 1);
        sem_init(&barJobDone, 0, 0);
    }

    void foo(function<void()> printFoo)
    {

        for (int i = 0; i < n; i++)
        {
            sem_wait(&fooJobDone);
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            sem_post(&barJobDone);
        }
    }

    void bar(function<void()> printBar)
    {

        for (int i = 0; i < n; i++)
        {
            sem_wait(&barJobDone);
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            sem_post(&fooJobDone);
        }
    }
};
//利用C++11里的mutex互斥量（锁）来实现（和信号量类似，暂时可以把它当作一个值为1的信号量），在一个线程里里一个锁mutex1.lock()之后，别的线程想再次把这个锁给锁上在执行后面的语句
//这个是不能实现的。包括自己当前这个线程想不在unlock之后再lock一次也是不可能的。只有当unlock之后才能lock，所以是互斥的
class FooBar
{
private:
    int n;

protected:
    mutex fooJobDone;
    mutex barJobDone;

public:
    FooBar(int n)
    {
        this->n = n;
        fooJobDone.unlock();
        barJobDone.lock();
    }

    void foo(function<void()> printFoo)
    {

        for (int i = 0; i < n; i++)
        {
            fooJobDone.lock();
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            barJobDone.unlock();
        }
    }

    void bar(function<void()> printBar)
    {

        for (int i = 0; i < n; i++)
        {
            barJobDone.lock();
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            fooJobDone.unlock();
        }
    }
};

/*使用原子类模板来实现
原子类模板：
https://www.cnblogs.com/cy1993/p/11498768.html
https://blog.csdn.net/K346K346/article/details/85345477
利用load函数读取数据和store函数写数据都是原子操作，普通变量对数据进行读写，编译成汇编语句要分三个步骤，从栈中读取数据到内存，内存中修改值，再写入内存中。不是原子操作
任何一个步骤都可能因为随着CPU时间片到期被中断，反而去执行其他线程中的某一个操作

this_thread::yield():
https://blog.csdn.net/u014673282/article/details/89209405
yield()函数的目的是，不要让CPU控制权一直在放在当前线程当中，而是要把这个控制权交出去，让其他线程去运行
*/
class FooBar
{
private:
    int n;

protected:
    atomic<bool> fooed{false};

public:
    FooBar(int n)
    {
        this->n = n;
    }

    void foo(function<void()> printFoo)
    {

        for (int i = 0; i < n; i++)
        {
            while (fooed.load())
            {
                this_thread::yield();
            }
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            fooed.store(true);
        }
    }

    void bar(function<void()> printBar)
    {

        for (int i = 0; i < n; i++)
        {
            while (!fooed.load())
            {
                this_thread::yield();
            }
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            fooed.store(false);
        }
    }
};
/*
    条件变量condition_variable 类型，它调用wait类型的成员函数 会让unique_lock<mutex>模板类去来锁住当前线程，使其阻塞直到发生的条件满足为止
    注意发生的条件应该要使用一个可调用对象来充当参数的，可调用对象里必须有对this的访问权，所以用lambda表达式是最好的。

    condVariable.notify_one(); 若任何线程在*this上进行等待，则调用 notify_one 会解阻塞(唤醒)等待线程之一

    condVariable.notify_all(); 若任何线程在 *this 上等待，则解阻塞（唤醒)全部等待线程。
*/
class FooBar
{
private:
    int n;
    mutex mu;
    int count = 1;
    condition_variable condVariable;

public:
    FooBar(int n)
    {
        this->n = n;
    }

    void foo(function<void()> printFoo)
    {

        for (int i = 0; i < n; i++)
        {
            unique_lock<mutex> lk(mu);
            condVariable.wait(lk, [this]() { return count == 1; });
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            count++;
            condVariable.notify_one();
        }
    }

    void bar(function<void()> printBar)
    {

        for (int i = 0; i < n; i++)
        {
            unique_lock<mutex> lk(mu);
            condVariable.wait(lk, [this]() { return count == 2; });
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            count--;
            condVariable.notify_one();
        }
    }
};