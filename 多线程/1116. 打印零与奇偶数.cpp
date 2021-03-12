/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-12 18:57:40
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-12 19:19:35
 */
#include <semaphore.h>
//信号量
class ZeroEvenOdd
{
private:
    int n;
    sem_t sem0;
    sem_t sem1;
    sem_t sem2;
    bool iseven = true;

public:
    ZeroEvenOdd(int n)
    {
        this->n = n;
        sem_init(&sem0, 0, 1);
        sem_init(&sem1, 0, 0);
        sem_init(&sem2, 0, 0);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber)
    {
        for (int i = 0; i < n; i++)
        {
            sem_wait(&sem0);
            printNumber(0);
            //cnt++;
            if (iseven)
                sem_post(&sem1);
            else
                sem_post(&sem2);
            iseven = !iseven;
        }
    }
    void odd(function<void(int)> printNumber)
    {
        for (int i = 1; i <= n; i += 2)
        {
            sem_wait(&sem1);
            printNumber(i);
            sem_post(&sem0);
        }
    }

    void even(function<void(int)> printNumber)
    {
        for (int i = 2; i <= n; i += 2)
        {
            sem_wait(&sem2);
            printNumber(i);
            sem_post(&sem0);
        }
    }
};
//互斥锁
class ZeroEvenOdd
{
private:
    int n;
    mutex muZero;
    mutex muEven;
    mutex muOdd;

    bool iseven = true;

public:
    ZeroEvenOdd(int n)
    {
        this->n = n;
        muEven.lock();
        muOdd.lock();
        muZero.unlock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber)
    {
        for (int i = 0; i < n; i++)
        {
            muZero.lock();
            printNumber(0);
            //cnt++;
            if (iseven)
                muOdd.unlock();
            else
                muEven.unlock();
            iseven = !iseven;
        }
    }
    void odd(function<void(int)> printNumber)
    {
        for (int i = 1; i <= n; i += 2)
        {
            muOdd.lock();
            printNumber(i);
            muZero.unlock();
        }
    }

    void even(function<void(int)> printNumber)
    {
        for (int i = 2; i <= n; i += 2)
        {
            muEven.lock();
            printNumber(i);
            muZero.unlock();
        }
    }
};
//原子类模板，原子操作
class ZeroEvenOdd
{
private:
    int n;
    atomic<int> ways{0};
    bool iseven = true;

public:
    ZeroEvenOdd(int n)
    {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber)
    {
        for (int i = 0; i < n; i++)
        {
            while (ways.load() != 0)
                this_thread::yield();
            printNumber(0);
            if (iseven)
                ways.store(1);
            else
                ways.store(2);
            iseven = !iseven;
        }
    }
    void odd(function<void(int)> printNumber)
    {
        for (int i = 1; i <= n; i += 2)
        {
            while (ways.load() != 1)
                this_thread::yield();
            printNumber(i);
            ways.store(0);
        }
    }

    void even(function<void(int)> printNumber)
    {
        for (int i = 2; i <= n; i += 2)
        {
            while (ways.load() != 2)
                this_thread::yield();
            printNumber(i);
            ways.store(0);
        }
    }
};
//条件变量
class ZeroEvenOdd
{
private:
    int n;
    mutex mu;
    condition_variable cond_Vari;
    bool iseven = true;
    int way = 0;

public:
    ZeroEvenOdd(int n)
    {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber)
    {
        for (int i = 0; i < n; i++)
        {
            unique_lock<mutex> lk(mu);
            cond_Vari.wait(lk, [this]() -> bool { return way == 0; });
            printNumber(0);
            if (iseven)
                way = 1;
            else
                way = 2;
            iseven = !iseven;
            cond_Vari.notify_one();
        }
    }
    void odd(function<void(int)> printNumber)
    {
        for (int i = 1; i <= n; i += 2)
        {
            unique_lock<mutex> lk(mu);
            cond_Vari.wait(lk, [this]() -> bool { return way == 1; });
            printNumber(i);
            way = 0;
            cond_Vari.notify_one();
        }
    }

    void even(function<void(int)> printNumber)
    {
        for (int i = 2; i <= n; i += 2)
        {
            unique_lock<mutex> lk(mu);
            cond_Vari.wait(lk, [this]() -> bool { return way == 2; });
            printNumber(i);
            way = 0;
            cond_Vari.notify_one();
        }
    }
};