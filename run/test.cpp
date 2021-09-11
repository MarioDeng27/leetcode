/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-02 00:44:43
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-09-09 22:27:29
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
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int cur = 0;
        int i = 0;
        while (i < n)
        {
            int maxval = -1;
            int temp = i;
            if (i + nums[i] >= n - 1)
                return true;
            int I = i + nums[i];
            for (int j = i + 1; j <= I; j++)
            {
                if (nums[j] + j >= n - 1)
                    return true;
                if (j < n && nums[j] + j > maxval)
                {
                    maxval = nums[j] + j;
                    i = j;
                }
            }
            if (temp == i)
                break;
        }
        return i >= n - 1;
    }
};
int main()
{
    vector<int> t = {3, 0, 8, 2, 0, 0, 1};
    cout << Solution().canJump(t);
    return 0;
}
