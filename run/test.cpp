/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-02 00:44:43
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-21 14:55:28
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

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        map<char, int> need;
        map<char, int> windows;
        for (auto chr : s1)
            need[chr]++;
        int left = 0;
        int right = 0;
        int valid = 0;

        while (right < s2.size())
        {
            char chr = s2[right];
            right++;
            if (need.count(chr) > 0)
            {
                windows[chr]++;
                if (windows[chr] == need[chr])
                    valid++;
            }
            while (right - left >= s1.size())
            {
                if (valid == need.size())
                    return true;
                char tmp = s2[left];
                left++;
                if (need.count(tmp) > 0)
                {
                    if (windows[tmp] == need[tmp])
                        valid--;
                    windows[tmp]--;
                }
            }
        }
        return false;
    }
};

int main()
{

    cout << "1" << endl;
    return 0;
}
