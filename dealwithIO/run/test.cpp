/*
 * @Description:
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2022-07-12 13:54:48
 * @LastEditors: Mario Deng
 * @LastEditTime: 2022-07-14 12:08:29
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
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        int pre1 = nums[0];
        int pre2 = 0;
        int cur = pre1;
        for (int i = 2; i <= n; i++)
        {
            cur = max(pre1, pre2 + nums[i - 1]);
            pre2 = pre1;
            pre1 = cur;
        }
        return cur;
    }
};
void show(vector<vector<char>> &vec)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<vector<char>> vec = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    show(vec);
    Solution()
        .solveSudoku(vec);
    cout << "----------------------------" << endl;
    show(vec);
    // cout << "ss" << endl;
    return 0;
}