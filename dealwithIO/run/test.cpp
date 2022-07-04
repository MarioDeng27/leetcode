/*
 * @Description:
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-02 00:44:43
 * @LastEditors: Mario Deng
 * @LastEditTime: 2022-07-04 15:45:03
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
int partition(vector<int> &nums, int l, int r)
{
    if (l > r)
        return -1;
    int first = l, last = r, key = nums[first];
    while (first < last)
    {
        while (first < last && nums[last] >= key)
            last--;
        nums[first] = nums[last];
        while (first < last && nums[first] <= key)
            first++;
        nums[last] = nums[first];
    }
    nums[first] = key;
    return first;
}
int k;
int ans = 0;
void quicksort(vector<int> &nums, int l, int r)
{
    if (l > r)
        return;
    int p = partition(nums, l, r);
    quicksort(nums, l, r - 1);
    quicksort(nums, p + 1, r);
}
class Solution
{
public:
    vector<int> dir = {-1, 0, 1, 0, -1};
    int m, n;
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        m = grid.size(), n = m ? grid[0].size() : 0;
        int area = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    grid[i][j] = 0;
                    area = max(area, 1 + dfs(grid, i, j));
                }
            }
        }
        return area;
    }
    int dfs(vector<vector<int>> &grid, int a, int b)
    {
        if (a < 0 || a > m || b < 0 && b > n || grid[a][b] == 0)
            return 0;
        grid[a][b] = 0;
        int area = 1;
        for (int i = 0; i < 4; i++)
        {
            int x = a + dir[i];
            int y = b + dir[i + 1];
            area += dfs(grid, x, y);
        }
        return area;
    }
};
int main()
{
    //"aewfafwafjlwajflwajflwafj"
    //[ "apple", "ewaf", "awefawfwaf", "awef", "awefe", "ewafeffewafewf" ] auto v = {1, 0, 0, 0, 1};
    // auto b = Solution().findMin({1, 3, 3, 3});
    vector<int> nums1 = {2, 3, 4, 2, 2, 1};
    Solution().findKthLargest(nums1, 3);
    for (auto n : nums1)
        cout << n << " ";
    cout << "ss" << endl;
    return 0;
}