/*
 * @FilePath: \Sort\demo1.cpp
 * @Brief: 
 * @Version: 1.0
 * @Date: 2021-03-20 22:06:43
 * @Author: Mario Deng
 * @Copyright: your copyright description
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-27 21:16:50
 */
#include <algorithm>
#include <array>
#include <atomic>
#include <cctype>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <iostream>
#include <list>
#include <map>
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
/*
#include <bits/stdc++.h>
using namespace std;
*/
int getAns(int a, int b, int c)
{
    return 0;
}

int main()
{
    /*     int n, m;
    while (cin >> n >> m)
    {
        int a;
        cin >> a;
    } */
    /* //矩阵的输入
    int n, m;
    while (cin >> n >> m)
    {
        vector<vector<int>> A;
        while (n--)
        {
            vector<int> nums;
            int t = m;
            while (t--)
            {
                int a;
                cin >> a;
                nums.push_back(a);
            }
            A.push_back(nums);
        }
        cout << getAns(A) << endl;
    }
    return 0; */

    int n, m;
    while (cin >> n >> m)
    {
        vector<vector<int>> A(n, (vector<int>(m)));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> A[i][j];
            }
        }
    }
}
/*输出几位小数
printf("%.2lf%%\n", result);
*/
/* //矩阵的输入
    int n, m;
    while (cin >> n >> m)
    {
        vector<vector<int>> A;
        while (n--)
        {
            vector<int> nums;
            int t = m;
            while (t--)
            {
                int a;
                cin >> a;
                nums.push_back(a);
            }
            A.push_back(nums);
        }
        cout << getAns(A) << endl;
    }
    return 0; */

/*
矩阵的输入
    int n, m;
    while (cin >> n >> m)
    {
        vector<vector<int>> A(n, (vector<int>(m)));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> A[i][j];
            }
        }
        cout << getAns(A);
    }
*/
