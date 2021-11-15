/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-02 00:44:43
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-11-15 20:26:16
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
void submit(T f)
{
    cout << typeid(T).name() << endl;
    function<void(int)> func(f);
    func(1);
}

void myfunc()
{
    cout << "no para" << endl;
}
void myfunc1(int i)
{
    cout << "have a para" << endl;
}

void delay(double sec)
{
    time_t start_time, cur_time; // 变量声明
    time(&start_time);
    do
    {
        time(&cur_time);
    } while ((cur_time - start_time) < sec);
};

void show(int n)
{
    cout << "n=" << n << endl;
}
thread returnThread()
{
    thread tt(show, 10);
    return tt;
}
#include <ctime>
#include <iostream>
#include <thread>
using namespace std;
void delay(double sec)
{
    time_t start_time, cur_time; // 变量声明
    time(&start_time);
    do
    {
        time(&cur_time);
    } while ((cur_time - start_time) < sec);
};

void show(int n)
{
    cout << "n=" << n << endl;
}
thread returnThread()
{
    thread tt(show, 10);
    return tt;
}
class Solution
{
public:
    int bulbSwitch(int n)
    {
        vector<bool> arr(n, true);
        for (int i = 2; i <= n; i++)
        {
            // for (int j = 1; j <= n; j++)
            // {
            //     if (j % i == 0)
            //     {
            //         arr[j] = !arr[j];
            //     }
            // }
            for (int j = i; j <= n; j += i)
            {
                arr[j] = !arr[j];
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i])
                cnt++;
        }
        return cnt;
    }
};
int main()
{

    thread t(show, 18);
    cout << "t is joinable? " << t.joinable() << endl;

    thread t1(returnThread());
    cout << "t1 is joinable? " << t1.joinable() << endl;

    thread t2(show, 3);
    cout << "t2 is joinable? " << t2.joinable() << endl;
    t2.join();
    cout << "after t2.join(),t2 is joinable? " << t2.joinable() << endl;

    thread t3(show, 5);
    cout << "t3 is joinable? " << t3.joinable() << endl;
    t3.detach();
    cout << "after t3.detach(),t3 is joinable? " << t3.joinable() << endl;
}
int main()
{

    thread t(show, 18);
    cout << "t is joinable? " << t.joinable() << endl;

    thread t1(returnThread());
    cout << "t1 is joinable? " << t1.joinable() << endl;

    thread t2(show, 3);
    cout << "t2 is joinable? " << t2.joinable() << endl;
    t2.join();
    cout << "after t2.join(),t2 is joinable? " << t2.joinable() << endl;

    thread t3(show, 5);
    cout << "t3 is joinable? " << t3.joinable() << endl;
    t3.detach();
    cout << "after t3.detach(),t3 is joinable? " << t3.joinable() << endl;
}