/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-23 22:45:49
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-23 22:52:17
 */
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

mutex m1;
mutex m2;
void a()
{
    m1.lock();
    sleep(1);
    m2.lock();
    cout << "a";
}

void b()
{
    m2.lock();
    sleep(1);
    m1.lock();
    cout << "b";
}
int main()
{
    thread t1(a);
    thread t2(b);
    t1.join();
    t2.join();
    return 0;
}